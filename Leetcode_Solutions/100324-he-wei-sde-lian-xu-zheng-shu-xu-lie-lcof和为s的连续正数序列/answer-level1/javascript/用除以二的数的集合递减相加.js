### 解题思路
1. 因为数m的两个连续的加数肯定在[1, m/2]范围内，所以先除以2得到一个范围
2. 假设ceil(m/2)=N, 那么这些加数集合范围肯定在[1, N]以内，所以我们可以从N开始遍历每个数并累加
3. 检查累加的和S,如果S一旦超过target就证明从N开始数的话得到的这个集合不满足要求，故重设指针从N-1再重新遍历
4. 如果等于target，把符合的数字临时数组加入总的结果集合
5. 如果大于小于target，就continue循环，继续累加，并且把累加的结果加入临时数组

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let tmp=0;
    const res=[];
    const tmpArr=[];
    let pointer = Math.ceil(target/2); //获取一个范围，所有和为target的数组必定在这个范围内
    while(pointer>0){
        tmpArr.unshift(pointer);
        tmp+=pointer; //每次循环都把当前元素加入临时数组，并且这些数的和也进行累加
        if(tmp<target){
            pointer--;
            continue; //还没够target，继续累加
        }
        
        if(tmp==target)res.unshift([...tmpArr]); //够target了，把临时数组加入总结果的集合里

        pointer=tmpArr[tmpArr.length-2]; //然后重设指针和临时数组，还有临时累加和
        tmpArr.length=0;
        tmp=0;
    }
    return res;
};
```