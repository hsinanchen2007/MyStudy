### 初始解法，未优化，利用位置索引
&emsp;刚开始看到这个题目，我就想到利用map。但是作为一个偏小白的学生重点是不知道如何把数组中**异位词**比较方便的提取出来。
&emsp;但是，我们可以想到**异位词**就是每个字母数量相同排序不同。
&emsp;$eg: bcba, cabb$
&emsp;人一般都喜欢规整，于是我简单的将其排好，然后便发现了玄机 $-> abbc\;abbc$。
- **异位词在经过排序之后是相同的**
&emsp;解题思路：
- ①首先保留一份拷贝$t$并对数组$strs$中的每个字符串都进行**排序**（现在数组中基本上有重复的字符串，例如从aet, eat -> aet, aet）
- ②维护一个$map$，用于记录每个排序后相同字符串(实际上也就是那些异位词)的位置，**比如**在原数组中eat的索引为1， aet的索引为3，在排序后，我们通过map和遍历把这些索引存储起来，这样在进行遍历后，我们从之前的拷贝数组中利用存储的索引可以直接提取出来。并用数组$words$记录所有排序后相同的字符串。
- ③最后我们通过遍历$words$和之前存储的索引获得我们最终的数组
### 代码
```cpp
class Solution {
    unordered_map<string, vector<int>> m; // used to record location
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        m.clear();
        vector<string> t = strs, words; // t用于拷贝一共strs的副本方便后续遍历， words用于存排序后数组中所有不相同的字符串
        vector<vector<string>> ans;
        for (auto& e : strs) std::sort(e.begin(), e.end()); // 对每个字符串进行排序 eg:eat -> aet
        for (int i = 0; i < strs.size(); ++ i) {
            if (m[strs[i]].empty()) words.emplace_back(strs[i]); // 假如为map空说明这个还没有出现过，记录之
            m[strs[i]].emplace_back(i); // 这里记录的是他在原始数组中的位置i,为了后续可以直接取出来
        }

        for (auto& e : words){
            vector<string> tmp; // 临时开辟一共数组用于暂存字母异位词
            for (auto& v : m[e]){
                tmp.emplace_back(t[v]); // 从之前拷贝的t中利用map存储的loc将其提取出来
            }
            ans.emplace_back(tmp);
        }

        return ans;
    }
};
```


### 优化后，直接利用map存储结果
经过思考，发现第一个方法冗余过多，代码结构不清晰，因此进行了优化，同样利用**异位词在经过排序之后是相同的**这个性质，不同的是，我们在**遍历,排序的过程中同时利用$map$记录异位词**，最后直接遍历$map$，将其$value$值压入数组中，完成代码优化,显然优化后的代码简洁一些。

### 代码

```cpp
class Solution {
    unordered_map<string, vector<string>> m;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for (auto& e : strs){
            string tt = e;
            std::sort(e.begin(), e.end());
            m[e].emplace_back(tt);
        }
        for (auto& e : m){
            ans.emplace_back(e.second);
        }

        return ans;
    }
};
```