### 解题思路
参考[https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/liang-ge-zhi-zhen-yi-qi-hua-by-loick/](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/liang-ge-zhi-zhen-yi-qi-hua-by-loick/)

参考2[https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/he-wei-sde-lian-xu-zheng-shu-xu-lie-by-duoduolee/]()

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let l = 1;
    let r = 1;
    const result = [];
    let sum = 0
    while(r < target){
        sum = sum + r;
        r = r+1;
        while(sum > target){
            sum = sum-l
            l = l+1;
        }
        if (sum == target){
            let temp = [];
            for(let i = l ; i<r; i++){
                temp.push(i)
            }
            result.push(temp)
        }
    }

    return result;
};
```

```
var findContinuousSequence2 = function(target) {
    //设置两个指针
    let l = 1;
    let r = 2;
    //存储结果
    const result = [];
    while (l<r){
        //当前和，尽量和是偶数
        let sum = ((l+r)*(r-l+1))>>>1;
        //如果目标还是大，让右指针+1
        if(sum<target){
            r++
        }
        //如果目标和sum相同，把l《=r范围添加temp
        else if (sum == target){
            let temp = []
            for(let i=l;i<=r;i++){
                temp.push(i)
            }
            result.push(temp);
        //注意
            l++
        }else{
            l++
        }
    }
    return result;
};
```
