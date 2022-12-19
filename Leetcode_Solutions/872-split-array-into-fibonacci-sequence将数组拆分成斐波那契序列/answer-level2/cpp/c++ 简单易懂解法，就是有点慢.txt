和累加数一样的套路。只不过为了防止溢出，使用了unsigned long long,倒是也能跑过所有用例；
i,j,k指针分别指向三个数的起始索引，i初始化为0，字符串转化为数字，加和判等；若满足所有条件
（1）除了数字0，不能以0开头
（2）各项要小于INT_MAX，不能溢出
（3）第三项等于前l两项之和
程序结尾要注意，如果第三项刚好截止到S末尾索引，则将所有数据push_back进res,否则一次只push_back进第一项，剩余数字递归完成
```
bool dfs(int i, int j, int k, string& num, vector<int>& res)
{
    if (num[i] == '0' && j - i >= 2)    return false;
    if (num[j] == '0' && k - j >= 2)    return false;
    //转换各个下标之间的数据，查看是否越界
    string s1 = num.substr(i, j - i);
    unsigned long long num1 = 0;
    for (int p = 0; p < s1.size(); ++p) {
        num1 = num1 * 10 + s1[p] - '0';
    }
    if (num1 > INT_MAX)    return false;

    //是否满足符合32位整数类型
    string s2 = num.substr(j, k - j);
    unsigned long long num2 = 0;
    for (int p = 0; p < s2.size(); ++p) {
        num2 = num2 * 10 + s2[p] - '0';
    }
    if (num2 > INT_MAX)    return false;
    
    string sum = to_string(num1 + num2);
    unsigned long long sumNum = 0;
    for (int p = 0; p < sum.size(); ++p) {
        sumNum = sumNum * 10 + sum[p] - '0';
    }
    if (sumNum > INT_MAX)    return false;

    if (k + sum.size() - 1 >= num.size())    return false;
    for (int p = k; p <= k + sum.size() - 1; ++p) {
        if (sum[p-k] != num[p])    return false;
    }

    if (k + sum.size() - 1 == num.size() - 1) {
        res.push_back(num1);
        res.push_back(num2);
        res.push_back(sumNum);
        return true;
    }
    //否则，一次只填充一个数
    res.push_back(num1);
    return dfs(j, k, k + sum.size(), num, res);
}
vector<int> splitIntoFibonacci(string S) 
{
    //将S拆分成斐波那契数列，返回vector，必须要符合32位整数类型，要<=2^32-1，res个数要至少3个
    int i = 0;//第一个下标，初始化为0
    vector<int> res;
    for (int j = 1; j <=S.size() / 2; ++j) {
        for (int k = j + 1; k < S.size(); ++k) {
            res.clear();//清理之前错误的res
            if (dfs(0, j, k, S, res)) {
                if (res.size() >= 3)    return res;
            }
        }
    }
    return res;//返回空vector
}
```

