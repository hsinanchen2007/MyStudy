```C++ []
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
public:
    int curr;
    bool hit_end;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hit_end = false;
        if (Iterator::hasNext()) {
            curr = Iterator::next();
        } else {
            hit_end = true;
        }
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return curr;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if (hit_end) {
            return -1;
        }
        int res = curr;
	    if (Iterator::hasNext()) {
            curr = Iterator::next();
        } else {
            hit_end = true;
        }
        return res;
	}

	bool hasNext() const {
	    return !hit_end;
	}
};
```

![image.png](https://pic.leetcode-cn.com/6ed2ae1519c599d4cdbba12c8660ad2b8c388f3ada4f0a589f40cece8f8d46f9-image.png)
