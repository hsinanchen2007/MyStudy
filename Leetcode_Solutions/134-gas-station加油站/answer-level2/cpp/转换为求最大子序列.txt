### 解题思路
子序列定义： 某处开始，直到数列结尾构成的序列。
此题可转换为求最大子序列，当子序列大于等于零，同时总序列和大于等于零，子序列的开始处为汽车始发加油站：
证明： 1) 汽车能到达下一站，要求汽车的gas >= cost
       2) 如果总的gas >= cost，存在某个子序列，使其gas >= cost

### 代码

```cpp
class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0;
    int iMax = 0;
    int num = 0;
    for(int i = 0; i < gas.size(); i++){
        total += gas[i] - cost[i];
        iMax += gas[i] - cost[i];
        if(iMax < 0){
            num = i + 1;
            iMax = 0;
        }
    }
    
    return total >=0 ? num : -1;
}
};
```