### 解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
8.3 MB
, 在所有 C++ 提交中击败了
14.73%
的用户

### 代码

```cpp
class Solution {
public:class Solution {
public:
    int div(int a, int b)
    {
        if (a>b)
        {
            return 0;
        }
        int ans = 1;

        int tmp = b;
        while(tmp >= INT_MIN/2 && tmp+tmp>=a)
        {
            ans += ans;
            tmp = tmp + tmp;
        }
        return div(a-tmp, b) + ans;
    }
    int divide(int a, int b) {
        if(a==0)
        {
            return 0;
        }
        if (a == INT_MIN)
        {
            if(b==1)
            {
                return INT_MIN;
            }
            else if(b == -1)    // 结果超限只有这一种情况
            {
                return INT_MAX;
            }
        }
        int ans = 0;
        bool bisless = false;
        // 转为负数
        if(a>0 && b<0)
        {
            bisless = true;
            a = -a;
        }
        else if(a<0 && b>0)
        {
            bisless = true;
            b = -b;
        }
        else if(a>0 && b>0)
        {
            a =-a;
            b = -b;
        }
        ans = div(a, b);
        if(bisless)
        {
            ans = -ans;
        }
        return ans;
    }
};
```