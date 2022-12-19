第一次写题解的小透明
![image.png](https://pic.leetcode-cn.com/ecc9bc114c2521b6d1aa6ecb7c77c150e05d5fd28121cc814a771dc3978a2f17-image.png)
# 解法
    双指针法

# 代码
```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens=s.size();
        int lent=t.size();
       
        
        if(lens>lent)
            return false;
        int j=0;
        for(int i=0;i<lent;i++)
        {
            if(t[i]==s[j])
            {
                j++;
            }

        }
        if(j==lens)
            return true;
        return false;

    }
};
```
