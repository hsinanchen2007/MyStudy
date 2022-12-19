### 解题思路
看了官方题解，自己写的
定义左侧，右侧，l,r  1,2
计算l ~ r 的和
* < target l不变，r可以向右扩展
* = target 则l r组合正确，而且l开头的组合就这一个保存并且l + 1，r + 1。 
l+1 r 的组合肯定小于target。l最远能到target / 2中间

* 大于target 则l 开头没有正确组合， l + 1, r不变
当l > target / 2 或l >= r时结束循环，返回结果

### 代码

```javascript

/*
* 滑动窗口 
定义左侧，右侧，l,r  1,2
计算l ~ r 的和，< target l不变，r可以向右扩展
= target 则l r组合正确，而且l开头的组合就这一个保存并且l + 1，r + 1。 
    l+1 r 的组合肯定小于target。l最远能到target / 2中间
>target 则l 开头没有正确组合， l + 1, r不变
当l > target / 2 或l >= r时结束循环，返回结果

* @param {number} target
* @return {number[][]}
*/
var findContinuousSequence = function(target) {
    let result = [];
    if(target === 1) return result;
    let l = 1;
    let r = 2;

    let sum = 0;
    let mid = Math.ceil(target / 2);
    while(l < mid && l < r) {
        sum = (l + r) * (r - l + 1) / 2;
        if(sum < target) {
            r++;
        } else if(sum === target) {
            let array = [];
            for(let index = l; index <= r; index++) {
                array.push(index);
            }
            result.push(array);

            l++;
            r++;
        } else {
            l++;
        }
    }

    return result;
}
```