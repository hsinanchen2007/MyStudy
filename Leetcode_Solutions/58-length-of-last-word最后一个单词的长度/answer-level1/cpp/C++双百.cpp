### 解题思路
第一个循环删除尾后所有的空格，第二个利用rbegin()迭代求出结果

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int num=0;
        auto it=s.end()-1;
        while(*it==' '){//删除尾后的空格
            s.erase(it,s.end());
            it=s.end()-1;
        }
        for(auto it=s.rbegin();it!=s.rend();++it){
            if(*it!=' ')++num;
            else break;
        }
        return num;
    }
};
```