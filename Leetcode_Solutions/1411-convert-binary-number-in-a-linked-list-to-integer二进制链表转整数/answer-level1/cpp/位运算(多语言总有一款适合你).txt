# 思路
`re`表示结果，初始化为0
取出节点数据，与`re`左移一位的结果按位或(左移后补０，不会出现同为１的情况，所以是可行的)
移动到下一个节点

# 代码
## `Cpp`
```cpp
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *tmp = head;
        int re = 0;
        while (tmp != nullptr) {
            re = (re << 1) | (tmp->val);
            tmp = tmp->next;
        }
        return re;
    }
};
```
![image.png](https://pic.leetcode-cn.com/9cfee8f389df36bb6d028da3ae153967d78df6e633f0ae7b2439539beac4f35a-image.png)


## `Go`
```go
func getDecimalValue(head *ListNode) int {
    re := 0
    for tmp := head ; nil != tmp ; {
        re = (re << 1) | (tmp.Val)
        tmp = tmp.Next
    }
    return re
}
```
![image.png](https://pic.leetcode-cn.com/1095f031f71c29efebef8621c34545c01ea3ebfce902e8cbd54145757c921493-image.png)

## `Python3`
```python
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        re = 0
        tmp = head
        while tmp is not None:
            re = (re << 1) | tmp.val
            tmp = tmp.next
        return re
```
![image.png](https://pic.leetcode-cn.com/5d4e587f176acd34eeac4c3807fe380a131bb00464c45dc6e59fcf962db70778-image.png)

# 分析
- 时间复杂度：　需要遍历全部节点，因此时间复杂度为$O(n)$
- 空间复杂度：　没有使用额外的空间，因此空间复杂度为$O(1)$