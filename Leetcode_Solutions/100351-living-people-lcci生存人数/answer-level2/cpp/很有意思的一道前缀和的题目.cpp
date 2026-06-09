### 解题思路
很有意思的一道题目

### 代码

```cpp
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        int a[11111]={0};
        int num = 0;
        int ans = 0;
        int sum = 0;
        
        for (int i = 0; i < birth.size(); i++)a[birth[i]]++;//在这个点出生
        for (int i = 0; i < death.size(); i++)a[death[i]+1]--;//在这个点的后一个点才算是真正的死亡
        for (int i = 0; i < 10011; i++)
        {
            sum += a[i];
            if (num < sum)
            {//找最大
                num = sum;
                ans = i;
            }
            //if (a[i]<0)sum += a[i];
        }
        
        return ans;
    }
};
```