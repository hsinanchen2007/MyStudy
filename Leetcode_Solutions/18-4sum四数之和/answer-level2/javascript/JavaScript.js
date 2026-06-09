```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
    // Guards
    if (nums.length<4) return []
    // Processing
    nums.sort((a, b) => a-b)
    // console.log(nums)
    const res = []
    const il = nums.length-4
    const iil = nums.length-3
    let i = 0
    while (i<=il) {
        let ii=i+1 
        while (ii<=iil) {
            const item1 = nums[i]
            const item2 = nums[ii]
            // Double Pointer find rest two numbers
            let leftPointer = ii+1
            let rightPointer = nums.length-1
            do {
                const leftItem = nums[leftPointer]
                const rightItem = nums[rightPointer]
                const sum = item1 + item2 + leftItem + rightItem
                // console.log([item1, item2, leftItem, rightItem], sum)
                if (sum === target) {
                    res.push([item1, item2, leftItem, rightItem])
                    // console.log("MATCHED!")
                }
                if (sum<=target) {
                    // Skip duplicated item
                    while(nums[leftPointer]===nums[++leftPointer]){}
                } else {
                    // Skip duplicated item
                    while(nums[rightPointer]===nums[--rightPointer]){}
                }
            } while (leftPointer<rightPointer)
            // Skip duplicated item
            // console.log("UPDATE SECOND PREFIX")
            while(nums[ii]===nums[++ii]){}
        }
        // Skip duplicated item
        // console.log("UPDATE FIRST PREFIX")
        while(nums[i]===nums[++i]){}
    }
    return res
};
```
