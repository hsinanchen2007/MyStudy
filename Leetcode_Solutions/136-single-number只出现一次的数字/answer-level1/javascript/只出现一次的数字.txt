*法一：排序再循环比较*

排序后只要某一项与它的前一项不同且与它的后一项也不同那它就是唯一项

```js
var singleNumber = function(nums) {
    nums.sort( (a, b) => a - b);
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] !== nums[i-1] && nums[i] !== nums[i+1]) {
            return nums[i]
        }
    }
};
```

*法二：位运算 异或*

1.	交换律：a ^ b ^ c <=> a ^ c ^ b 
2.	任何数于0异或为任何数 0 ^ n => n 
3.	相同的数异或为0: n ^ n => 0 
var a = [2,3,2,4,4]
2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3

原理是将数组中所有数都一起异或之后值相同的项异或为0,0异或那个只出现一次的项结果为那个项本身

```js
var singleNumber2 = function(nums) {
    var result = 0;
    var len = nums.length
    for(let i = 0; i < len; i++) {
        result = result ^ nums[i];
    }
    return result
};
```

