### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(),i=n-1,ans=0,j;
        if(n==0)
            return n;

        while(i>=0  && s[i]==' '  )
        {
            i--;
        }
//cout <<"i="<<i<<endl;
        j=i;
        while(j>=0 && s[j]!=' ' )
            j--;

///cout<<i<<" "<<j<<endl;
        ans=i-j;
        return ans;
    }
};
```