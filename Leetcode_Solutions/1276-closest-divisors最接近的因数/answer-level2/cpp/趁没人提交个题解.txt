### 解题思路

![image.png](https://pic.leetcode-cn.com/e34621c4bd0e6281dc7ff9b0a499e2aa6367508e6abd9af9820bcc29f4f762fc-image.png)

### 代码

```cpp
class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> result;
        if (num == 1)
        {
            result.push_back(1);
            result.push_back(2);
            return result;
        }
        int gen = sqrt(num);
        
        int left = gen+1;
        int right = gen+1;
        while ((num+1) % left != 0)
        {
            left--;
        }
        right = (num+1)/left;
        int abs1 = abs(left-right);
        
        int left2 = gen+1;
        int right2 = gen+1;
        while ((num+2) % left2 != 0)
        {
            left2--;
        }
        right2 = (num+2)/left2;
        int abs2 = abs(left2-right2);
        if (abs1<=abs2)
        {
            result.push_back(left);
            result.push_back(right);
        }
        else
        {
            result.push_back(left2);
            result.push_back(right2);
        }
        
        return result;
    }
};
```