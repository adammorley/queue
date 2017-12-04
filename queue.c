#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

queue* queue_new() {
    queue* q = malloc(sizeof(queue));
    if (q == NULL) assert(true);
    q->f = NULL;
    q->b = NULL;
    return q;
}

static bool _empty(queue* q) {
    if (q->f == NULL && q->b == NULL) return true;
    return false;
}

void q_enqueue(queue* q, void* ptr) {
    queue_element* qe = malloc(sizeof(queue_element));
    qe->ptr = ptr;
    qe->n = NULL;
    qe->p = NULL;
    if (_empty(q)) {
        q->f = q->b = qe;
        return;
    }
    qe->p = q->b;
    q->b = q->b->n = qe;
    return;
}

void* q_dequeue(queue* q) {
    if (_empty(q)) return NULL;
    queue_element* qe = q->f;
    if (qe->n == NULL) q->b = q->f = NULL;
    else {
        q->f = qe->n;
        q->f->p = NULL;
    }
    void* ptr = qe->ptr;
    free(qe);
    return ptr;
}
