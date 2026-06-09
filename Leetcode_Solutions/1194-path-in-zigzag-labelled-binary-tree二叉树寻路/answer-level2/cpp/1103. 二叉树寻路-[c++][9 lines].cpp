注意转换 label 即可。

```cpp
vector<int> pathInZigZagTree(int label) {
    int level = log(label) / log(2) + 1; // 计算层数
    vector<int> path(level);
    while (label) {
        path[level-1] = label;
        label = pow(2, level) - 1 - label + pow(2, level - 1);  // 计算对称点。比如 4 的对称点是 7，7 的对称点是 4， 5 对应 6
        label >>= 1;
        level--;
    }
    return path;
}
```
