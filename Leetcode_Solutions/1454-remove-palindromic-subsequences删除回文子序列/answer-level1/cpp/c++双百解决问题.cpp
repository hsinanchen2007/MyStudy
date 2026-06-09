### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/57df7579b0a5f1ce57df1a435ccd930a8550e2cd5d49323324f19b636d867d4e-image.png)

### 代码

```cpp
class Solution {
public:
    int removePalindromeSub(string s) {
        if(s=="") return 0;
        if(s.size()%2==0)
        {
            int mid1=s.size()/2-1,mid2=s.size()/2;
            while(mid1>=0)
            {
                if(s[mid1]!=s[mid2]) return 2;
                mid1--;
                mid2++;
            }
            return 1;
        }
        int mid1=s.size()/2,mid2=mid1;
        while(mid1>=0)
            {
                if(s[mid1]!=s[mid2]) return 2;
                mid1--;
                mid2++;
            }
            return 1;
    }
};
```