### 法一：申请额外空间
&emsp;基础法，利用new，申请堆空间进行处理：
&emsp;解题思路
- 初始化一个虚拟结点，一个扫描结点
- 循环，利用头插法插入结点


```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dhead = new ListNode(1);
        ListNode* sc = head;
        while (sc){
            ListNode* tmp = new ListNode(sc->val);
            tmp->next = dhead->next;
            dhead->next = tmp;
            sc = sc->next;
        }

        return dhead->next;
    }
};
```

### 法二：就地
&emsp;就是把5->4->3->2->1->NULL $\rightarrow$ 改为 NULL<-5<-4<-3<-2<-1,也就是**把链表就地翻转过来**。
- 初始化结点，$tmp$暂存，$cur$表示当前结点，$pre$表示之前结点
- `tmp = cur->next` 暂存
- `cur->next = pre` 翻转到前面那个
- `pre = cur` 改变$pre$，保存，用于下次循环
- `cur = tmp` 进行下一次处理


```
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        
        return pre;
    }
};
```



### 法三：递归
&emsp; 这个相对比较难理解。(建议先看看代码)首先用我的语言总结一下：**递归处理好之后的，然后处理好现在的**,举个例子：
$$eg: 3 \rightarrow 4 \rightarrow 5 \rightarrow NULL$$
&emsp; 递归到最后的位置，如图,**t**是递归处理结束后返回的结点:
$$ 3 \rightarrow \overbrace{4}^{cur} \rightarrow \overbrace{5}^{t} \rightarrow NULL$$
&emsp; 然后进行修改第一次修改，也就是，让$t$指向$cur$,$cur$指向$NULL$:
$$ 3 \rightarrow \overbrace{4}^{\uparrow ^{NULL}} \leftarrow \overbrace{5}^{t}$$
&emsp;这时候我们已经完成这次递归的步骤，并返回，进入上一次层，在上一层中，$cur$指向的是3结点(注意$t$的位置)：
$$ \overbrace{3}^{cur} \rightarrow \overbrace{4}^{\uparrow ^{NULL}} \leftarrow \overbrace{5}^{t}$$
&emsp; 然后，我们继续进行修改，就是`cur->next->next(4的next)=cur(3)`和`cur->next(3的next)=NULL`，修改后如图：
$$NULL \leftarrow \overbrace{3}^{cur} \leftarrow 4 \leftarrow \overbrace{5}^{t}$$
&emsp; 这时候，我们返回$t$结点。
&emsp; 因此，总结如下: 我们首先通过递归确定**尾端结点**，并进行**翻转操作**，返回代表着**我已经将你下一个结点以后的结点都翻转好了，你只需要翻转你和你的下一个结点。**
```cpp

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* t = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return t;
    }
};
```