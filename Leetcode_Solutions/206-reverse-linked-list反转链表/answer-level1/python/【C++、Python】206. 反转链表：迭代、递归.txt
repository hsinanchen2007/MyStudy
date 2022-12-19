### 方法一：迭代 ###
#### 思路 ####
- 双指针，分别记录当前节点及其前一个节点
- 从头到尾遍历链表，将每个节点的`next`指针指向前一个节点即可
#### 算法 ####
- 初始化指针`prev`为`nullptr`，`curr`指向`head`
- 循环
  - 将`curr->next`暂存为`next`，然后使其指向`prev`
  - 更新`prev`为`curr`，`curr`为`next`
  - 若`curr`为`nullptr`，返回`prev`

<![幻灯片1.PNG](https://pic.leetcode-cn.com/f2a6814fc727c9880549f466f133f1c2a3b66bb45f35f28d51b16848be959a43-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/591c5b76688884a8251e4bf43aea5c2f5c63e5930074c95f18b2a5800517b59f-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/c4ae078856fa525ff0cb2423a0b6deee918bb9d7771ea6319e3fe98ecfd575b3-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/535cb6d24484629ad698eca09f967c0117319a21bc724a4663462afb397b7d88-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/739c958bfcbd89d24e7fce83a6517413527bd81cce056b65057d35512bae6b07-%E5%B9%BB%E7%81%AF%E7%89%875.PNG),![幻灯片6.PNG](https://pic.leetcode-cn.com/e54494e9793199b1398b4db5af8cdf429517e2809c3ed327a3a1fda235c122e7-%E5%B9%BB%E7%81%AF%E7%89%876.PNG),![幻灯片7.PNG](https://pic.leetcode-cn.com/9fb2cb046cdd5ed162f4668dad545173df4d99bff4e9b403fe83d5babf7de22f-%E5%B9%BB%E7%81%AF%E7%89%877.PNG)>
#### 代码 ####
```c++ []
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```
```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev, curr = None, head
        while curr:
            curr.next, prev, curr = prev, curr, curr.next
        return prev
```
#### 复杂度分析 ####
- 时间复杂度`O(n)`
- 空间复杂度`O(1)`

***
### 方法二：递归 ###
#### 思路 ####
- 若当前节点是旧链表的**表尾**，则说明它是新链表的**表头**
- 否则，反转当前节点之后的所有节点
- 因为当前节点后面的所有节点都完成了反转，所以只需
  - 令当前节点的后一个节点的`next`指针指向当前节点
  - 令当前节点的`next`指针为空
- 最后返回新的表头
#### 算法 ####
- 初始时`curr`为`head`
- 若`curr`或`curr->next`为空，返回`curr`作为`newHead`
- 否则
  - 反转以`curr->next`为表头的链表
  - 令`curr->next->next`指向`curr`
  - 令`curr->next`为`nullptr`
- 返回`newHead`

<![幻灯片1.PNG](https://pic.leetcode-cn.com/3986e4b257f7bdcc6a70bfca259b010ce606ead30026ff41969dfe25c75af9d5-%E5%B9%BB%E7%81%AF%E7%89%871.PNG),![幻灯片2.PNG](https://pic.leetcode-cn.com/872736be279bbbe41581e678dbf0c5ee7b7a9faf5a1218913bc5d6e50a22d00d-%E5%B9%BB%E7%81%AF%E7%89%872.PNG),![幻灯片3.PNG](https://pic.leetcode-cn.com/efb40736bf3dcdae06bd7b7072155729d864d135b93d79662744803561b39f11-%E5%B9%BB%E7%81%AF%E7%89%873.PNG),![幻灯片4.PNG](https://pic.leetcode-cn.com/a460332b177ed12c5cde331c4be04684165bb8dd5b31d8cd73a84f8b42c6afe9-%E5%B9%BB%E7%81%AF%E7%89%874.PNG),![幻灯片5.PNG](https://pic.leetcode-cn.com/1939ee4064843062393069556599ad69c485447b5fcfe35864f82c2f9e4d5ac0-%E5%B9%BB%E7%81%AF%E7%89%875.PNG)>
#### 代码 ####
```c++ []
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
```
```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        newHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return newHead
```
#### 复杂度分析 ####
- 时间复杂度`O(n)`
- 空间复杂度`O(n)`