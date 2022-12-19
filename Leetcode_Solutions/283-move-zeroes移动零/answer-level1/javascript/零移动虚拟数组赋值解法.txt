1. 新增一个新指针j指向非零数组成的数组（虚拟数组）其实际指向原数组的地址
2. i指针循环原数组，每遇到一个非零数，就往虚拟数组中push，此时实际操作为赋值
3. 判断j指针指向的实际数组的位置是否为0，若为0，则将其移动至非0位置（因为j i指针同时起步，只有遇到0时，j指针停滞不走，故可以通过判断i j是否相等来赋值0）
```
function turnArr(nums) {
    let j = 0
    for (let i = 0, len = nums.length; i < len; i++) {
        if (nums[i] !== 0) {
            nums[j] = nums[i]
            j++
            if (j !== i) { // 等价于nums[j] === 0
                nums[i] = 0
            }
        }
   }
}
```
虚拟数组对应的辅助数组解法
```
function turnArr(nums) {
    let vitualArr = [], count = 0
    for (let item in nums) {
        if (items !== 0) {
            vitualArr.push(item)
            count++
        }
    }
    nums =  virtualArr.splice(count, nums.length - count, 0)
}
```
```
function turnArr(nums) {
    let vitualArr = [], count = 0
    vitualArr = nums.filter(function (item) {
        return item > 0
    })
    nums =  virtualArr.splice(count, nums.length - count, 0)
}
```

