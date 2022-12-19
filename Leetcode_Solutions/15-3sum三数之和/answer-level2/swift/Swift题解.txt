先排序，从小到大排序，时间O(nlogn)
用指针k从右往左定义target = -nums[k]，用两个指针i = 0, j = k - 1来查找target，判断nums[i] + nums[j]和target的关系
若相等，则三个数加入结果，同时i右移，j左移，若小于target则i右移，否则j左移。其中等于target的情况还需要判断nums[i]和nums[i + 1]，来规避掉相等的情况，同理j也要做判断
最后时间复杂度O(n²)，空间复杂度O(1)
```
func threeSum(_ nums: [Int]) -> [[Int]] {
    var res = [[Int]]()
    let sortedNums = nums.sorted()
    var k = sortedNums.count - 1
    while k >= 2 {
        if sortedNums[k] < 0 {
            break;
        }
        var i = 0
        var j = k - 1
        let target = -sortedNums[k]
        while i < j {
            if sortedNums[i] + sortedNums[j] == target {
                res.append([sortedNums[i],sortedNums[j],sortedNums[k]])
                while i < j && sortedNums[i] == sortedNums[i + 1] {
                    i = i + 1
                }
                while i < j && sortedNums[j] == sortedNums[j - 1] {
                    j = j - 1
                }
                i = i + 1
                j = j - 1
            } else if sortedNums[i] + sortedNums[j] < target {
                i = i + 1
            } else {
                j = j - 1
            }
        }
        while k >= 2 && sortedNums[k] == sortedNums[k - 1] {
            k = k - 1
        }
        k = k - 1
    }
    return res
}
```
