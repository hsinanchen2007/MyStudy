### 解题思路
普通做法会将头结点和非头结点附加处理，虚拟头结点的作用就是让头结点看上去和非头结点一样，操作统一化

### 代码

```cpp
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* invented = new ListNode(0); //构建虚拟头节点
        invented -> next = head;
        ListNode* prev = invented;
        while(prev && prev -> next) { //从虚拟头结点之后的头结点开始搜索
            if(prev -> next -> val == val) {
                prev -> next = prev -> next -> next; //删除
                break; //删除之后跳出循环
            }
            prev = prev -> next; //向后搜索
        }
        return invented -> next; //返回头节点
    }
};

```