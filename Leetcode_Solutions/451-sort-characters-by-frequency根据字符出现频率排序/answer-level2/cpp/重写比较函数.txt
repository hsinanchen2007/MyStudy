### 解题思路
1. 把字符串中的每个字符及其出现的次数存在字典m 中
2. 把字典m中的<key,val>转化成pair 存入vector中
3. 重写sort的比较函数，需要定义为static类型，入参为vector的元素类型，从大到小排序用> ;从小到大排序用<
4. 对vector元素进行排序
5. 根据vector元素出现的顺序分别生成临时子串tmp, 使用string 类的构造函数
6. 将所有tmp接在ret后面，输出

### 代码

```cpp
class Solution {
public:
    static bool compare(const pair <char, int> &a, const pair <char, int> &b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(char c : s) ++m[c];
        vector<pair <char, int>> v;
        for (auto item : m) v.push_back(item);
        sort(begin(v), end(v), compare);
        string ret;
        for (int i = 0; i < v.size(); i++) {
            string tmp(v[i].second, v[i].first);
            ret.append(tmp);
        }
        
        return ret;
    }
};
```