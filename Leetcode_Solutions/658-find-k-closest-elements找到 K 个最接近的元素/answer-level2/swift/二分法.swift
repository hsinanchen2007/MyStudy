大体就是先二分找到最接近的数，然后向两边扩散依次比较
```
class Solution {
    func findClosestElements(_ arr: [Int], _ k: Int, _ x: Int) -> [Int] {
        var minminus = arr.last!
        var left = 0
        var right = arr.count - 1
        var anchor = 0
        var leftVal: Int?
        var rightVal: Int?
        
        while left + 1 < right  {
            let mid = left + (right - left)/2
            if arr[mid] > x {
                right = mid
                if abs(arr[mid] - x) < minminus {
                    anchor = mid
                    minminus = abs(arr[mid] - x)
                }
            }else if arr[mid] < x {
                left = mid
                if abs(arr[mid] - x) < minminus {
                    anchor = mid
                    minminus = abs(arr[mid] - x)
                }
            }else{
                anchor = mid
                break
            }
        }
        
        left = anchor - 1
        right = anchor + 1
        var res = [arr[anchor]]
        while res.count < k {
            
            if left >= 0 {
                leftVal = arr[left]
            }else{
                leftVal = nil
            }
            if right < arr.count {
                rightVal = arr[right]
            }else{
                rightVal = nil
            }
            if leftVal != nil && rightVal != nil {
                if x - leftVal! <= rightVal! - x {
                    res.insert(leftVal!, at: 0)
                    left -= 1
                }else if x - leftVal! >= rightVal! - x && res.count < k {
                    res.append(rightVal!)
                    right += 1
                }
            }else if leftVal != nil {
                res.insert(leftVal!, at: 0)
                left -= 1
            }else if rightVal != nil {
                res.append(rightVal!)
                right += 1
            }
        }
        
        return res
    }
}

```