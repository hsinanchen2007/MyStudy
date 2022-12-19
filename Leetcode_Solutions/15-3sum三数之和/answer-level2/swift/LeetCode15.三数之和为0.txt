解题思路:
1.先排序，减少多余操作，从小到大排序
2.重复过滤
3.将三数之和为0转换为 a+b = -c,转成两个数之和 
3.通过下标i、下标low = i + 1、下标high = nums.count - 1来判断相等  target = 0 - nums[i]
4.若nums[low] + nums[high] = target 则加入结果集同时i右移、high左移继续遍历，若 < target ，则右移， 若 > target 则左移

    class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
     guard nums.count > 2 else {
         return []
     }

     var results = [[Int]]()
     let sortedNums = nums.sorted()

    for i in 0..<sortedNums.count-1 {
        if i > 0 && sortedNums[i] == sortedNums[i-1] {
           continue
       }
        let target = 0 - sortedNums[i]
        var low = i + 1
        var high = nums.count - 1

        while low < high {
            let sum = sortedNums[low] + sortedNums[high]
           if sum == target {
                let result = [sortedNums[i], sortedNums[low], sortedNums[high]]
               results.append(result)

            while (low < high && sortedNums[low] == sortedNums[low+1]) {
                low += 1
             }
            while (low < high && sortedNums[high] == sortedNums[high-1]) {
                 high -= 1
            }
               low += 1
               high -= 1
            } else if sum < target {
               low += 1
           } else {
              high -= 1
           }
        }
    }

    return results
     }
    }