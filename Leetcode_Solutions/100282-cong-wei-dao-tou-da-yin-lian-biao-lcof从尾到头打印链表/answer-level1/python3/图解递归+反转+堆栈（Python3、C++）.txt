### 思路一：反转
从头到尾将链表打印到数组中，返回反转后的结果即可。

#### 代码

```python []
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        res = []
        while head:
            res.append(head.val)
            head = head.next
        return res[::-1]  # 或者 reverse(res)
```

```python []
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        res = []
        while head:
            res = [head.val] + res
            head = head.next
        return res
```
```C++ []
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while (head){
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

#### 复杂度分析
- 时间复杂度：$O(n)$，$reverse()$ 的时间复杂度为 $O(n)$，遍历了一遍数组，复杂度也为 $O(n)$。
- 空间复杂度：$O(n)$，使用了额外的 `res`。

### 思路二：递归

假设 `head.next` 已经排好序，那么只需将 `head` 添加到末尾即可。

其中，`head.next` 部分可以使用递归来实现，递归的终止条件为 `head` 为空。

![6.gif](https://pic.leetcode-cn.com/8d355b0406f16bca1966fa5e6ed0808ec26ee52104350acd10b148e7c043d731-6.gif)



#### 代码
```python []
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        if not head: return []
        return self.reversePrint(head.next) + [head.val]
```

```C++ []
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if (!head) return res;
        reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};
```

#### 复杂度分析

- 时间复杂度：$O(n)$，递归 $n$ 次，时间间复杂度为 $O(n)$，递归函数中的操作时间复杂度为 $O(1)$，总时间复杂度为 $O(n)\times O(1)=O(n)$。
- 空间复杂度：$O(n)$，递归将占用链表长度的栈空间。

### 思路三：堆栈

利用堆栈先进后出的特点，先依次将元素压入堆栈中，然后将所有元素从堆栈中弹出，即可实现反转。

#### 代码

```python []
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []
        while head: # push
            stack.append(head.val)
            head = head.next
        res = []
        while stack: # pop
            res.append(stack.pop())
        return res
```
```C++ []
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        stack<int> st;
        while(head){// push
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty()){ // pop
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```
#### 复杂度分析

- 时间复杂度：$O(n)$，$push$ 的间复杂度为 $O(n)$，$pop$ 的间复杂度为 $O(n)$。
- 空间复杂度：$O(n)$，使用了额外的 `res` 和 堆栈。


### 视频

![6.mp4](d0c9cb4f-6ef2-41cc-a137-ae7ba6dc8f29)
