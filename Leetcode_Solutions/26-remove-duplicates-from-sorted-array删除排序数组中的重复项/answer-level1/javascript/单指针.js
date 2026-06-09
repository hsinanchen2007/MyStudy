```
var removeDuplicates = function(nums) {
    if(nums.length<2) return nums.length
    //已遍历节点
    let index = 0
    //上一节点
    let node = null
    while(nums[index]!=undefined){
        if(node!=nums[index]){
            node = nums[index]
            index++
        }else{
            nums.splice(index,1)
        }
    }
    return nums.length

};
```
1.当节点小于2时，返回当前长度
2. 指针index记录已去重节点
3. node代表去重之后的最后一个节点
4. 终止条件为当前指针指向空
5. 当节点重复时，删除后一节点，当节点不重复时，指针后移