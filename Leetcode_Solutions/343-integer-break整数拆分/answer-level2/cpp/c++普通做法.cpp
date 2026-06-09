### 解题思路
相加组成n的这组数，随着其个数增加，他们的乘积只有一个峰。
那峰的两边肯定单调递减。
从将n对半分开始观察这几个数的乘积，当当前的乘积比刚才的分法乘积小，那刚刚那组分法即峰，直接return。

### 代码

```cpp
class Solution {
public:
    int sub(int n,int part)
    {
        return n/part;
    }
    int integerBreak(int n) {
        int max=1;
        for(int i=2;i<=n;i++)
        {
            int cnt=i;
            int n1=n;
            int mul=1;
            while(cnt>0)
            {
                mul*=sub(n1,cnt);
                n1-=sub(n1,cnt);
                cnt--;
            }
            if(mul>max)max=mul;
            else return max;
        }
        return 0;
    }
};

```