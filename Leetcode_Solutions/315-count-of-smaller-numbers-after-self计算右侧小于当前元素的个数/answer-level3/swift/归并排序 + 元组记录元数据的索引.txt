
1. 对输入数组进行归并排序。
2. 在排序过程中，左数组的数据copy到临时数组时，计数rightIndex-middle-1，这里的时间复杂度会低，因为不用逐个迭代累加，直接通过计算求得。

```
class Solution {
     var index315:[Int]!
    func countSmaller(_ nums: [Int]) -> [Int] {
        if nums.count == 0 {
            return []
        }

        index315 = Array<Int>(repeating: 0, count: nums.count)
        var x: [(Int,Int)] = Array<(Int,Int)>(repeating: (0,0), count: nums.count)
        for i in 0...nums.count-1 {
            x[i] = (i,nums[i])
        }
        var tempArr = Array<(Int,Int)>(repeating: (0,0), count: x.count)
        sortSplit315(&x, 0, nums.count-1, &tempArr)
        return index315
    }
    
    func sortSplit315(_ nums: inout [(Int,Int)], _ begin:Int,_ end:Int, _ temp:inout [(Int,Int)]) {
        if begin < end {
            let middle = (begin + end) >> 1
            sortSplit315(&nums, begin, middle, &temp)
            sortSplit315(&nums, middle+1, end, &temp)
            mergeArr315(&nums, begin, middle, end, &temp)
        }
    }
    func mergeArr315(_ nums: inout [(Int,Int)], _ begin:Int, _ middle:Int, _ end:Int, _ tem:inout [(Int,Int)]) {
//        print("merge [\(begin),\(middle)]--[\(middle+1),\(end)]")
        var leftIndex = begin
        var rightIndex = middle+1
        var temIndex:Int = 0
        while leftIndex <= middle && rightIndex<=end {
            if nums[leftIndex].1 <= nums[rightIndex].1 {
                index315[nums[leftIndex].0] += rightIndex-middle-1
                tem[temIndex] = nums[leftIndex]
                temIndex += 1
                leftIndex = leftIndex+1
            } else {
//                for i in leftIndex...middle {
//                    index315[nums[i].0] += 1
//                }
                tem[temIndex] = nums[rightIndex]
                temIndex += 1
                rightIndex += 1
            }
        }
        while leftIndex <= middle {
            index315[nums[leftIndex].0] += rightIndex-middle-1
            tem[temIndex] = nums[leftIndex]
            temIndex += 1
            leftIndex += 1
        }
        while rightIndex <= end {
            tem[temIndex] = nums[rightIndex]
            temIndex += 1
            rightIndex += 1
        }
        
        for i in 0...end-begin {
            nums[begin+i] = tem[i]
        }
    }
}
```
