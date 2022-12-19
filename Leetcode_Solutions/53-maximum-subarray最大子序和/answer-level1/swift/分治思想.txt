1. 求整个序列的最大连续子序列，可以分成分别求前后两个小子序列
2. 将前后两部分进行合并，结果可能有3种
    - 前半部分是整个序列的最大子序列
    - 后半部分是整个序列的子序列
    - 前后衔接在一起拼成最大子序列（这块很麻烦，出错很多次）
```
func maxSubArray(_ nums: [Int]) -> Int {
        var subBegin = 0
        var subEnd = 0
        return maxSubArrayDivideAndConquerEditionHelper(nums, 0, nums.count-1, &subBegin,&subEnd)
    }
    
   func maxSubArrayDivideAndConquerEditionHelper(_ nums:[Int],_ begin:Int, _ end:Int,_ subBegin:inout Int, _ subEnd:inout Int) -> Int {
        if begin == end {
            subBegin = begin
            subEnd = begin
            return nums[begin]
        }
        let middle = (begin + end)/2
        if middle == begin || middle == end {
            if nums[begin] > nums[end] {
                if nums[begin] + nums[end] > nums[begin]{
                    subBegin = begin
                    subEnd = end
                    return nums[begin]+nums[end]
                } else {
                    subBegin = begin
                    subEnd = begin
                    return nums[begin]
                }
            } else {
                if nums[begin] + nums[end] > nums[end]{
                    subBegin = begin
                    subEnd = end
                    return nums[begin]+nums[end]
                } else {
                    subBegin = end
                    subEnd = end
                    return nums[end]
                }
            }
        }
        let leftPart = maxSubArrayDivideAndConquerEditionHelper(nums, begin, middle, &subBegin, &subEnd)
        let leftSubBegin = subBegin
        let leftSubEnd = subEnd
        let rightPart = maxSubArrayDivideAndConquerEditionHelper(nums, middle+1, end, &subBegin,&subEnd)
        let rightSubBegin = subBegin
        let rightSubEnd = subEnd
        //尝试将两部分结合,既然是两部分结合，所以必须包含左半部分的最后一个；有半部分的第一个
        var sumCrossTwoParts = 0, crossLeftBegin = 0,crossRightEnd = 0
        var leftDo = false, rightDo = false
        var thisLeftEndSum = 0, maxleft = 0
        for i in 0...middle-begin {
            thisLeftEndSum += nums[middle-i]
            if thisLeftEndSum > maxleft {
                leftDo = true
                crossLeftBegin = middle-i
                maxleft = thisLeftEndSum
            }
        }
        sumCrossTwoParts += maxleft
        
        var thisRightFrontSum = 0, maxright = 0
        for i in middle+1...end {
            thisRightFrontSum += nums[i]
            if thisRightFrontSum > maxright {
                rightDo = true
                crossRightEnd = i
                maxright = thisRightFrontSum
            }
        }
        sumCrossTwoParts += maxright
        
        
        if leftPart > rightPart {
            if leftDo && rightDo && sumCrossTwoParts > leftPart {
                subBegin = crossLeftBegin
                subEnd = crossRightEnd
                return sumCrossTwoParts
            } else {
                subBegin = leftSubBegin
                subEnd = leftSubEnd
                return leftPart
            }
            
        } else {
            if leftDo && rightDo && sumCrossTwoParts > rightPart {
                subBegin = crossLeftBegin
                subEnd = crossRightEnd
                return sumCrossTwoParts
            } else {
                subBegin = rightSubBegin
                subEnd = rightSubEnd
                return rightPart
            }
        }
    }


```
