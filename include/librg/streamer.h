// Copyright ReGuider Team, 2016-2017
//
#ifndef librg_streamer_h
#define librg_streamer_h

#include <vectorial/vectorial.h>

#include <librg/entities.h>
#include <librg/utils/aabb.h>
#include <librg/components/streamable.h>

namespace librg
{
    void streamer_initialize();
    void streamer_terminate();

    namespace streamer
    {
        constexpr int MAX_NODES = 4;
        using namespace vectorial;

        struct qtree_t {
            qtree_t() {}
            qtree_t(aabb_t boundary) : boundary(boundary),
                                       entities(),
                                       blacklistedEntities(),
                                       trees() {}

            void subdivide();
            void create_child(aabb_t boundary);
            bool insert(entity_t entity);
            bool remove(entity_t entity);
            void clear();
            void query(std::vector<entity_t> &visible, aabb_t range, ComponentHandle<streamable_t> streamable, entity_t caller);

            aabb_t boundary;
            std::vector<entity_t> entities;
            std::vector<entity_t> blacklistedEntities;
            std::vector<qtree_t> trees;
        };

        extern qtree_t _root;

        /**
         * Client-side streamer cache that stores current entities
         */
        extern std::unordered_map<uint64_t, entity_t> client_cache;

        /**
         * Public API method for inserting an entity to the quad tree.
         * @param entity An entity to insert.
         */
        bool insert(entity_t entity);

        /**
         * Public API method for removing entity from the streamer
         * @param  entity
         * @return
         */
        bool remove(entity_t entity);

        /**
         * Public API method for cleaning up the quad-tree.
         */
        void clear();

        /**
         * Public API method for cleaning up the quad-tree and
         * setting up a new boundary.
         * @param bounds A tree world boundary.
         */
        void clear(aabb_t bounds);

        /**
         * Public API method for querying a list of entities that should be
         * streamed.
         * @param entity An entity to be queried against.
         */
        std::vector<entity_t> query(entity_t entity);

        /**
         * Public API method for setting the global visibility of the entity.
         * @param  entity An entity to deal with.
         * @param  state  A visibility state.
         * @return        Returns zero if no change has happened, one otherwise.
         */
        bool set_visible(entity_t entity, bool state);

        /**
         * Public API method for setting visibility of the entity for a specific
         * entity target.
         *
         * Only works if the target entity has a streamable component.
         *
         * @param  target An entity target we relate entity state with.
         * @param  entity An entity we set states for.
         * @param  state  A visibility state.
         * @return        Returns zero if no change has happened, one otherwise.
         */
        bool set_visible_for(entity_t target, entity_t entity, bool state);
    }
}

#endif // librg_streamer_h
