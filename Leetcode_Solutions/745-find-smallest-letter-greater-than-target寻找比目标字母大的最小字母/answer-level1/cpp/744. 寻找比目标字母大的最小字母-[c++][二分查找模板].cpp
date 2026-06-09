
二分模板详解：[点我](https://leetcode-cn.com/problems/binary-search/solution/704-er-fen-cha-zhao-cer-fen-mo-ban-by-ivan_allen/)

- 基于 upperbound 的版本，先查找 target，target 右侧就是解。

```
char nextGreatestLetter(vector<char>& letters, char target) {
    int lo = -1, hi = letters.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1 >> 1);
        if (target >= letters[mid]) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return letters[(++lo)%letters.size()];
}
```

- 基于 lowerbound 的版本，直接查找目标。

```cpp
char nextGreatestLetter(vector<char>& letters, char target) {
    int lo = 0, hi = letters.size();
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (target < letters[mid]) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return letters[lo%letters.size()];
}
```
