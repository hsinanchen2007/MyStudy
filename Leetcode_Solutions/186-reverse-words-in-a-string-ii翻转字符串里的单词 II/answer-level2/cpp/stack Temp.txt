### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/dc06189fee0dbea6d0f4b7fe79c7b7947db7bf32a8b2903e6dbdc3bd6f160592-image.png)

### 代码

```cpp
class Solution {
public:
    void reverseWords(vector<char>& s) {
        stack<string> sTemp;
        string temp = "";
        for(char &x : s) {
            if (x != ' ') {
                temp+=x;
            }else {
                sTemp.push(temp);
                temp.clear();
            }
        }
        sTemp.push(temp);
        s.clear();
        while(!sTemp.empty()) {
            temp = sTemp.top();
            sTemp.pop();
            for(char &x : temp) {
                s.emplace_back(x);
            }
            s.emplace_back(' ');
        }
        s.pop_back();
    }
};
```