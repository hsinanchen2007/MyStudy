### 结果
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 解题思路
从末尾开始一个个数有多少个1，但因为是二进制，用位运算就比较轻松了。
使用``` n&1 ```判断末尾是否是1，是就+1
使用n>>1，二进制串向右移动一位

### 代码

```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n)
        {
            if(n&1)ans++;
            n=n>>1;
        }
        return ans;
    }
};
```