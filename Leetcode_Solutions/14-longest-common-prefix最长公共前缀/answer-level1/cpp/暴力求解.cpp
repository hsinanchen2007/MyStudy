### 解题思路
暴力求解：先判断数组是否为空，若不为空，以最短字符串长度进行循环，比较每个字符串中的相应字符是否相等，详细解释看注释。复杂度为log(mn) m为最小字符串长度

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string outcome="";
    if(strs.size()==0)
        return outcome;
    int i;
    int counts = strs[0].length();     //将第一个字符串长度
    for(int i=0;i<strs.size();i++)   //得到最小字符串长度
        if(strs[i].length()<counts)
            counts = strs[i].length();
    for(int j=0;j<counts;j++)        //比较每个字符串的前n个字符
    {
        for(i=0;i<strs.size()-1;i++)
        {
            if(strs[i][j]!=strs[i+1][j])  //如果字符之间不相等，结束循环
                break;
        }
        if(i==strs.size()-1)    //如果所有字符串中的相同位置字符都相等，则加入结果字符串中
            outcome += strs[0][j];
        else
            break;       //若不行等，则结束外层循环
    }
    return outcome;
    }
};
```