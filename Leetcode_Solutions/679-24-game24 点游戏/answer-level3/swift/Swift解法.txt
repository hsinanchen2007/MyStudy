先上代码
```Swift
class Solution {
    func judgePoint24(_ nums: [Int]) -> Bool {
        let result = nums.map { (item) -> Double in
            return Double(item)
        }
        return solve(nums: result)
    }
    
    func solve(nums: [Double]) -> Bool {
        guard nums.count != 0 else {
            return false
        }
        guard nums.count != 1 else {
            return abs(nums[0] - 24.0) < 0.000001
        }
        for (offset, element) in nums.enumerated() {
            for (offset2, element2) in nums.enumerated() {
                guard offset != offset2 else { continue }
                var nums2 = [Double]()
                for (offset3, element3) in nums.enumerated() where offset3 != offset && offset3 != offset2 {
                    nums2.append(element3)
                }
                for i in 0...3 {
                    if i<2 && offset2 > offset {
                        continue
                    }
                    switch i {
                    case 0:
                        nums2.append(element + element2)
                    case 1:
                        nums2.append(element * element2)
                    case 2:
                        nums2.append(element - element2)
                    case 3:
                        guard element2 != 0 else { continue }
                        nums2.append(element / element2)
                    default:
                        break
                    }
                    if solve(nums: nums2) {
                        print(nums2)
                        return true
                    }
                    nums2.removeLast()
                }
            }
        }
        return false
    }
}
```

这里思路就是排列组合，先取前两个遍历做4则运算，然后使得数组长度减少一位，然后再对新数组进行同样的操作，直到数组数量变为2或更少。