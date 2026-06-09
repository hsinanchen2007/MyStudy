### 解题思路
第一个N循环是探索当前的字符串有没有转换的必要，为的是遇到长字符串的时候由于内存超出的问题，第二个循环是返回新建的字符串。

### 代码
![image.png](https://pic.leetcode-cn.com/e64fd8a62ae6035fc6014105905a5acf7d67357792d205daf8b95bb27742388b-image.png)

```cpp
class Solution {
public:
    string compressString(string S) {
        int n=S.size();
        int l=0,r=0;
        int length=0;
        int court=1;
        string ans;
        while(r<n)
        {
            
            if(S[r]!=S[l]) {court=court+1; l=r;}
            if(2*court>=n) return S;
            r=r+1;
        }
        l=0,r=0;
        while(r<n)
        {
            if(S[l]==S[r]){
                if(r==n-1)  ans=ans+S[l]+ to_string(length+1);
                length=length+1;
                r=r+1;
                continue;
            }
            else {
                ans=ans+ S[l]+to_string(length);
                l=r;
                length=0;
            }

        }
        return ans;

    }
};
```