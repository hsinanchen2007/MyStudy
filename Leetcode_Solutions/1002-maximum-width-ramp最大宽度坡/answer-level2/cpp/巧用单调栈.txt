### 解题思路
这里用到了单调栈，先遍历得到初始化的单调递减栈(值大于等于栈顶元素就压入，否则略过)，随后从数组尾部依次递减与单调栈中的元素进行宽度值比较，满足条件则更新宽度值并弹出单调栈中的元素，直到单调栈空或者数组遍历完毕。
![捕获.PNG](https://pic.leetcode-cn.com/cd26debfc7e0052cb05a865a960cea76694cc74d945a27743306462ac6ced40d-%E6%8D%95%E8%8E%B7.PNG)
### 代码

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> sta;
        sta.push(0);
        int result = 0;
        for (int i = 1; i < A.size(); i++) {
            if (A[sta.top()] >= A[i]) {
                sta.push(i);
            }
        } 
        for (int i = A.size() - 1; i >= 0 && !sta.empty(); i--) {
            while (!sta.empty() && A[i] >= A[sta.top()]) {
                result = max(i - sta.top(), result);
                sta.pop();
            }
        }
        return result;
    }
};
```