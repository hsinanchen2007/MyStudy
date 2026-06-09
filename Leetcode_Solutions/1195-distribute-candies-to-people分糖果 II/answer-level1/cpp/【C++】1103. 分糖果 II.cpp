### 解题思路

定义一个数组（初始化为全0）用于记录每个小朋友分到的糖果数，定义一个整型count用于计数当前应该分给小朋友多少个糖果。

每一次分糖果后总的糖果数减掉分发掉的糖果数，即为剩下的总糖果数，所以外层循环当糖果数`candies == 0`时退出循环。内层循环遍历每一个小朋友模拟分发糖果的真实情况，如果剩余的糖果数足够，就直接将应分发的count个糖果分发给ans[i]小朋友，即这个小朋友的糖果数+count，并且总的糖果数要减掉已分发出去的count，计数count++即应该分给下一个小朋友的糖果数；如果剩余的糖果数不足，则把剩下的所有糖果都分给这个小朋友，并将剩下的糖果数count置为0以跳出外层循环。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int count = 1;//当前应分发的糖果数
        while (candies != 0)
        {
            for (int i = 0; i < num_people; i++) {
                //糖果数目已不足够，剩下的全部糖果都分给这个小朋友
                if (candies < count) {
                    ans[i] += candies;
                    candies = 0;
                }
                //糖果数目足够
                else {
                    ans[i] += count;
                    candies -= count;
                    count++;
                }
            }
        }
        return ans;
    }
};
```