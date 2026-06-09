### 解题思路
进位模拟，数学题

![image.png](https://pic.leetcode-cn.com/b2d86837a7ba0ed6f872019dc2c4422b46d6102b0dc235841d585d462cc3cfd3-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size() - 1, now = digits.size() - 1;
        digits[len] ++;
        while(digits[now] > 9 && now > 0)
        {
            now --;
            digits[now] ++;
        }
        if(digits[now] > 9)
        {
            digits.push_back(0);
            digits[0] = 1;
            len ++;
        }
        while(now < len)
        {
            now ++;
            digits[now] = 0;
        }
        return digits;
    }
};
```