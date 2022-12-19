### 解题思路
左边是偶数，右边是奇数  类似快速排序的partition 规则换成了奇偶而已

### 代码

```cpp
class Solution {
public:
    //1、
    vector<int> sortArrayByParity(vector<int>& A) {
        
        if (A.size() <= 1)
            return A;

        int even = -1; //偶数区域

        for (int i = 0; i < A.size(); ++i)
        {
            if (A.at(i) % 2 == 0) //偶数
            {
                swap(A.at(i), A.at(++even));
            }
        }

        return A;
    }

    //2
    vector<int> sortArrayByParity(vector<int>& A) {

        if (A.size() <= 1)
            return A;

        int even = -1; //偶数区域
        int odd = A.size(); //奇数区域

        int i = 0;

        while (i < odd)
        {
            if (A.at(i) % 2 == 0) //偶数
            {
                swap(A.at(i), A.at(++even));
                ++i;
            }
            else //奇数
            {
                swap(A.at(i), A.at(--odd));
            }
        }

        return A;
    }
};
```