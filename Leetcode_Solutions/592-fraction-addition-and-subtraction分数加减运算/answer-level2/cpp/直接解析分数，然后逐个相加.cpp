### 解题思路

比较暴力的方法，解析分数，逐个相加
利用 pair<int, pair<int, int>>来表示一个分数，第一个是符号，后面分别是分子和分母
侥幸双百了

几个注意的点
* 1.注意判断分子，为0的分数，均设置为0/1
* 2.解析分数时候要小心点
* 3.利用辗转相除求最大公约数
* 4.设置了每个分数的符号位，那么分数的分子分母都是正数，写代码时候不要忘记

### 代码

```
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
    string fractionAddition(string expression);
    void parse(const string &expression, int idx, vector<pair<int, pair<int, int>>> &nums);
    pair<int, pair<int, int>> addTwoFraction(const pair<int, pair<int, int>> &lhs, const pair<int, pair<int, int>> &rhs); 
    int getGcd(int a, int b);
    
};

string Solution::fractionAddition(string expression) {
    vector<pair<int, pair<int, int>>> nums;
    parse(expression, 0, nums);
    pair<int, pair<int, int>> sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        sum = addTwoFraction(sum, nums[i]);
    }
    // 构造结果字符串
    string ret;
    if (sum.first == -1)
        ret = "-";
    ret = ret + to_string(sum.second.first) + "/" + to_string(sum.second.second);
    return ret;
}

inline
void Solution::parse(const string &expression, int idx, vector<pair<int, pair<int, int>>> &nums) {
    if (idx >= expression.size())
        return;
    bool positive = true;
    if (!isdigit(expression[idx])) {
        if (expression[idx] == '-')
            positive = false;
        idx++;
    }
    // 解析出一个分数
    int i = idx;
    int x, y;
    while (i < expression.size() && expression[i] != '+' && expression[i] != '-') {
        if (expression[i] == '/') {
            x = stoi(expression.substr(idx, i - idx));
            idx = i + 1;
        }
        i++;
    }
    // idx指向分母的第一个字符，这种情况下是一定存在的，因为/符号后一定有分母
    y = stoi(expression.substr(idx, i - idx));
    nums.push_back({(positive ? 1:-1), {x, y}});
    parse(expression, i, nums);
}


pair<int, pair<int, int>> Solution::addTwoFraction(const pair<int, pair<int, int>> &lhs, const pair<int, pair<int, int>> &rhs) {
    int y = lhs.second.second * rhs.second.second;
    int x = lhs.first * lhs.second.first *rhs.second.second + rhs.first * rhs.second.first * lhs.second.second;
    bool positive = (x > 0);
    x = (x > 0) ? x: -x;
    // 化简分数 (利用辗转相除法找到分子分母的最大公约数)
    // 由于分子x可能为0，导致得到的最大公约数也是0，这时不能除，直接返回一个结果，而分母设置为1即可
    if (!x) {
        return {1, {0, 1}};
    }
    auto gcd = getGcd(y, x);
    return {(positive ? 1 : -1), {x / gcd, y / gcd}};
}

int Solution::getGcd(int x, int y) {
    if (x < y)
        return getGcd(y, x);
    return y == 0 ? x : getGcd(y, x % y);
}
```
![屏幕快照 2020-03-19 下午15.42.10 下午.png](https://pic.leetcode-cn.com/1f555df94f8b7b65f793987e9ce02f8828aca1eb3c6370d9e3931dd88333bb84-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-19%20%E4%B8%8B%E5%8D%8815.42.10%20%E4%B8%8B%E5%8D%88.png)
