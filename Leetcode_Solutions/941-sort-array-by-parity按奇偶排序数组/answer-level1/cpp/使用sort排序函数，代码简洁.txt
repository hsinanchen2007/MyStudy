借助C++库函数sort，自定义比较函数，如果数字a,b分别是偶数和奇数时，将a放在b之前，否则，将a放在b之后；
最后，将排序好的数组返回。

```
const int EVEN_NUM = 2;
class Solution {
public:
    static bool Compare(int &a, int &b)
    {
        if (a % EVEN_NUM == 0 && b % EVEN_NUM != 0) {
            return true;
        }
        return false;
    }

    vector<int> sortArrayByParity(vector<int>& A) 
    {
        sort(A.begin(), A.end(), Compare);

        return A;
    }
};
```
