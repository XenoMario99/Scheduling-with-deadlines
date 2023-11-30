#pragma once

#include "quickSort.h"

namespace scheduling {

typedef int index;

struct Task {
    index id;
    int boundaryTerm;
    int benefit;

    Task() : id(0), boundaryTerm(0), benefit(0) {}
    Task(index id, int bT, int bf) : id(id), boundaryTerm(bT), benefit(bf) {}

    ~Task() {}
};

void scheduleWithDeadlines(std::vector<Task>& tasks);

}  // namespace scheduling