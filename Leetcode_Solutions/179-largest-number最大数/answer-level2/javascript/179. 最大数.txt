#### 解法一
+ 拼接对比
+ 结尾判断结果是否是正常的number
```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    nums.sort( (a,b) => {
        let aStr = a + '';
        let bStr = b + '';
        return (b * Math.pow(10,aStr.length) + a) - (a * Math.pow(10,bStr.length) + b);
    })
    return nums.join('').replace(/^0+/,'') || '0';
};
```
#### 解法二
+ 思路
  + 直觉上，构建最大数字，希望越高位的数字越大越好
    + 降序
  + 关键
    + 首先排序原数组
    + 直接在排序时，对比拼接降序的相邻两个元素后的两个值的大小
      + 大的排前面，如30和3
        + 330 > 303 => 3、30
```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    nums.sort((a,b) => {
        let t1 = a + '' + b;
        let t2 = b + '' + a;
        if(t1 < t2) return 1;
        else if(t1 > t2) return -1;
        else return 0;
    })
    let ans = nums.join('');
    return ans[0] === '0' ? '0' : ans;
};
```
#### 解法三
+ 只是把拼接过程换成了map(String)
```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    return nums.map(String).sort((a,b) => (b+a) - (a+b)).join('').replace(/^0+/,'') || '0';
};
```