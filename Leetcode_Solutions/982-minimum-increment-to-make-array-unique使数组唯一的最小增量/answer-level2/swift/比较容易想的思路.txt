
主要思路: 
1:将数组排序,排序貌似是nlogn
2:处理排序的数组,例如[1,1,2]  -> 变成满足要求的的最少次数肯定是变成了 [1,2,3],这三个数的顺序是没有要求的.所以只需要比较 A[i+1] 和 A[i]的值，要是A[i+1] <= A[i]的，那么A[i+1]直接变成A[i]+1就行了,每次递增1，所以res = res + A[i]+1 - A[i+1]

代码如下

    class Solution {
        func minIncrementForUnique(_ A: [Int]) -> Int {
            var temp: [Int] = A.sorted()
            var res = 0
            var preVal = 0
            for index in 0..<temp.count {
                if index > 0 {
                    if temp[index] <= preVal {
                        res = res + (preVal + 1) - temp[index]
                        temp[index] = (preVal + 1)
                    }
                }
                preVal = temp[index]
            }
            return res
        }
    }