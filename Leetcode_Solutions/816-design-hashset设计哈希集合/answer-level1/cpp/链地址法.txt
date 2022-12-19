### 解题思路
此处撰写解题思路

### 代码

```cpp
/*struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val),next(nullptr){}
};*/
const int len=100;
class MyHashSet {
public:
    vector<ListNode*> arr;
    /** Initialize your data structure here. */
    MyHashSet() {
        arr=vector<ListNode*>(len,new ListNode(-1));

    }
    
    void add(int key) {
        int hash=key % len;
        ListNode* temp=arr[hash];
        if(temp->val!=-1){
            while(temp){
                if(temp->val==key) return;
                if(!(temp->next)){
                    ListNode* node=new ListNode(key);
                    temp->next=node;
                    return;
                }
                temp=temp->next;
            }
        }
        else {
            temp->val=key;
            return;
        }
    }
    
    void remove(int key) {
        int hash=key % len;
        ListNode* temp=arr[hash];
        if(temp->val!=-1){
            while(temp){
                if(temp->val==key){
                    temp->val=-1;
                    return;
                }
                temp=temp->next;
            }
        }

    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash=key % len;
        ListNode* temp=arr[hash];
        while(temp){
            if(temp->val==key) return true;
            temp=temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```