### 解题思路
indexes，sources，targets都根据indexes的值从大到小排序，然后就可以从后往前替换S。
从后向前替换是确保未替换的index不变。

### 代码

```cpp
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        if (!S.size() || !indexes.size()) return S;
        qsort(indexes, sources, targets, 0, indexes.size()-1);
        for (int i = 0; i <indexes.size(); ++i) {
            if (S.compare(indexes[i], sources[i].size(), sources[i])) continue;
            S.replace(indexes[i], sources[i].size(), targets[i]);
        }
        return S;
    }

    void qsort(vector<int>& indexes, vector<string>& sources, vector<string>& targets, int left, int right) {
        if (left >= right) return;
        int pos = partition(indexes, sources, targets, left, right);
        qsort(indexes, sources, targets, left, pos-1);
        qsort(indexes, sources, targets, pos+1, right);
    }

    int partition(vector<int>& indexes, vector<string>& sources, vector<string>& targets, int left, int right) {
        int pos = left;
        for (int i = left; i < right; ++i) {
            if (indexes[i] > indexes[right]) {
                swap(indexes[i], indexes[pos]);
                swap(sources[i], sources[pos]);
                swap(targets[i], targets[pos]);
                pos ++;
            }
        }
        swap(indexes[right], indexes[pos]);
        swap(sources[right], sources[pos]);
        swap(targets[right], targets[pos]);
        return pos;
    }
};
```