在118题解基础上优化即可
```
std::vector<int> Solution::getRow(int rowIndex) {
    std::vector<int> ret(rowIndex+1, 1);
    for (int i = 1; i < rowIndex + 1; ++i) {
        for (int j = i - 1; j > 0; --j) {
            ret[j] = ret[j-1] + ret[j];     // 注意此处倒序覆盖即可
        }
    }
    return ret;
}
```
