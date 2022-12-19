### 解题思路
分两种情况讨论：
1. 若i为奇数，则其二进数含1的个数必定是res[i - 1] + 1;
2. 若i为偶数，则其二进数含1的个数和res[i / 2]一样,因为在偶数情况下，最低位为0，那么其右移一位后得到的数对应的二进数含有的1的个数必定与原数相同。

### 代码

```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        for(int i = 1; i <= num; i++){
            if(i % 2 == 0) res[i] = res[i/2];
            else res[i] = res[i - 1] + 1;
        }
        return res;
    }
};
```