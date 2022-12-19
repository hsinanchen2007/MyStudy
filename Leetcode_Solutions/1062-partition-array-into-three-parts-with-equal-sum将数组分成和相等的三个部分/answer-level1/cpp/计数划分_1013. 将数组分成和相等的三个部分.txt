### 解题思路
    /*
     * 因为是等分为三部分，所以可以先将整个数组的总和sumA求出，
     * 再除以3求每个部分的和sumPart，如果都不能整除3直接返回false。
     * 再遍历数组，同时对数值进行累加，判断累加和是否为sumPart，
     * 如果等于sumPart，则累加和sumTemp归0，重新开始一轮累加。
     * 设置计数器count，因为是分成三组，那么累加和等于sumPart的次数肯定等于3。
     * 但例如[10,-10,10,-10,10,-10,10,-10]这种情况时，count等于4，
     * 所以需要修改计数器次数应大于等于3。
     * */
### 代码

```cpp
bool canThreePartsEqualSum(std::vector<int> &A) {
    if(A.empty()){
        return false;
    }

    int sumA = 0, sumPart = 0, sumTemp = 0;
    
    // 求数组的总和
    for(int i = 0; i < A.size(); i++){
        sumA += A[i];
    }
    
    // 求每个部分的和
    if(sumA % 3 == 0){
        sumPart = sumA / 3;
    }else{
        return false;
    }

    // 计数划分组数
    int count = 0;
    for(int a : A){
        // 每部分的累加和
        sumTemp += a;
        
        // 判断是否到每部分和
        if(sumTemp == sumPart){
            count++;
            sumTemp = 0;
        }
    }
    
    // count >= 3是处理总和为0情况下，计数超过3
    return sumTemp == 0 && count >= 3;
}
```