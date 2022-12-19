3种方法 按照时间复杂度排序
第一种  最简单的，利用vector来存储每一个链表节点的指针，然后利用前后的双指针，把vector中的节点拼接在一起
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        auto p = head;
        while(p)
        {
            v.push_back(p);
            p = p->next;
        }
        ListNode* dummy = new ListNode(0);
        p = dummy;
        int l = 0, r = v.size() - 1;
        
        while(l <= r)
        {
            //cout << "l: " << l << " r: " << r << endl;
            p->next = v[l++];
            p = p->next;
            if(l <= r)
            {
                p->next = v[r--];
                p = p->next;
            }
        }
        p->next = nullptr;
    }
};
```

第二种 利用递归的方式
从中间开始，每次只处理左右两边新增的
![image.png](https://pic.leetcode-cn.com/64b8de7ded5360f700d05d42c5d60122b28b36a668522cd1773adbdea7dc7f79-image.png)

我们来考虑一下，处理了一层之后，外层需要什么呢？
需要返回一个内层头指针，用来拼接
那么这个内层头指针怎么拼接呢？
本层头指针->本层的尾巴->内层头指针

本层的尾巴怎么知道的？
因为每一层都是削去头和尾，所以只要知道这一层的总长度就可以知道尾巴在哪里了
```
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* dfs(ListNode* head, int len)
    {


        if(len == 0)
            return nullptr;
        if(len == 1)
        {
            head->next = nullptr;
            return head;
        }
        auto tail = head;
        int cnt = len - 1;
        while(cnt--)
        {
            tail = tail -> next;
        }
        auto tmp = head->next;
        head->next = tail;
        tail->next = dfs(tmp, len - 2);
        return head;
    }


public:
    void reorderList(ListNode* head) {
        int len = 0;
        auto p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        p = head;
        dfs(p, len);
    }
};
```


进一步优化，是否可以不用每次都用循环来算一次尾巴？我的内层递归是否能返回我的尾巴给我？也就是说返回两个东西：一个是内层头指针，一个是本层的尾巴，这样我就不用循环找尾巴了。
```
class Solution {
    pair<ListNode*, ListNode*> dfs(ListNode* head, int len)
    {
        cout << len << endl;
        if(len == 0)
        {
            return {nullptr, head};
        }
        if(len == 1)
        {
            auto tail = head->next;
            head->next = nullptr;
            return {head, tail};
        }
        auto tmp = head->next;
        auto x = dfs(tmp, len - 2);
        //cout << x.first->val << ' ' << x.second->val << endl;
        ListNode* tail = x.second;
        head->next = tail;
        tmp = tail->next;
        tail->next = x.first;
        return {head, tmp};
    }


public:
    void reorderList(ListNode* head) {
        int len = 0;
        auto p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        p = head;
        //cout << len << endl;
        dfs(p, len);
    }
};
```

再进一步优化
是否需要返回内层头指针？似乎不是需要的，因为我本层头指针的next就是内层的头指针呀
```
class Solution {
      ListNode* dfs(ListNode* head, int len)
    {
        //cout << len << endl;
        if(len == 2)
        {
            auto tail = head->next->next;
            head->next->next = nullptr;
            return tail;
            
        }
        if(len == 1)
        {
            auto tail = head->next;
            head->next = nullptr;
            return tail;
        }
        auto tmp = dfs(head->next, len - 2);
        auto tail = tmp->next;
        tmp->next = head->next;
        //cout << x.first->val << ' ' << x.second->val << endl;
        head->next = tmp;
        return tail;
    }


public:
    void reorderList(ListNode* head) {
        if(!head) return;
        int len = 0;
        auto p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        p = head;
        //cout << len << endl;
        dfs(p, len);
    }
};
```

第三种方法
把链表分成两半，然后把后面的一半反转，然后再把两半的链表拼接在一起
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    ListNode* reverse(ListNode* head)
    {
        ListNode *cur = head, *prev = nullptr;
        while(cur)
        {
            auto nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        auto slow = dummy, fast = dummy;
        while(fast!= nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //奇数是中间，偶数是中间的左边 
        auto left = head, right = slow->next;//左边的多右边少
        slow->next = nullptr;
        right = reverse(right);
        auto pt = dummy;
        while(left || right)
        {
            if(left)
            {
                dummy->next = left;
                left = left->next;
                dummy = dummy->next;
            }
            if(right)
            {
                dummy->next = right;
                right = right->next;
                dummy = dummy->next;
            }
        }
    }
};
```
还写了一些别的leetcode的题解，分享一下看看有没有需要的，题解还会更新：[https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#](https://www.yuque.com/books/share/300e07be-6fc9-417d-bb05-c50f5dea1618?#)
顺带给自己推一波公众号，要是有兴趣可以关注：**麦芽糖的笔记本**
![image.png](https://pic.leetcode-cn.com/95c54eba219d34f176350f6968ff8d934a93879a43a12f926b2e05148b5833ca-image.png)

公众号回复**LC**，可以下载题解的pdf版本，pdf也会更新

![image.png](https://pic.leetcode-cn.com/a533ef6e9a37396c93e0d965e5ef389996a90e8c5b6a05d35aa19d918dcf8b86-image.png)



