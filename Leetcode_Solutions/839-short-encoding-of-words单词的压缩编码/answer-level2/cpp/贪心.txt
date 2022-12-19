### 解题思路
分析，一个单词可能是另外单词的后缀，因此最长的Word肯定需要在最终的字符串，而较短的word可能是其他word的一部分，显然具有贪心的特征，先按长度排序，取最长的Word合入到最终的字符，然后新加入的word，在已有的字符串中查找，查不到就依次合入到字符串中。

时间：排序nlogn + 合并O(n)
空间：多用了一个字符串S，其实也可以不用，在排序好的容器中遍历，一样可行，用字符串的方式实现更简单。O(n).

知识点：
1、贪心算法
2、sort排序
3、排序自定义比较函数，本例使用了lamda表达式实现，
也可以自定义函数实现。


### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [&](const string &a, const string &b){return a.size() > b.size();});
        string s= words[0] + "#";
        for (auto w : words){
            if (s.find(w + "#") == string::npos){
                s += w + "#";
            }
        }
        return s.size();
    }
};
```