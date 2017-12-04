#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

static int* p(int i) {
    int* p = malloc(sizeof(int));
    *p = i;
    return p;
}

int main() {
    queue* q = queue_new();
    assert(q_dequeue(q) == NULL);
    q_enqueue(q, p(5));
    q_enqueue(q, p(6));
    q_enqueue(q, p(7));
    q_enqueue(q, p(8));
    assert(*(int*)q_dequeue(q) == 5);
    assert(*(int*)q_dequeue(q) == 6);
    assert(*(int*)q_dequeue(q) == 7);
    assert(*(int*)q_dequeue(q) == 8);
    assert(q_dequeue(q) == NULL);
    return 0;
}
