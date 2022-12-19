因为python用习惯了，代码一定要简洁易懂短小，如下是c++实现
说实话， 这论坛上 c++的优秀题解是真的少。
之前写python个java，总能看到各种大神的解析，c++就贫瘠的一批。
```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> path;
        unordered_map<char, char> dic = {{'(',')'}, {'{', '}'}, {'[', ']'}};
        for(char c: s){
            if (dic.count(c))
                path.push(c);
            else if (!path.empty() and c == dic[path.top()])
                path.pop();
            else
                return false;
        }
        return path.empty();
    }
};
```
