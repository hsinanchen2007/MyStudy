刚入手数据结构与算法，新手解法，只求AC，算是记录一下。思路：将数组中其他字符串的前i个字符组成的子串与第0个字符串的前i个字符组成字串比较，相等则继续比较，不相等则标志flag为false，跳出循环，返回相等的字串。
**代码**
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int size = strs.size();
        int m = strs[0].size();
        bool flag=true;
        int i;
        for(i =1;i<=m;i++){
            for(int j=1;j<size;j++){
                if(strs[j].substr(0,i)!=strs[0].substr(0,i)){
                    flag=false;
                    break;    
                } 
                else
                    continue;
            }
            if(flag==false)
                break;    
        }
        if(i==1)
            return "";
        else
            return strs[0].substr(0,i-1);    
    }
};
```

