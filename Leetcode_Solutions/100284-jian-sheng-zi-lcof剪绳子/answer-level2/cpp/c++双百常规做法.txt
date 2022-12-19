### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int sub(int n,int part)
    {
        return n/part;
    }
    int cuttingRope(int n) 
    {
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