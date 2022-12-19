字符排列是按N字排列的，如这个字符串“LEETCODEISHIRING”，当行数为4点时候是这么排列：
![image.png](https://pic.leetcode-cn.com/0a373082a1cf66bfda564c4304216db92810080f2f26443887007e6b8f2d1c8a-image.png)

我们可以当成多个V字结构来看待：
![image.png](https://pic.leetcode-cn.com/299d1024ed47a5e881c0ef8050764a859ce47c71faab903221041d83f57f6acd-image.png)
假设总行数为n，我们观察发现：
1）每个V字结构可分解为两部分：“|”部分和“/”部分，其中“|”部分最大字符数为n，“/”部分最大字符数为(n - 2)，两部分加起来为(2n - 2)
2）可能存在的V字结构的数量 maxCntV = 向上取整(len(字符串) / (2n - 2))

有这两个数据，我们可以进一步观察
设当前行序号为k (0 <= k < n)，当前的V结构序号为i (0 <= i < maxCntV)，可得出：
1）V字结构“|”部分上每个元素的坐标 f(k, i) = (2n - 2)i + k
2）V字结构“/”部分上每个元素的坐标 f(k, i) = (2n - 2)(i + 1) - k

由此，最终代码为：
```
string convert(string s, int numRows) {
    if (s.size() <= numRows || numRows <= 1) {
        return s;
    }

    // V字结构可容纳的最大字符数
    size_t maxCntV = 2 * numRows - 2;
    // 存在的V字结构的数量
    size_t maxV = (size_t)ceil((double)s.size() / maxCntV);

    stringstream ss;
    for (size_t posRow = 0; posRow < numRows; ++posRow) {
        for (size_t posV = 0; posV < maxV; ++posV) {
            size_t idx = maxCntV * posV + posRow;
            if (idx < s.size()) {
                ss << s[idx];
            }

            // 每个V字结构，只有首行和尾行一个字符
            if (posRow != 0 && posRow + 1 != numRows) {
                idx = maxCntV * (posV + 1) - posRow;
                if (idx < s.size()) {
                    ss << s[idx];
                }
            }
        }
    }
    
    return ss.str();
}
```





