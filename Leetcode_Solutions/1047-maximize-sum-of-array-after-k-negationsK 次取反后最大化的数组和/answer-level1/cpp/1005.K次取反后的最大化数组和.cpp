### 解题思路
此处撰写解题思路

### 代码

```cpp
#include <algorithm>

bool compare_np_abs(int a, int b)
{
    if(a <0 && b < 0)
    {
        return a > b;
    }
    else
    {
        return a < b;
    }
}

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int negCnt = 0;
        bool isZero = false;
        for(vector<int>::iterator ite = A.begin(); ite != A.end(); ++ite)
        {
            if(*ite >= 0)
            {
                if(0 == *ite)
                {
                    isZero = true;
                }
            }
            else
            {
                negCnt++;
            }
        }

        int sum = 0;
        if(K > negCnt)
        {
            //以绝对值高低排序-- :根本不需要排序，只需要select出绝对值最小的
            int minElement = INT_MAX;
            for(vector<int>::iterator ite = A.begin(); ite != A.end(); ++ite)
            {
                if(abs(*ite) < minElement)
                {
                    minElement = abs(*ite);
                }
                sum += abs(*ite);
            }

            if((K-negCnt)%2 == 1 )
            {
                sum -= 2* minElement;
            }
        }
        else
        {
            //return 13;
            //以-1 -2 -3 0 1 2 3排序
            //-1 -3 -4 2 5
            sort(A.begin(), A.end(), compare_np_abs);
            for(vector<int>::iterator ite = A.begin(); ite != A.end(); ++ite)
            {
                if(distance(A.begin(), ite) < (negCnt-K))
                {
                    sum += *ite;
                }
                else{
                    sum += abs(*ite);
                }
            }

        }
        return sum;
    }
};
```