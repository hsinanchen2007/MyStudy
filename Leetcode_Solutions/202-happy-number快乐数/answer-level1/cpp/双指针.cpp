### 解题思路
这道题目的难点在于如果不为1，如何跳出循环。

这里我们发现，如果不为1的话，就是一个死循环，那么我们就可以按照环形链表的思想来做。
设定两个数fast和slow。
fast执行两次操作，slow执行一次操作。
如果最后可以为1，则1的操作后还是1，所以，也是一个回环，可以跳出循环；
如果最后不可为1，则是一个死循环，那么使用双指针总能找到相同的情况；
这样就可以跳出循环了。

### 代码

```cpp
class Solution {
public:
    int suqre_num(int x){
        string s  = to_string(x);
        int res = 0;
        for(int i=0;i<s.size();i++){
            res = res + (s[i] - '0') * (s[i] - '0');
        }
        return res;
    }
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        slow = suqre_num(slow);
        fast = suqre_num(fast);
        fast = suqre_num(fast);
        //利用双指针来解决这个问题
        while(fast != slow){
          slow = suqre_num(slow);
          fast = suqre_num(fast);
          fast = suqre_num(fast);
        }
        if(slow == 1) return true;
        else return false;
    }
};
```