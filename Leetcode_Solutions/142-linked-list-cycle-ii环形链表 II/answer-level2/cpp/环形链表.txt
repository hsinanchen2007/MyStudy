
- ### 方法一
中规中矩的想法，就是将遍历过的元素放到一个集合，每次遍历之前先查看集合中是否已经存在，如果存在，直接返回，否则继续。
```
//set记录
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         set<ListNode *>mySet;
//         while(head){
//             if(mySet.find(head)==mySet.end()){
//                 mySet.insert(head);
//             }else{
//                 return head;
//             }
//             head=head->next;
//         }
//         return NULL;
//     }
// };
```
- ### 方法二
快慢指针起初是真的没有想到，毕竟是第一次刷到这种题，看到题解之后才恍然大明白，所以这里就记录一下吧。
设置两个指针`fast`和`slow`，`fast`一次后移两个，`slow`一次后移一个。如果没环的话，两者自然是不会相遇的。但是如果有环的话就分两步解决
- 找到`fast`和`slow`两个指针的相遇点。
- 从`head`和`fast`开始向后走，这次两个指针都是每次走一步。然后在此相遇的时候就是入环点
当然了看了那么多题解，这个大家都知道了。接下来说一下我自己理解的证明吧（有错希望可以指正）
    假设环的长度是`r`，非环的长度是`s`，`fast`和`slow`指针在入环c步之后相遇。
    接下来只需要证明`s=kr-c`就可以了。(k表示几圈)
    `slow`走了`k`步到了相遇点。`fast`走了`2k`步，这时`fast`已经转了`n`圈环，所以有`k=s+c,2k-s=nr=> s=nr-c`
    故得证

```
//快慢指针
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow=head,*fast=head,*temp=head;
//         while(fast!=NULL&&fast->next!=NULL){
//             fast=fast->next->next;
//             slow=slow->next;
//             if(slow==fast){
//                 while(temp!=fast){
//                     fast=fast->next;
//                     temp=temp->next;
//                 }
//                 return fast;
//             }
//         }
//         return NULL;
//     }
// };
```
- ### 方法三
评论区网友根据内存地址高低判断的骚操作
```

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         while(head) {
//             if(!less<ListNode *>()(head, head->next)) {
//                 return head->next;
//             }
//             head = head->next;
//         }
//         return nullptr;
//     }
// };
```

