### 解题思路
此处撰写解题思路
利用ES6提供的新数据结构Set,Set时类似于数组的集合，会自动忽略重复的元素，当添加重复元素时，Set的长度size是不变的
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    var s = new Set()//set为自动忽略重复元素
    for(var i in nums){
        let current = s.size//记录当前set的长度
        s.add(nums[i])//遍历数组，将元素添加到s中
        if(s.size == current){//如果有重复的元素添加时，会自动被忽略掉，即s的长度不变
            return nums[i]
        } 
    }
};
```