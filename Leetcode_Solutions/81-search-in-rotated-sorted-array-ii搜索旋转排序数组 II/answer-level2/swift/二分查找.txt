- 先找到旋转点，将输入数组拼接成一个顺序的数组；
- 进行二分
```
class Solution {
    func search(_ nums: [Int], _ target: Int) -> Bool {
        if nums.count == 0 {
            return false
        }
        if nums.count == 1 {
            return nums[0] == target
        }
        var media = 0
        for i in 1...nums.count-1 {
            if nums[i] < nums[i-1] {
                media = i
            }
        }
        var arr:[Int] = Array<Int>(repeating: 0, count: nums.count)
        for i in 0...nums.count-1 {
            if i < media {
                arr[i + nums.count - media] = nums[i]
            } else {
                arr[i-media] = nums[i]
            }
        }
        
        var begin = 0
        var end = arr.count - 1
        var middle = (begin+end)>>1
        if arr[middle] != target {
            while begin != end {
                if arr[middle] > target {
                    if middle == end {
                        end = begin
                    } else {
                        end = middle
                    }
                } else {
                    if begin == middle {
                        begin = end
                    } else {
                        begin = middle
                    }
                }
                middle = (begin+end)>>1
                if arr[middle] == target {
                    return true
                }
            }
        } else {
            return true
        }
        
        return false
    }
}
```
