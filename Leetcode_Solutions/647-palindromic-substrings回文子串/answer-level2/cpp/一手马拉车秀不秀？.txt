### 解题思路
终于学会马拉车了哈哈

### 代码

```cpp
class Solution {
public:
    int countSubstrings(string str) {
        int i,j,mx,n=str.size();
        string s="@#";
        for(i=0;i<n;i++){
            s+=str[i];
            s+="#";
        }//预处理
        n=s.size();
        vector<int>p(n);
        j=mx=0;
        for(i=1;i<n;i++){
            p[i]=mx>i?min(p[2*j-i],mx-i):1;//在以j为中心的回文串内,2*j-i与i对称
            while(s[i+p[i]]==s[i-p[i]])p[i]++;//半径还可能更大，继续增加
            if(mx<p[i]+i){
                mx=p[i]+i;
                j=i;
            }//如果最大右边端点比此时右边端点小，更新,j变为新的长回文串中心
        }
        j=0;//数量初始化0
        for(i=1;i<n;i++)j+=p[i]/2;//回文串数量等于扩展的半径/2
        return j;
    }
};
```