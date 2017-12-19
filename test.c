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
    int* p;
    for (int i = 5; i<= 8; i++) {
        p = q_dequeue(q);
        assert(*p == i);
        free(p);
    }
    assert(q_dequeue(q) == NULL);
    free(q);
    return 0;
}
