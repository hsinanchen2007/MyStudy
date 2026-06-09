C++ 4MS 9MB 最长公共前缀不会超过最小的字符串
逐个字符判断是否相等。
the end
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return ""; 
        int min1=INT_MAX;
        string a;
        
        for(int i=0;i<strs.size();i++)
        {
            int m=strs[i].size();
            min1=min(min1,m);
        }
        for (int i=0;i<min1;i++){
           for(int k=0;k<strs.size()-1;k++)
           {
               if (strs[k][i]==strs[k+1][i])
                   continue;
               else return a;
           }
            a=a+strs[0][i];
        }
        return a;
    }
};
```
