### 思路
1. 排序，然后相同的数字就会挨在一起
2. 使用一个标准值，当新值比标准值大，就更新标准值。
    21. 因为只能做加一操作，所以空着的数就跳过了
3. 当新值小于标准值时，说明这一段连续的数值中有重复的出现了，标准值会提醒他应该增加多少

### 答题
```C++ []
int minIncrementForUnique(vector<int>& A)
{
    if (A.empty()) return 0;
    sort(A.begin(), A.end());
    int ans = 0;
    int st = A[0];
    for (int i = 0; i < A.size(); i++)
    {
        st = max(st, A[i]);
        ans += (A[i] < st) ? st - A[i] : 0;
        st++;
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

