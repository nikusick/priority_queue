#include <vector>
#include <iterator>

template<
        class T,
        class Container = std::vector<T>,
        class Compare = std::less<typename Container::value_type>
> class priority_queue {
private:
    std::vector<T> _container;
    Compare _compare;

    void siftUp(int index) {
        if (index != 0) {
            if (_compare(_container[(index - 1) / 2], _container[index])) {
                std::swap(_container[index], _container[(index - 1) / 2]);
                siftUp((index - 1) / 2);
            }
        }
    }

    void siftDown(int index) {
        auto left = 2 * index + 1;
        auto right = 2 * index + 2;
        int cur;
        if (left >= _container.size()) return; // no children
        if (right >= _container.size()) { // only left
            cur = left;
        }
        else {
            cur = _compare(_container[left], _container[right]) ? right : left;
        }
        if (_compare(_container[index], _container[cur])) {
            std::swap(_container[cur], _container[index]);
            siftDown(cur);
        }
    }

public:
    void push(const T& value) {
        _container.push_back(value);
        siftUp(_container.size() - 1);
    }

    void pop() {
        if (!empty()) {
            std::swap(_container.front(), _container.back());
            _container.pop_back();
        }
        siftDown(0);
    }

    const T& top() const {
        return _container.front();
    }

    bool empty() const {
        return _container.empty();
    }
};