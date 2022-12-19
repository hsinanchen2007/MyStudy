### 解题思路
1.找最短的字符串min
2.比较子串组的每个子串与 min的每个字符 ————所有双层for循环
  所有相等则res+；不等则就是结果
所以相等指的是在内层一轮循环结束可以res+，
内层用于 if(strs[j][i]!=min[i])  return res;来剔除不等的情况

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string min=strs[0];
        for(int i=1;i<strs.size();i++){
            if(strs[i].size()<min.size()){
    
                min=strs[i];
            }
        }
        string res="";
        for(int i=0;i<min.size();i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=min[i])  return res;
            }
            res+=min[i];
        }
        return res;
    }
};
```