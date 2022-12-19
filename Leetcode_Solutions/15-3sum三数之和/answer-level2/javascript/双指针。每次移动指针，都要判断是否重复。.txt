`var threeSum = function(nums) {
    nums = nums.sort((a, b) => a - b);  // 给数组排序
    if(nums.length < 3) return [];  // 数组长度小于3返回空数组
    let res = [];  // 保存的结果
    for(let i = 0; i < nums.length - 2; i++) {  // i右边必须要有两个值
        let left = i + 1,  // 左指针
            right = nums.length - 1;  // 右指针
        if(nums[i] === 0 && nums[left] === 0 && nums[right] === 0) {
            // 当左指针、右指针、i指针都为0时。只存入一个[0, 0, 0]。
            res.push([0, 0, 0]);
            break;
        }
        if(nums[i] === nums[i - 1]) continue;  // i指针的值等于上一个i指针的值，进入下一个循环，避免重复
        while(left < right) {  // 左指针小于有指针时，循环继续
            let result = nums[i] + nums[left] + nums[right];  // 计算出相加的结果
            if(result === 0) {  // result是否为0，是则存入res中。
                res.push([nums[i], nums[left], nums[right]]);
                // 存入后移动指针，继续寻找
                left++;
                right--;
                while(left < right && nums[left] === nums[left - 1]) {
                    left++;  // 当左指针移动后发现与上一个值相同，向右移动，避免重复
                }
                while(left < right && nums[right] === nums[right + 1]) {
                    right--;  // 当右指针移动后发现与上一个值相同，向左移动，避免重复
                }
            } else if(result < 0) {  // result小于0.需要一个更大的左指针。左指针向右移动
                left++;
                while(left < right && nums[left] === nums[left - 1]) {
                    left++;  // 当左指针移动后发现与上一个值相同，向右移动，避免重复
                }
            } else {  // result大于0.需要一个更小的右指针。右指针向左移动
                right--;
                while(left < right && nums[right] === nums[right + 1]) {
                    right--;  // 当右指针移动后发现与上一个值相同，向左移动，避免重复
                }
            }
        }
    }
    return res;
};`