代码写出来了，不确定这是不是贪心算法。。。

```
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() == 1) {
            return stones[0];
        }
        int index = 0;  //存第一大、第二大值的下标
        for(int i=0; i<stones.size()-1; i++) {
            int value1 = 0;   //存第一大值
            int value2 = 0;   //存第二大值
            for(int j=0; j<stones.size(); j++) {
                if(stones[j]>value1) {
                    value1 = stones[j];
                    index = j;
                }
            }
            stones[index] = 0;  //最大值去除
            for(int k=0; k<stones.size(); k++) {
                if(stones[k]>value2) {
                    value2 = stones[k];
                    index = k;
                }
            }
            stones[index] = value1 - value2;  //第二大值用第第二大之差代替
        }
        return stones[index];  //除了这个值可能不是0，其他值都为0
    }
};
```
