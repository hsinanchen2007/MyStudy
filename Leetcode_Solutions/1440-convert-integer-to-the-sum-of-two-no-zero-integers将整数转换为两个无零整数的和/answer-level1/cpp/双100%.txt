![image.png](https://pic.leetcode-cn.com/b69da01354d8b1ddbc568f275204be919c4b1586f3b6643cc24866a2a12ba6df-image.png)

```
class Solution {
public:
    int countZeros(int num)
    {
        int cnt = 0;
        while(num>0)
        {
            if(num%10==0) cnt++;
            num/=10;
        }
        return cnt;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        int num1 = 0, num2 = 0;
        while(num1 <= n / 2)
        {
            num1++;
            num2 = n - num1;
            if(countZeros(num1) == 0 && countZeros(num2) == 0)
            {
                res.push_back(num1);
                res.push_back(num2);
                break;
            }
        }
        return res;
    }
};
```