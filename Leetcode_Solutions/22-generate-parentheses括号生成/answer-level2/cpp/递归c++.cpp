解法：分析可知，第一个总是"(",在逐个生成字符串的过程中，遵循"("的数量大于等于")"的数量的规则添加新的符号。不过事实上超过10就会超时了。

```cpp
vector<string> vTotal;
void generateParenthesis(int n, string s, int iLeft, int iRight) {
    if (iLeft == n && iRight == n) {
        vTotal.push_back(s);
        return;
    }
    if (iLeft != n)
        generateParenthesis(n, s+"(", iLeft + 1, iRight);
    if (iRight < iLeft)
        generateParenthesis(n, s+")", iLeft, iRight + 1);
}
vector<string> generateParenthesis(int n) {
    if (n == 0)return vTotal;
    else
        generateParenthesis(n, "(", 1, 0);
    return vTotal;
}
```