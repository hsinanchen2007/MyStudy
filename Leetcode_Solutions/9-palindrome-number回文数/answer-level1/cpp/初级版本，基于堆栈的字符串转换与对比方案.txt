### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        stack<char> ss;
        for(auto &n : s) {
            ss.push(n);
        }
        
        string trans;
        while(!ss.empty()) {
            
            trans.push_back(ss.top());
            ss.pop();
        }

        cout << trans << endl;

        return trans == s ? true : false;

        

    }
};
```