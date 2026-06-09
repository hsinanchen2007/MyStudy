### 1. 优先队列

对于优先队列有这几种做法：

**方法1：** 建立优先队列（最大堆或者最小堆均可），全部元素接连入队；最后再不断弹出，构建链表。这也是一种想法，不过这样子效率就有些低下了。

> 空间复杂度O(n)，时间复杂度O(2*log(**n!**)) ；n是所有节点个数

这里我不知道计算是否正确，如果不对还望指出~~

**方法2：** 依然建立优先队列，不过不需要全部元素一次性入队；**只需要让链表头元素入队即可，弹出该元素后，该链表往后移。**

![优先队列](https://pic.leetcode-cn.com/fb973066389b2b2e921601bd404fa29c9eb12cdb0bc877f4253492fbf5b9250a)

> 空间复杂度 O(k)，时间复杂度 O(**nlog(k)**)；n是所有节点个数，k是链表数


**代码：**
```cpp
class Solution {
public:
    // 小根堆的回调函数
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }
};
```

### 2. 两两合并

在做这个题前，我们肯定会遇到 **[21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)** 这道题，不了解的伙伴儿可以先移步了解一下。

简单的说，合并两个有序链表可以使用迭代或者递归来完成，思路是一样的；这里就不多做介绍了。

对于合并K个链表，不难想到我们可以从头开始**两两合并**。

**这里时间复杂度的计算和下一种方法分治合并可能有的伙伴会有混淆，在下面做详细介绍**

> 时间复杂度 O(kn) ，空间复杂度 O(1)【不考虑递归调用栈】


**代码：**
```cpp
class Solution {
public:
    // 合并两个有序链表
    ListNode* merge(ListNode* p1, ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next = merge(p1->next, p2);
            return p1;
        }else{
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

     ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i<lists.size(); ++i){
            if(lists[i]) head = merge(head, lists[i]);
        }
        return head;  
    }
};
```

### 3. 分治合并

还是采用上面两两合并的法子，不过这里添加分治的思想，请看下图，这就是分治合并的过程

+ k个链表两两配对，进行第一轮合并，结束后k个链表被合并成k/2个链表
+ k/2个链表依然两两配对，进行第二轮合并，结束后k/2个链表被合并成k/4个链表
+ 重复上述过程，进行log(k)次合并，完成总体合并工作

![分治合并](https://pic.leetcode-cn.com/72ec698ca75a416fd5d8abb76a43549e26e78fc7acf5c24889ebe7ac7de6b7a8)

> 时间复杂度 O(logk * n)，空间复杂度 O(1)【不考虑递归调用栈】

**代码：**

```cpp
class Solution {
public:
    // 合并两个有序链表
    ListNode* merge(ListNode* p1, ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next = merge(p1->next, p2);
            return p1;
        }else{
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

    ListNode* merge(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* l1 = merge(lists, start, mid);
        ListNode* l2 = merge(lists, mid+1, end);
        return merge(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size()-1);
    }
};
```

### 4. 两两合并和分治合并时间复杂度解析

假设有K条链表，所有链表等长，每个链表长度为N，这里只是为了方便演示，实质上无所谓。

合并两个有序链表的时间复杂度是O(n)，n是两个链表的总节点数。

**两两合并**

两两合并需要进行 K-1 次合并，时间复杂度求和为：

2N + 3N + 4N + ... + KN = (K+2) * (K-1) * N / 2

这里近似看为 K * K*N , 也就是K * n  【n是链表总节点数】

**分治合并**

K个有序链表，每次分割一半，总共需要分割logK次，而每一轮merging的时间复杂度为O(n)，注意这里的n是所有链表的节点总数，因为每一次merging所有的节点都需要比较一次，可参考上述分治合并过程的图片。则时间复杂度求和为：

logK * O(n) = O(n* logK)


**有哪里不对的地方，还请指出来呀~~**
