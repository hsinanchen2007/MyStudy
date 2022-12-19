

**ps：i表示每个字符串对应的同一个索引，j表示对应第几个字符串,只有所有元素都是共有的才能执行完循环到最后一步，即可返回任意的字符串**
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            if(strs.size()==0)          return "";

            for(int i=0;i<strs[0].size();i++)
                for(int j=1;j<strs.size();j++)   
                    if(strs[j][i]!=strs[0][i])           
                        return strs[0].substr(0,i);        
                    //substr取前i个元素，因为终止循环的索引i对应的是第i+1个元素不是共有的,所以前i个元素是共有前缀
            return strs[0];
    }
};
```