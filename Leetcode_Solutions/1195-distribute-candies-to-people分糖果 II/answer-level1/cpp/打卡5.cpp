### 解题思路
简单的暴力模拟，一个一个加过去，到底了就再回到开头继续。知道糖果数量小于等于该次该分结束。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> r(num_people , 0);
        int id = 0;
        int t = 1;
        while(candies){
            if(candies <= t){
                r[id] += candies;
                break;
            }
            else{
                r[id++] += t;
                candies -= t++;
                id = id % num_people;
            }
        }
        return r;
    }
};
```