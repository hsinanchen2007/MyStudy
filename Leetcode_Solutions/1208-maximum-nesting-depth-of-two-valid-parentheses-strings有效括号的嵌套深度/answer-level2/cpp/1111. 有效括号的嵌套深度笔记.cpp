### 解题思路
此处撰写解题思路
1. 这题的难点在理解题目
2. 核心：一个字符串的depth仅取决于其深度最大的那一组嵌套括号，只需要把嵌套括号对半分就行
3. 抽象出来就是 有一个很长很长的有效括号字符串，它的最大深度为5，就可以看作它就是((((())))),那么只需要把奇数个和偶数个的括号分别放到A,B组即可
1. vector<int> ans; 初始化一个空的vector
2. string的遍历
3. 单引号引起的一个字符实际上代表一个整数。双引号引起的字符串，代表的却是一个指向无名数组起始字符的指针。该数组会被双引号之间的字符以及一个额外的二进制为零的字符 '\0' 初始化。
4. vector的push_back函数，尾部增加一个元素

### 代码

```cpp
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // 核心：一个字符串的depth仅取决于其深度最大的那一组嵌套括号，只需要把嵌套括号对半分就行
        int d = 0;
        vector<int> ans;
        for (char& c : seq) {
            if (c == '(') {
                d++;
                ans.push_back(d % 2);
            } else {
                ans.push_back(d % 2);
                d--;
            }
        }

        return ans;
    }
};
```