双指针法:
```
var trap = function(height) {
    const length = height.length
    if (length === 0) return 0
    let left = 0
    let right = length - 1
    let floor = 0
    let result = 0
    while (true) {
        if (left >= right) {
            result -= floor
            break
        }
        let leftValue = height[left]
        if (leftValue <= floor) {
            result -= leftValue
            left ++ 
            continue
        }
        let rightValue = height[right]
        if (rightValue <= floor) {
            result -= rightValue
            right -- 
            continue
        }
        let nextFloor = Math.min(leftValue, rightValue)
        result += (right - left + 1) * (nextFloor - floor)
        floor = nextFloor
    }
    return result
};
```