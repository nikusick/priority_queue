#include "priority_queue.h"

int main() {
    priority_queue<int, std::vector<int>, std::greater<>> pq;
    pq.push(0);
    pq.push(20);
    pq.push(10);
    pq.pop();
    pq.push(15);
    pq.push(50);
    pq.push(13);
    pq.pop();
    return 0;
}
