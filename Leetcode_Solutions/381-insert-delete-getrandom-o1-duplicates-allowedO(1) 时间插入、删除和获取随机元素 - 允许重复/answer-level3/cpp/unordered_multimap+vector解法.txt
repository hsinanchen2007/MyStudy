```
/** Initialize your data structure here. */
    unordered_multimap<int, int> m;
    unordered_multimap<int, int>::iterator it;
    vector<unordered_multimap<int, int>::iterator> v;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        it = m.find(val);
        v.push_back(m.insert({val, v.size()}));//first是val元素值， second的是存放当前元素的数组下标
        return it == m.end() ? true : false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        it = m.find(val);
        if(it == m.end()) return false;
        int index = it->second;
        v[index] = v[v.size()-1];//将数组尾部的元素搬到index上，这样只要删除尾部就行  实现了o1的数组删除
        m.erase(it);
        v.erase(v.end()-1);
        if(index != v.size()) v[index]->second = index;//若要删除的就是尾部的 则不能对其进行修改，因为在上一个行以及将其删除了。若要删除的不在尾部，则需要将存在index上的迭代器的second更新 指向当前index
        return true;
    }//不能在map上更新是因为，我们这个map是multimap，我们find到的元素不一定是我们需要修改，这样反而修改了不需要修改的值的下标
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand() % (v.size());
        return v[index]->first;
    }
```