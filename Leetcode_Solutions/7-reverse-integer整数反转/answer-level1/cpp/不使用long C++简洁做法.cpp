
一开始看到很多高赞答案使用long甚至long long 通过了题目，但是仔细审题后发现只能开辟空间到int，因此重新优化题目。
```C++
class Solution {
public:
    int reverse(int x) {
    if(x == INT_MIN) return 0;
    int flag = 1;
    if(x < 0) flag = -1;
    x = abs(x);
    string s = to_string(x);
    for(int i = 0, j = s.size() - 1; i<j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    int res = 0;
    int delta; 
    for (auto num : s)
    {
        if(res > INT_MAX/10) return 0;
        delta = num - '0';
        res = res * 10 + delta;
    }
    return (int)res * flag;
    }
};

```