1. 通过递归函数查找子集相等的情况，用到了数据记忆记录已知结果
2. 分割后的子集相等，所以数组的和不能是奇数
```
class Solution {
   func canPartition(_ nums: [Int]) -> Bool {
        var sum:Int = 0
        for item in nums {
            sum = sum+item
        }
       if sum % 2 == 1 {
            return false
        }
        var arrMemory:[String:Bool] = [:]
        return helper416(0, sum, 0, nums, &arrMemory)
    }
    /*
     从下标index开始 找出sum与subSum相等
     */
    func helper416(_ index:Int,_ sum:Int, _ subSum:Int, _ nums:[Int], _ arrMemory:inout [String:Bool]) -> Bool {
        let key = "\(index)\(sum)\(subSum)"
        if arrMemory[key] != nil {
            return arrMemory[key]!
        }
        var r = false
        if index == nums.count || subSum > sum {//没有元素了
            r = false
        } else {
            if nums[index]+subSum == sum-nums[index] {//找到等和子集
                r = true
            } else {
                r = helper416(index+1, sum-nums[index], subSum+nums[index], nums,&arrMemory)//把当前元素插入到子集
                if r == false {
                    r = helper416(index+1, sum, subSum, nums,&arrMemory)
                }
            }
        }
        arrMemory[key] = r
        return r
    }
}
```
