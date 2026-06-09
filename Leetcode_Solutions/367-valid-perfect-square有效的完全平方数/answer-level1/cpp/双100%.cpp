### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        long l = 1, r = num;

        while (l <= r)
        {
            long mid = l + (r - l) / 2;
            if (mid * mid > num) r = mid - 1;
            else if (mid * mid < num) l = mid + 1;
            else return true;
        }
        return false;
    }
};
```