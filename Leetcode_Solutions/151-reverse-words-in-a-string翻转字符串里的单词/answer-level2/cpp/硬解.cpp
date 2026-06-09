### 解题思路
暴力硬解思路，特殊情况只有""和" "
速度不太行，但也是个解法

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;

        int len = s.size(); 
        if(!len) return ""; // 如果为空，返回""

        int i = 0;
        while(i<len){ // 遍历字符串s
            if(s[i]==' '){ // 为空就后移
                i++;
            }else{ // 不为空开始录入
                string t;
                while(i<len && s[i]!=' '){ // 注意
                    t+=s[i];
                    i++;
                }
                v.push_back(t); // 结束录入，插入vector
            }
        }

        if(v.empty()) return ""; // 如果s都是空格，vector为空，返回""

        string res;
        for(int i = v.size()-1; i>0; i--){ // 弹出
            res+=v[i];
            res+=' ';
        }
        res+=v[0]; // 最后一个单词单独处理

        return res;
        }
};
```