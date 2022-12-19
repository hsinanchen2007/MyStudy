主要是思路的问题，一种是遍历一遍数组,找出与val值相同的数组元素，然后使用splice方法删除。大部分解法都是这样因此就不再写具体代码了。另外一种思路就是直接找到与val值相同的数组元素，进行删除，以下是代码
```
var removeElement = function(nums, val) {
    let tmp;
    while(true) {
        tmp =  nums.indexOf(val);
        if(tmp === -1) {
            break
        } else {
            nums.splice(tmp,1);
        }
    }
    return nums.length;
};
```
