### 解题思路
找出出现最多的字母，其他字母插空隔离，利用队列模拟转盘。

### 代码

```cpp
class Solution {
protected:
    static bool Cmp(const pair<char, int> left, const pair<char, int> right)
    {
        return left.second > right.second;
    }
public:
    string reorganizeString(string S) {
        string result;
        if (S.size() == 0) {
            return result;// 判空直接返回
        }
        map<char, int> charBag;
        for (int i = 0; i < S.size(); i++) {
            ++charBag[S[i]];// 按照出现次数缓存map
        }
        vector<pair<char, int>> nodeBag;
        map<char, int>::iterator iter = charBag.begin();
        while (iter != charBag.end()) {
            nodeBag.push_back(make_pair(iter->first, iter->second));// 转存到vector用于排序
            iter++;
        }
        sort(nodeBag.begin(), nodeBag.end(), Cmp);// 按照出现次数降序排列
        pair<char, int> topNode = nodeBag[0];// 记录出现次数最多的字母
        int count = 0;
        for (int i = 1; i < nodeBag.size(); i++) {
            pair<char, int> temp = nodeBag[i];
            count += temp.second;
        }
        // 其他所有字母总和要大于组多字母的数量-1否则直接返回，插空隔离思想
        if (count < topNode.second - 1) {
            return result;
        }
        queue<string> strBag;// 定义转盘队列用于字母拼接
        string dot(1, topNode.first);
        for (int i = 0; i < topNode.second; i++) {
            strBag.push(dot);// 出现最多的字母优先入队
        }
        for (int i = 1; i < nodeBag.size(); i++) {
            int num = nodeBag[i].second;
            string add(1, nodeBag[i].first);
            while (num > 0) {
                string topStr = add + strBag.front();// 其他字母依次与队列里的元素拼接插空，注意add要放到前边
                strBag.pop();
                strBag.push(topStr);
                num--;
            }
        }
        while (!strBag.empty()) {
            result += strBag.front();// 所有隔离的字母拼接出结果
            strBag.pop();
        }
        return result;
    }
};
```