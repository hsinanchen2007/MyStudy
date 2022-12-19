跳过前面相同部分，比较两个单词不同的地方，注意点在注释中

```
class Solution {
    unordered_map<char, int> hash;

    bool checkOrder(string& a, string& b) {
        int len = min(a.size(), b.size()); // 取公共长度
        int i = 0;
        while (i < len && a[i] == b[i]) ++i; // 跳过前面字母相同的部分 
        if (i < len) return hash[a[i]] < hash[b[i]]; // 如果公共部分存在不相同的字母，则比较位置关系

        // 如果不存在公共部分，则比较单词长度。例如：apple，app
        return a.size() <= b.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.empty() || order.empty()) return false;

        // 将字母位置存入hash表，节省后续查找时间
        for (int i = 0; i < order.size(); ++i) hash[order[i]] = i;

        // 一组数组中，如果所有相邻的单词有序，那么整个数组也是有序的
        for (int i = 1; i < words.size(); ++i)
            if (!checkOrder(words[i - 1], words[i])) return false;
        
        return true;
    }
};
```
