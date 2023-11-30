#include "scheduling.h"

#include <gtest/gtest.h>

#include <algorithm>

namespace scheduling {

TEST(ScheduleWithDeadlinesTest, schedule_ok) {
    std::vector<Task> tasks{Task(1, 3, 25), Task(2, 2, 10), Task(3, 3, 15), Task(4, 3, 40),
                            Task(5, 1, 30), Task(6, 1, 20), Task(7, 1, 35)};

    std::vector<Task> expected{Task(4, 3, 40), Task(7, 1, 35), Task(1, 3, 25)};

    scheduleWithDeadlines(tasks);

    EXPECT_EQ(tasks.size(), expected.size());

    for (auto ptr{expected.begin()}; ptr != expected.end(); ptr++) {
        EXPECT_NE(std::find_if(tasks.begin(), tasks.end(), [&ptr](const Task& task) -> bool { ptr->id == task.id; }), tasks.end());
    }
}

}  // namespace scheduling