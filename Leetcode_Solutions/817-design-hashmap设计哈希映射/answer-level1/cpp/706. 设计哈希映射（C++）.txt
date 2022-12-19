# 706. 设计哈希映射
```
class Node{
public:
	int key;
	int val;
	Node *next;
public:
	Node(int _key,int _val){
		key  = _key;
		val  = _val;
		next = nullptr;
	}
};

class MyHashMap {
private:
	vector<Node *> arr;
	int MaxArrLength = 10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        arr = vector<Node *>(MaxArrLength,new Node(-1,-1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int group_id = key % MaxArrLength;
		Node *group_ptr = arr[group_id];
		while( group_ptr->next != nullptr ){
			if( group_ptr->next->key == key ){
				group_ptr->next->val = value;
				return;
			}
			group_ptr = group_ptr->next;
		}
		Node *temp = new Node(key,value);
		group_ptr->next = temp;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int group_id = key % MaxArrLength;
		Node *group_ptr = arr[group_id];
		while( group_ptr->next != nullptr ){
			if( group_ptr->next->key == key ){
				return group_ptr->next->val;
			}
			group_ptr = group_ptr->next;
		}
		return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int group_id = key % MaxArrLength;
		Node *group_ptr = arr[group_id];
		while( group_ptr->next != nullptr ){
			if( group_ptr->next->key == key ){
				Node *temp = group_ptr->next;
				group_ptr->next = group_ptr->next->next;
				delete temp;
				return;
			}
			group_ptr = group_ptr->next;
		}
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```
