```c++
class MyHashMap {
private:
    struct node {
        int value;
        int key;
        node* next;
        node(int k, int val): key(k), value(val), next(NULL) {};
    };
    vector<node*> dict;
    int size = 10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        dict = vector<node*>(size, new node(-1, -1));
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key % size;
        node* temp = dict[index];
        node* last_node;
        while(temp != NULL) {
            if (temp->key == key) {
                temp->value = value;
                return;
            }
            last_node = temp;
            temp = temp->next;
        }
        node* cur = new node(key, value);
        last_node->next = cur;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key % size;
        node* temp = dict[index];
        while(temp != NULL) {
            if (temp->key == key) {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key % size;
        node* temp = dict[index];
        node* last_node = temp;;
        while(temp != NULL) {
            if (temp->key == key) {
                last_node->next = temp->next;
                return;
            }
            last_node = temp;
            temp = temp->next;
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
