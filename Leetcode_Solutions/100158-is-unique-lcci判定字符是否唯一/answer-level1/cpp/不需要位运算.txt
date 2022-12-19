### 解题思路
此处撰写解题思路
1.遍历字符串astr
2.若str中存在当前astr字符 return false
3.若不存在把当前astr字符存入str
4.最后返回true
### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        string str;
        for(int i=0;i<astr.size();++i){
            if(str.find(astr[i]) != string::npos) return false;
            str.push_back(astr[i]);
        }
        return true;
    }
};
```