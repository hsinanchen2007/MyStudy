### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    //特殊的两个
    if(target === 1) return [1];
    if(target === 2) return [2];
    //返回值
    var res = [];
    var i = 1, j = 2;
    var sum = i + j;
    //双指针，保持当前区间和sum在目标和target附近
    while(i < j&&j < ((target>>1)+2)){
        //如果sum > target,前指针后挪一位
        if(sum > target) sum -= i++;
        //如果sum = target,保存结果,前指针后挪一位
        else if(sum === target){
            let tmp = [];
            let k = 0;
            for(k = i; k <= j;k++){
                tmp.push(k);
            }
            res.push(tmp);
            sum -= i++;
        }
        //如果sum < target,后指针后挪一位
        else sum += ++j;
    }
    return res;
};
```