```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    // Re-Order
    nums.sort((a, b) => a-b)
    // Processing
    let nearestSum = nums[0]+nums[1]+nums[2]
    const end = nums.length-2
    for (let i=0; i<end; i++) {
        // Current Number
        const base = nums[i]
        // DoublePointer to find other numbers
        let leftPointer = i+1
        let rightPointer = nums.length-1
        do {
            const prevSum = nearestSum
            const leftItem = nums[leftPointer]
            const rightItem = nums[rightPointer]
            const currentSum = base + leftItem + rightItem
            if (Math.abs(currentSum-target)<Math.abs(nearestSum-target)) {
                nearestSum = currentSum
            }
            if (currentSum<=target) {
                leftPointer++
            } else {
                rightPointer--
            }
        } while(leftPointer<rightPointer)
    }
    return nearestSum
};
```
