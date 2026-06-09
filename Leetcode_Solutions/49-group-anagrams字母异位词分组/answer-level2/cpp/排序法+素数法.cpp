解法1：本题的关键在于如何判断两个string是异位词，第一种方法是两个词如果经过排序是一样的，则是异位词。有一点有意思，就是存放key-val用的如果是哈希表反而比红黑树要更慢，可能的解释是对于string的散列计算会比较耗时，但是比较比较不耗时。

```cpp

vector<vector<string>> vAns;
unordered_map<string, vector<string>> hmAll;
for (int i = 0; i < strs.size(); i++) {
    string s = strs.at(i);
    sort(s.begin(), s.end());
    hmAll[s].push_back(strs.at(i));
}
for (auto iter = hmAll.begin(); iter != hmAll.end(); iter++) {
    vAns.push_back(iter->second);
}
return vAns;

```

解法2：第二种方法是对每一个字母赋一个素数，用这个代表这个单词的每一个字母的素数做乘积，如果乘积一样则认为是异位词。有一点也比较有趣，在这样解法下，哈希表表现比红黑树表现好很多，可以认为是对double计算散列是容易的，因此哈希表的优势较大。本解法需要注意存储乘积的变量的大小，int和long类型都不足以存放下，我的代码用的是double.

```cpp
vector<vector<string>> vAns;
unordered_map<double, vector<string>>hmAll;
map<char, int> hmNum = {
    {'a',2},{ 'b',3 },{ 'c',5 },{ 'd',7 },{ 'e',11},{ 'f',13 },{ 'g',17 },{ 'h',19 },{ 'i',23 },{ 'j',29 },{ 'k',31 },
    { 'l',37 },{ 'm',41 },{ 'n',43 },{ 'o',47 },{ 'p',53 },{ 'q',59 },{ 'r',61 },{ 's',67 },{ 't',71 },{ 'u',73 },{ 'v',79 },
    { 'w',83 },{ 'x',89 },{ 'y',97 },{ 'z',101 }
};
for (int i = 0; i < strs.size(); i++) {
    double sum = 1;
    for (int j = 0; j < strs.at(i).size(); j++) {
        sum *= hmNum[strs.at(i).at(j)];
    }
    hmAll[sum].push_back(strs.at(i));
}
for (auto iter = hmAll.begin(); iter != hmAll.end(); iter++) {
    vAns.push_back(iter->second);
}
return vAns;
```