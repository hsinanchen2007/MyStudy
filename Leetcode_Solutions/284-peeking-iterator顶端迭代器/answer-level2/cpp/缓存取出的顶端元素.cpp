### 解题思路
缓存取出的顶端元素，并用一个布尔变量表示当前是否有缓存值。

### 代码

```cpp
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool has_temp = false;
    int tmp = 0;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (has_temp)
            return tmp;
        if (!Iterator::hasNext())
            return -1;
        has_temp = true;
        tmp = Iterator::next();
        return tmp;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (has_temp) {
            has_temp = false;
            return tmp;
        }
        return Iterator::next();
	}

	bool hasNext() const {
	    if (has_temp)
            return true;
        return Iterator::hasNext();
	}
};
```