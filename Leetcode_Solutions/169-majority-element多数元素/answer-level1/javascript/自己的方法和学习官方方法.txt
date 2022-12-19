/**
 * @param {number[]} nums
 * @return {number}
 */

<!-- 
第一种方法，是我自己想到的方法，通过两次遍力。
第一次遍力是保存数组中出现的次数
第二次遍力是找到次数最多的那个项。
第二种方法是参考官方的思路
先对数组进行排序，升序和降序都可以。
因为众数的数量是大于n/2的，所以中位数肯定就是众数。

个人见解：
官方提供的第二种方法有问题，因为众数并不唯一，也可能存在多个。
比如，数组[1,1,1,1,3,3,3,3,4,5,6],这里的众数其实是两个，1,3 -->


var majorityElement = function (nums) {

    const numsLen = nums.length;
    const repeat = new Map();

    nums.forEach((item) => {

        if (repeat.has(item)) {
            repeat.set(item, repeat.get(item) + 1);
        } else {
            repeat.set(item, 1);
        }

    });
    const arr = [];
    [...repeat].map(([key, value])=>{
        if (value > numsLen / 2) {
            arr.push(key);
        }
    });
    return arr.join(',');

};



var majorityElement = function (nums) {

    const numL = nums.length;
    const arr = nums.sort((a, b) =>  {
        return a - b;
    });
    const index = (numL / 2) >> 0;
    return arr[index];

};

```