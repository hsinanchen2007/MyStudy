### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {

        vector<int> v(num_people);

        int remain = candies;//剩余糖果数
        int j = 0; //数组下标
        int i = 1; //分发个数
        for(;;)
        {
            if(remain - i < 0) //不比前一次发的糖果多 (包含remain == 0的情况)
            {
                v.at(j) += remain;
                break;
            }
            else //正常发
            {
                v.at(j) += i;
                remain -= i;
                ++i;
                ++j;
                if(j == num_people)
                {
                    j = 0;
                }
            }
        }

        return v;
    }
};
```