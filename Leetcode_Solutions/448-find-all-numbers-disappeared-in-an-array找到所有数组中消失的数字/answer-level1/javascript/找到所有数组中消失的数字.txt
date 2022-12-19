*法一*

```js
var findDisappearedNumbers = function(nums) {
    var n = nums.length;
    var res = [];
    for (let i = 1; i <= n; i++) {
        if (nums.indexOf(i) === -1) {
            res.push(i)
        }
    }
    return res
};
```

*法二*

将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字。
举个例子：

•	原始数组：[4,3,2,7,8,2,3,1] 
•	重置后为：[-4,-3,-2,-7,8,2,-3,-1] 
结论：[8,2] 分别对应的index为[5,6]（消失的数字）

**变换过程：**

|index|num|abs(num)-1|[4,3,2,7,8,2,3,1] 初始数据|   
|---|---|---|---|
| 0  |  4| 3 |[4,3,2,**-7**,8,2,3,1] 
| 1  |  3|2 |[4,3,**-2**,-7,8,2,3,1]
| 2  |  -2| 1 |[4,**-3**,-2,-7,8,2,3,1]
| 3  |  -7| 6 |[4,-3,-2,-7,8,2,**-3**,1]
| 4  |  8| 7 |[4,-3,-2,-7,8,2,-3,**-1**]
| 5  |  2| 1 |[4,**-3**,-2,-7,8,2,-3,-1]
| 6  |  -3 |2 |[4,-3,**-2**,-7,8,2,-3,-1]
| 7  |  -1| 0 |[**-4**,-3,-2,-7,8,2,-3,-1]


```js
var findDisappearedNumbers = function(nums) {
    var len = nums.length;
    var arr = [];
    for (let i = 0; i < len; i++) {
        nums[Math.abs(nums[i])-1] = -Math.abs(nums[Math.abs(nums[i])-1]);
    }
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) {
          arr.push(i + 1);
        }
    }
    return arr
};
```