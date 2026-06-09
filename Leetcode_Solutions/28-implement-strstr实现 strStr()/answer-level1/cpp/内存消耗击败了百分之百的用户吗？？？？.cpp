### 解题思路
此处撰写解题思路
击败百分之百的用户？？
![1583827638(1).png](https://pic.leetcode-cn.com/836ecf56c73ff5639f3645c68aff060549250c2a738610055d130caa3ef29001-1583827638\(1\).png)
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==""&&needle==""||needle=="")return 0;
        int res=-1;
        int k=0;
        bool flag=true;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[k]){
                if(flag)
                res=i;
                k++;
                flag=false;
            }
            if(k==needle.size()&&(i-res)==needle.size()-1){
                return res;
            }else if(k==needle.size()){
                k=0;
                i=res;
                flag= true;
            }
        }
        return -1;
    }
};
```