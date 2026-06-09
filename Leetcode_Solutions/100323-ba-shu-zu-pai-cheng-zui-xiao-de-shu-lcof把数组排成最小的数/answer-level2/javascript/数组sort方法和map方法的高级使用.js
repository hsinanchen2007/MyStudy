思路借鉴题解中一大神的，具体解释请看：[大神题解](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/yi-ge-bu-suan-you-mei-de-acjie-by-horizonlc-coding/)
关于sort和map混合的高级使用：
![image.png](https://pic.leetcode-cn.com/1529a9b644aaf075173b0c7a5dc603e66a885fb434e69bc1e8b6f884f4580942-image.png)
```
var minNumber = function(nums) {
    // 先获取最大数值的位数
    const max = Math.max(...nums).toString().length;
    // 用map方法把数组改成 键－值对形式，这样后面可以使用键值获取原数组对值
    let temp = nums.map((el, idx) => {
        let str = el.toString();    
        while(str.length < max) {
            // 把小于最大位数的值用它的第一位补齐
            str += str[0];
        }

        return {index: idx, value: str}
    });
    // 用补齐后所有位数都相同的值排序
    temp.sort((a,b) => {
        let count = a.value - b.value;
        // 这里避免补齐后数值一样
        if(!count) {
            let max;
            if(nums[a.index] > nums[b.index]) {
                max = nums[a.index].toString();
                count = max[max.length-1] - max[max.length-2];
            } else {
                max = nums[b.index].toString();
                count = max[max.length-2] - max[max.length-1];
            }
            
        }
        return count;
    });
    // 再次用map迭代数组
    let res = temp.map(el => {
        // 利用索引获得原始值
        return nums[el.index];
    }).join('');
    return res;
};
```
又在题解里看到了一种贼简单的解法，不得不说，数组的方法学透之后，能用的太多了
具体解释看大神：[炒鸡简单](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/cao-ji-jian-dan-yi-dong-by-delicate-solo/)
```
var minNumber = function(nums) {
    nums.sort((a, b) => {
        a = a.toString();
        b = b.toString();
        if(a+b > b+a) {
            return 1
        } else {
            return -1;
        }
    })
    return nums.join('');
};
```
