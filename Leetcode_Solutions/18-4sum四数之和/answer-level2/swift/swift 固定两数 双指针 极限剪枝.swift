
![image.png](https://pic.leetcode-cn.com/0f2069d77fec032e6f4a564c5b0e666185615a8da0469e49cbbba748cf77bc48-image.png)

```
class Solution {
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        guard nums.count >= 4 else {
            return []
        }
        let sorted = nums.sorted()
        let count = sorted.count
        var arr = [[Int]]()
        for i in 0..<count - 3 {
            if i > 0 && sorted[i] == sorted[i - 1] {
                continue
            }
            guard sorted[i] + sorted[i + 1] + sorted[i + 2] + sorted[i + 3] <= target else {
                break
            }
            for j in i + 1..<count - 2 {
                if j > i + 1 && sorted[j] == sorted[j - 1] {
                    continue
                }
                guard sorted[i] + sorted[j] + sorted[count - 1] + sorted[count - 2] >= target else {
                    continue
                }
                guard sorted[i] + sorted[j] + sorted[j + 1] + sorted[j + 2] <= target else {
                    break
                }
                var l = j + 1
                var r = count - 1
                while l < r {
                    let sum = sorted[i] + sorted[j] + sorted[l] + sorted[r]
                    if sum == target {
                        arr.append([sorted[i], sorted[j], sorted[l], sorted[r]])
                        while l < r && sorted[l] == sorted[l + 1] {
                            l += 1
                        }
                        while l < r && sorted[r] == sorted[r - 1] {
                            r -= 1
                        }
                        l += 1
                        r -= 1
                    } else if sum > target {
                        r -= 1
                    } else if sum < target {
                        l += 1
                    }
                }
            }
        }
        return arr
    }
}
```
