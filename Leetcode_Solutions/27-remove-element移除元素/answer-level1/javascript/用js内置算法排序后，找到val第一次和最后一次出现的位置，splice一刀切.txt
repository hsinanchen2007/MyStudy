采用语言js，参考了[@stack_pop](/u/stack_pop/)提到的方法
他的方法是先对数组排序，再用indexOf()找到第一次出现的位置在进行重复次数计算并随后通过splice()减去元素

根据他的思路想到lastIndexOf()可以返回一个数组元素最后一次出现的位置，那么可以用splice()直接把这两个位置之间所有的元素一次性删去，相比他的算法又快了一点
代码如下，耗时60ms，空间33.8mb
```
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
nums.sort((a,b) => a -b)                            //先对数组进行排序
    let fidx = nums.indexOf(val);                   //然后先找出该值第一次出现的位置
    let lidx = nums.lastIndexOf(val);               //再找出最后一次出现的位置
    if (fidx != -1) nums.splice(fidx,lidx-fidx+1);  ////直接把包括这两个位置在内的所有值全都删掉即可
    return nums.length;
};
```
