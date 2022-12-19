### 解题思路
根据string1和string2的字符串长度，可以判断应该在string1上如何操作变成string2。
1. string1长度大于string2长度时候，一定有删除操作，如果删除一个字符后还不匹配，肯定大于一次编辑，返回false
2. string1长度等于string2长度时候，修改一个字符之后，如果后面还有不匹配，则编辑距离大于1
3. string1长度小于string2长度时候，一定有个插入操作，插入一个值后剩余字符串仍然不匹配，则编辑距离大于1
最后特殊化处理，字符串长度差大于1，返回false;

### 代码

```cpp
class Solution {
public:
    bool oneEditAway(string first, string second) {
        int opt; // 1-delete  0-updata 2-insert
        int d = first.size() + second.size() -min(first.size(),second.size()) * 2;
        if(d>1) return false;
        else{
            if(first.size()>second.size()) opt = 1;
            else if(first.size()==second.size()) opt = 0;
            else opt=2;
        }
        int edit_dis = 0;
        for(int i=0,j=0;i<first.size()&&j<second.size();i++,j++){
            if(first[i]!=second[j]){
                edit_dis++;
                if(opt==1)
                {
                    j--;
                }
                if(opt==2)
                {   
                    i--;
                }
            }
        }
        return edit_dis<=1;
    }
};
```