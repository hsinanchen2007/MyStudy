**N位数的每一位仅与前一位相关，十分适合采用DFS递归方法**

```
int N, K;
vector<int>ans;
void help(int digit) {
    if (int(log10(digit)) + 1 == N) { ans.push_back(digit); return; }//位数达到要求
    int pre = digit % 10;//末位
    if (pre >= K)               help(10 * digit + pre - K);          //左孩子：末位-K
    if (K!=0 && pre + K <= 9)   help(10 * digit + pre + K);          //右孩子：末位+K
}
vector<int> numsSameConsecDiff(int N, int K) {
    if (N == 1) return vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    this->N = N, this->K = K;
    for (int i = 1; i <= 9; i++)
        help(i);
    return ans;
}
```
