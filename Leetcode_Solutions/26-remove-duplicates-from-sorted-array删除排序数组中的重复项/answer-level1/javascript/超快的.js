```
var removeDuplicates = function(nums) {
    let active = 1
    let activeItem = nums[0]
    for (let i=1; i<nums.length;i++) {
        if (activeItem !== nums[i]) {
            nums[active] = nums[i]
            activeItem = nums[i]
            active++
        }
    }
    return active
};
```
不使用数组方法才会快
![712153EE4A792AF671B6C5841B44AF6B.jpg](https://pic.leetcode-cn.com/fb472b6354d48ee0ad702769e6a5df81209061e0edaf1d9dabb3aac8bad90544-712153EE4A792AF671B6C5841B44AF6B.jpg)
