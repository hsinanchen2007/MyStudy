### 解题思路
此处撰写解题思路

### 代码

```cpp
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        n=1000;
		v.assign(1000,list<int>());
    }
    
	list<int>::iterator find(int key){
		k=key%n;
		list<int>::iterator it=v[k].begin();
		for(;it!=v[k].end()&&(*it!=key);++it);
		return it;
	}

    void add(int key) {
		list<int>::iterator it=find(key);
		if(it==v[k].end()) v[k].push_back(key);
    }
    
    void remove(int key) {
        list<int>::iterator it=find(key);
		if(it!=v[k].end()) v[k].erase(it);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        list<int>::iterator it=find(key);
		if(it!=v[k].end()) return true;
		return false;
    }
private:
	vector<list<int>> v;
	int k,n;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```