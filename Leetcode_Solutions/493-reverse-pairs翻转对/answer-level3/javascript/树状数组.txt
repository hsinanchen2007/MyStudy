```
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
    const nums_copy = [...nums]
    nums_copy.sort((a, b) => a - b)
    const n = nums.length
    const bit = new Array(n + 1).fill(0)
    let ans = 0
    let i = 0
    while(i < n) {
        // 查询时， bit里存放的都是nums数组中下标在我前面的数的统计信息
        // 查询到的就是nums数组中下标在我前面但是比我两倍大的数的数量
        const index1 = b_sort(nums_copy, nums[i] * 2 + 1)
        const index2 = b_sort(nums_copy,  nums[i])
        ans += get(bit, index1 + 1)
        update(bit, index2 + 1, 1)
        i++
    }
    return ans
};

// 树状数组， 每一个位置存放从结尾到当前位置位置有多少个元素
function get(bit, index) {
    let count = 0
    while(index < bit.length) {
        count += bit[index]
        //每次index二进制表示时末尾的加一个1
        index += (index & -index)
    }
    return count
}

// 每次更新从当前位置开始到下标0的值
function update(bit, index, val) {
    while(index > 0) {
        bit[index] += val
        // 末尾去一个1
        index -= (index & -index)
    }
}

function b_sort(arr, num) {
    let l = 0
    let r = arr.length
    while(l < r) {
        const mid = Math.floor((l + r) / 2)
        if(arr[mid] < num) {
            l = mid + 1
        } else if(arr[mid] > num) {
            r = mid
        } else return mid
    }
    return l
}
```
