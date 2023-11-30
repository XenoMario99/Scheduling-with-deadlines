#include "scheduling.h"

#include <algorithm>

namespace scheduling {

void scheduleWithDeadlines(std::vector<Task>& tasks) {
    if (!tasks.empty()) {
        const auto& predicate{[](const Task& lhs, const Task& rhs) -> bool { return lhs.benefit > rhs.benefit; }};
        auto maxElem{std::max_element(tasks.begin(), tasks.end(), [](const Task& lhs, const Task& rhs) -> bool { return lhs.boundaryTerm < rhs.boundaryTerm; })};  // chosing the latest boundary term to know when to finish
        sort::quickSort<Task>(tasks.begin(), tasks.end(), predicate);                                                                                              // sorting tasks in decreasing order basing on boundary terms

        int timer{0};
        auto ptr{tasks.begin()};
        auto reference{tasks.begin()};

        while (timer <= maxElem->boundaryTerm) {
            if (ptr->boundaryTerm >= timer) {  // We are placing feasible tasks on the front of the vector
                auto temp{*ptr};
                *ptr = *reference;
                *reference = temp;
                reference++;
            }

            timer++;
            ptr++;
        }

        tasks.erase(reference, tasks.end());  // erasing infeasible tasks
    }
}

}  // namespace scheduling