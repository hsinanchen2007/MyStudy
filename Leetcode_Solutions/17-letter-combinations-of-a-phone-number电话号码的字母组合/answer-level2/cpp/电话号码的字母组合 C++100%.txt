### 解题思路
此处撰写解题思路
思路很简单，就是一个字母一个字母处理，不明白为什么是中等难度
### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length=(int)digits.size();
        vector<string> s;
        if(length==0) return s;
        s={""};//初始化处理
        vector<string> temp;
        char i;
        for(char c:digits){//按字母进行迭代
            temp=s;
            s.clear();
            for(string a:temp){//简单的数学计算，自己看看
                i=(c-'2')*3+'a';
                if(c>='8') i++;
                s.push_back(a+i);
                i++;
                s.push_back(a+i);
                i++;
                s.push_back(a+i);
                if(c=='7'||c=='9'){
                    i++;
                    s.push_back(a+i);
                }
            }
        }
        return s;
    }
};
```