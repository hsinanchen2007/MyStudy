### 解题思路
两层循环嵌套解题，踩坑好几次才解出来，都在代码中的注释中写出来了。
输入为空的判断不加的话会出现以下错误：
    Line 923: Char 34: runtime error: reference binding to null pointer of type 'struct value_type' (stl_vector.h)
耽误了好长时间才解出来。。。
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) //一定要加这个输入为空的判断
            return "";
        string ans=strs[0];
        for (int i=0; i<strs.size()-1; i++){
            int j=0; 
            int bounder=ans.size()<strs[i+1].size()?ans.size():strs[i+1].size(); //循环边界值
            for (; j<bounder; j++){
                if (ans[j]==strs[i+1][j])
                    continue;
                break;
            }
            ans=ans.substr(0,j); //要系诶在第二个for循环之外，如果写在里面，请考虑{"aa","aa"}的情况
        }
        return ans;
    }
};
```