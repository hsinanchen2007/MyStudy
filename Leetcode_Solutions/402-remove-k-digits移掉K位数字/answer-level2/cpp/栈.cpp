### 解题思路
要保证生成的数字最小，那么数字一定是递增的。所以利用栈的思想，依次淘汰。
注意点：如果所给数字已经是递增，那么只需要删除后面的多余的数字即可；
        同时需要考虑前导'0'以及最后删成空字符串的情况。

### 代码

```cpp
class Solution {
public:
   string removeKdigits(string num, int k) {
    string ans("");
    int ansLength = num.size() - k;
    for (int i = 0; i < num.size(); i++) {
        while(! ans.empty() && ans.back() > num[i] && k != 0) {
            ans.pop_back();
            k--;
        }
        ans.push_back(num[i]);
    }
    ans.resize(ansLength);
    while(! ans.empty() && ans.front() == '0') {
        ans.erase(ans.begin());
    }
    return ans.empty() ? "0" : ans;
}
};
```