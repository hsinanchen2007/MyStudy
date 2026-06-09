### 解题思路
执行用时0ms,内存7.8M，生生做成了一个找规律的题
if((cnt1+cnt2)%2 != 0) return -1;
int ans = 0;
ans =(cnt1+1)/2+(cnt2+1)/2;

### 代码

```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.length()!= s2.length()) return -1;
        int cnt1=0,cnt2=0;
        for(int i=0;i<s1.length();++i)
        {
            if(s1[i]== 'x' && s2[i] == 'y')
            {
                cnt1++;
            }
            else if(s1[i] == 'y' && s2[i] == 'x')
            {
                cnt2++;
            }
        }
        if((cnt1+cnt2)%2 != 0) return -1;
        int ans = 0;
        ans =(cnt1+1)/2+(cnt2+1)/2;
        return ans;
    }
};
```