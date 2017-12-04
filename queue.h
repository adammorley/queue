/*
    first-in, first-out queue implementation
    with void pointers for re-usability

    can add mutex later if multi-threading needed
*/
#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue_element queue_element;
struct queue_element {
    void* ptr;
    queue_element* n;
    queue_element* p;
};

typedef struct queue {
    queue_element* f;
    queue_element* b;
} queue;

// create a new queue
queue* queue_new();

// put on back
void q_enqueue(queue* queue, void* ptr);

// take off front
void* q_dequeue(queue* queue);

#endif //QUEUE_H
