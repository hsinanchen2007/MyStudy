### 解题思路
执行结果：通过 显示详情 执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
private:
    //返回n的位数
    int CalcNum(int n) 
    {
        int res = 0;
        while (n) {
            n = n / 10;
            res++;
        }
        return res;
    }
    
    //取位数为n，s开头的“顺次数”
    int GetNum(int n, int s) 
    {
        int res = 0;
        while (--n) {
            res = res * 10 + s++;
        }
        if (s > 9) {
            return 0;
        }
        return res * 10 + s;
    }

public:
    vector<int> sequentialDigits(int low, int high)
    {
        int lowNum = CalcNum(low);
        int highNum = CalcNum(high);

        vector<int> res;
        for (int i = lowNum; i <= highNum; i++) {
            for (int j = 1; j < 9; j++) {
                int n = GetNum(i, j);
                if (n >= low && n <= high) {
                    res.push_back(n);
                }
            }
        }
        return res;
    }
};
```