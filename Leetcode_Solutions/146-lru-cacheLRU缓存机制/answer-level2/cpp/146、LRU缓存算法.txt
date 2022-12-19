### 解题思路
双向链表+哈希表实现。
STL对应为 list 和 unordered_map

### 代码

```cpp
#include <unordered_map>
using namespace std;
class LRUCache {
private:
    struct ListNode{
        int val;
        int data;
        ListNode* pre;
        ListNode* next;
        ListNode(int x):val(x),data(x),pre(NULL),next(NULL){}
    };
    ListNode* head = new ListNode(0);
    ListNode* tail = new ListNode(0);
    unordered_map<int,int> h_table;
    unordered_map<int,int>::const_iterator h_it;
    int capacity_;
    int count_;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        count_ = 0;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        h_it = h_table.find(key);
        if(h_it == h_table.end()){
            return -1;
        }else{
            ListNode* p = head->next;
            while(p){
                if(p->val == key){
                    p->next->pre = p->pre;
                    p->pre->next = p->next;

                    p->next = head->next;
                    p->pre = head;
                    head->next->pre = p;
                    head->next = p;
                    break;
                }
                p = p->next;
            }
            return h_it->second;
        }
    }
    
    void put(int key, int value) {
        int data_temp = get(key);
        if(data_temp != -1){
            ListNode* p = head->next;
            while(p){
                if(p->val == key){
                    if(data_temp != value){
                        p->data = value;
                        h_table[key] = value;    
                    } 
                    p->next->pre = p->pre;
                    p->pre->next = p->next;
                    p->next = head->next;
                    p->pre = head;
                    head->next->pre = p;
                    head->next = p;
  
                    break;
                }
                p = p->next;
            }
        }else{
            if(count_ < capacity_){
                ListNode* temp = new ListNode(key);
                temp->next = head->next;
                temp->pre = head;
                head->next->pre = temp;
                head->next = temp;
                h_table.insert(pair<int,int>(key,value));
                count_++;
            }else if(count_ == capacity_ && capacity_ != 0){
                int temp_key = tail->pre->val;
                tail->pre = tail->pre->pre;
                tail->pre->next = tail;
                ListNode* temp = new ListNode(key);
                temp->next = head->next;
                temp->pre = head;
                head->next->pre = temp;
                head->next = temp;
                h_table.erase(temp_key);
                h_table.insert(pair<int,int>(key,value));
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```