# 解题思路
在题目中的每一个字母选项，我们可以视为一个字母的集合，求出字符串的备选项，就是求集合之间的笛卡尔积。
## 笛卡尔积数学定义
集合A, B的笛卡尔积的定义为: A × B = { (x, y) | x ∈ A ∧ y ∈ B }
## 示例解释
X = {'a', 'b', 'c'}, Y = {'d'}, Z = {'e', 'f'}
X × Y = {"ad", "bd", "cd"}
X × Y × Z = (X × Y) × Z = {"ade", "adf", "bde", "bdf", "cde", "cdf"}
## 算法1. 集合的笛卡尔积
### 步骤一. 生成集合
逐字符读取字符串，如果读取到'{'，则创建及一个新的集合，将读取到的小写字母加入集合中，直到读取到'}'为止；
如果读取到小写字母，则直接创建一个新集合，并将读取到的小写字母加入到集合中；
我们需要记录集合中元素的个数，一边后续使用。
### 步骤二. 笛卡尔积
我们为每一个集合建立一个索引，初始化为0。我们使用每个集合中索引为0的字符建立一个字符串，随后最后一个集合的索引+1；
每当集合的索引+1后于集合元素个数相等时，前一个集合的索引+1，此集合索引初始化为0；
直到第一个集合的索引在+1后与集合元素个数相等时，完成全部字符串生成。
## 代码
```cpp
class Solution {
private:
    vector<pair<vector<char>, int>> GenerateSets(string S) {
        vector<pair<vector<char>, int>> charSet;
        vector<char> oneSet;
        for (string::iterator ch = S.begin(); ch != S.end(); ch++) {
            oneSet.clear();
            if (*ch == '{') {
                ch++;
                while (*ch != '}') {
                    if (*ch >= 'a' && *ch <= 'z') {
                        oneSet.push_back(*ch);
                    }
                    ch++;
                }
            }
            else if (*ch >= 'a' && *ch <= 'z') {
                oneSet.push_back(*ch);
            }
            charSet.push_back(make_pair(oneSet, oneSet.size()));
        }
        return charSet;
    }
public:
    vector<string> expand(string S) {
        vector<pair<vector<char>, int>> charSets = GenerateSets(S);
        vector<string> ans;
        int n = charSets.size();
        int pos[n] = {0};
        string tmp;
        while (pos[0] != charSets[0].second) {
            tmp = "";
            for (int i = 0; i < n; i++) {
                tmp += charSets[i].first[pos[i]];
            }
            pos[n - 1]++;
            for (int j = n - 2; j >= 0; j--) {
                int l = charSets[j + 1].second;
                pos[j] += pos[j + 1] / l;
                pos[j + 1] %= l;
            }
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

## 运行结果
![lihaihai.PNG](https://pic.leetcode-cn.com/e19c150e1b7ffbd4aa874f2e1c7534126d7cf975fd83e57c0eb480e9b99de1f3-lihaihai.PNG)
