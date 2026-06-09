### 解题思路
![Snipaste_2020-03-22_23-31-59.png](https://pic.leetcode-cn.com/163e411f0e76656b09577117bb19cae681bf3459eed4ac2a2c9626a23c0f68c9-Snipaste_2020-03-22_23-31-59.png)


### 代码

```cpp
class Solution {
public:
    int reverse(long long x){ 
        if (x == 0)
        {
        return 0;
        }
        else if (x > 0)
        {
            int a = 0;
            int i = 0;
            int num = 0;
            long long sum = 0;
            while (1)
            {
                a = pow(10, i);
                if (x / a < 10 && x / a >= 1)
                {
                    break;
                }
                i++;
            }
            if (x % a == 0)
            {
                return x/a;
            }
            else
            {
                while (i != -1)
                {
                    int k = (x / pow(10,i));
                    x = x - k * pow(10,i);
                    sum += (k * pow (10, num)); 
                    i--;
                    num++;
                }
                if (sum >= -pow(2, 31) && sum <= pow(2, 31) - 1)
                {
                    return sum;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            x = -x;
            int a = 0;
            int i = 0;
            int num = 0;
            long long sum = 0;
            while (1)
            {
                a = pow(10, i);
                if (x / a < 10 && x / a >= 1)
                {
                    break;
                }
                i++;
            }
            if (x % a == 0)
            {
                return -x/a;
            }
            else
            {
                while (i != -1)
                {
                    int k = (x / pow(10,i));
                    x = x - k * pow(10,i);
                    sum += (k * pow (10, num)); 
                    i--;
                    num++;
                }
                if (sum >= -pow(2, 31) && sum <= pow(2, 31) - 1)
                {
                    return -sum;
                }
                else
                {
                    return 0;
                }
            }
        }
    } 
};
```