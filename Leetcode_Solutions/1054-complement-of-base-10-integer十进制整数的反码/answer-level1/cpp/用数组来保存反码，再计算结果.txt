![image.png](https://pic.leetcode-cn.com/dd81da1ed87594a177d75a7ea36ab0975ff786a078645cf4517819c67caeb4d7-image.png)


### 解题思路
以一个数组来储存N的反码。
注意，要使用插入操作，保证每个新计算的码都在数组的最前面。
这样，顺序才与二进制数相同。

再来将二进制数转化为十进制数。
可以参考这道题[https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/](二进制链表转整数) 二进制链表转整数

### 代码

```cpp
class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N) {
            return 1;
        }
        vector<int> bit;
        while(N > 0) {
            bit.insert(bit.begin(), N % 2 ? 0 : 1);
            N /= 2;
        }
        
        int ans = 0;
        for(int i = 0; i != bit.size(); ++i) {
            ans *= 2;
            ans += bit[i];
        }
        return ans;
    }
};
```