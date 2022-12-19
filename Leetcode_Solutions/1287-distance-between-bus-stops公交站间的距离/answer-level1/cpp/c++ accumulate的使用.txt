### 解题思路
先求全部值的和 `sum`，然后求`start -> destination`的值的总和 `sum1`(保证start小于destination),最后的结果 `min(sum1,sum-sum1)`

### 代码

```cpp
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum=accumulate(distance.begin(),distance.end(),0);
        //保证start小于destination,如果不满足则交换两个值
        if(start > destination){
            start = start - destination;
            destination = start + destination;
            start = destination - start;
        }
        int sum1 = accumulate(distance.begin()+start,distance.begin()+destination,0);
        return min(sum1,sum-sum1);
    }
};
```