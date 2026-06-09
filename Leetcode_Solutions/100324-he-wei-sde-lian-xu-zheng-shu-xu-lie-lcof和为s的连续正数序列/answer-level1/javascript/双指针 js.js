### 解题思路
看代码

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    //初始化指向1和2,它们都是向右侧移动
    let l = 1,r = 2;
    const res = [];
    while(l<r){
        //等差数列的求和
        //记录l到r之间所有数字的和，
        let sum = ((l+r) * (r-l+1)) >>> 1;
        if(sum === target){
            let s = new Set();
            for(let i = l; i<=r; i++){
                s.add(i)
            }
            let temp = Array.from(s);
            res.push(temp)
            l++
        }else if (sum < target){
            r++
        }else{
            l++
        }
    }
    return res
};
```