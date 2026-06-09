
var removeDuplicates = function(nums) {
    let map = new Map()
    for (let i = 0; i < nums.length; i++) {
        if (!map.has(nums[i])) {
            map.set(nums[i], nums[i])
        } else {
            nums.splice(i, 1)
            i--
        }
    }
}