
执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了80.29%的用户
```
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for (auto i : t)  //计算t串的ascii码总值
            sum += i;
        for (auto i : s)  //利用sum减去s串的ascii总值
            sum -= i;
        return sum;
    }
};
```
