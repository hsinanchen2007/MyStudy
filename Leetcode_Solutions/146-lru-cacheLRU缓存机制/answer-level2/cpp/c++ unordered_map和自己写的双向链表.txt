### 解题思路
原本想用stl的list，但是用的不熟练，干脆自己写个双向链表节点吧(但是还是建议用list写)。得到的结果感觉好像比用list的结果好一些。

![QQ截图20200321213022.png](https://pic.leetcode-cn.com/319b5f6cb31cb21657012116b2240453eba3b281e24ff23952bd8ecc46df503d-QQ%E6%88%AA%E5%9B%BE20200321213022.png)
中间两个是执行解题中高亮的STL执行结果，其余两个是我自己写的结果。
代码写的冗余很多，可以把一些操作抽象为函数。

### 代码

```cpp
struct ListNode_fgy{//自己写的双向链表
    int key;
    int val;
    ListNode_fgy* next;
    ListNode_fgy* prev;
    ListNode_fgy(int _key, int _val):key(_key),val(_val),next(nullptr),prev(nullptr){}
};

class LRUCache {
public:
    int cap;
    int size_L;
    ListNode_fgy *head;//链表头尾不保存元素，只是为了方便进行插入删除操作。
    ListNode_fgy *tail;
    unordered_map<int,ListNode_fgy*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        size_L=0;
        head=new ListNode_fgy(-1,-1);
        tail=new ListNode_fgy(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(mp.count(key)==0)
            return -1;
        ListNode_fgy* tmp=mp[key];
        int output=tmp->val;
        //将该元素插入到头
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
        head->next->prev=tmp;
        tmp->next=head->next;
        tmp->prev=head;
        head->next=tmp;
        return output;
    }

    void put(int key, int value) {
        if(mp.count(key)==1)
        {
            //只更新对应那个节点的位置map不用更新
            ListNode_fgy* tmp=mp[key];
            tmp->val=value;
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
            head->next->prev=tmp;
            tmp->next=head->next;
            tmp->prev=head;
            head->next=tmp;
        }
        else
        {
            if(size_L<cap)
            {
                //插入放在头部
                ListNode_fgy* tmp=new ListNode_fgy(key,value);
                head->next->prev=tmp;
                tmp->next=head->next;
                tmp->prev=head;
                head->next=tmp;
                ++size_L;
                mp[key]=tmp;
            }
            else
            {
                //删除尾结点
                ListNode_fgy* pre_tmp=tail->prev;
                pre_tmp->prev->next=tail;
                tail->prev=pre_tmp->prev;
                mp.erase(pre_tmp->key);
                delete pre_tmp;
                ListNode_fgy* tmp=new ListNode_fgy(key,value);
                head->next->prev=tmp;
                tmp->next=head->next;
                tmp->prev=head;
                head->next=tmp;
                mp[key]=tmp;
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