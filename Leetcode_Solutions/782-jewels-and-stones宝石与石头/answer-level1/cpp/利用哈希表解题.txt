题目中说到J字符串是不重复的，那么可以通过建立一个256或者128大小的哈希表作为宝石类型的标记，接着：
1. 遍历J字符串，将宝石类型在哈希表中标记
2. 遍历S字符串，查找对应石头类型是否在哈希表中出现，统计出现个数
```
int NumbersOfJewelInStones(string J, string S)
{
    if (J.length() <= 0 || S.length() <= 0)
        return 0;
    const int ASCNUMBER = 256;
    char jewelMap[ASCNUMBER];
    int count = 0;
    memset(jewelMap, 0, sizeof(jewelMap[0]) * ASCNUMBER);
    for (int i = 0; i < J.length(); i++)
        ++jewelMap[J[i]];
    for (int i = 0; i < S.length(); i++)
        if (jewelMap[S[i]] == 1) ++count;
    return count;

```
时间复杂度为O(n)
空间复杂度为O(k),k为哈希表大小，大小是固定的