#include <clocale>
#include "unit/tests.hpp"
#include "perf/tests.hpp"

int main()
{
    #ifdef WIN32
        // Set our locale to the C locale, as Unicode output only functions in this locale
        std::setlocale(LC_ALL, "C");
        SetConsoleOutputCP(CP_UTF8);
    #endif

    motd();
    {
        run_unit_tests();
        performance::run_tests();
    }

    return results();
}
