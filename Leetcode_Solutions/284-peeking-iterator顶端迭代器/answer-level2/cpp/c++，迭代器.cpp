复制一个当前状态的迭代器，并调用next，使得目前的迭代器位置不变
```
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if(hasNext()){
            Iterator it(*this);
            return it.next();
        }
        return 0;
    }
```