最开始对“右边第一位”理解有误，加上两个例子更加误导了。
```
unc nextGreaterElement(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var result = Array<Int>()
        for (_, num1) in nums1.enumerated() {
            let index2 = nums2.firstIndex(of: num1)!
            if index2 == nums2.count - 1 {
                result.append(-1)
            }
            else {
                var match = false
                for index in (index2 + 1)..<nums2.count {
                    let num2 = nums2[index]
                    if num2 > num1 {
                        result.append(num2)
                        match = true
                        break
                    }
                }
                if !match {
                    result.append(-1)
                }
            }
        }
        return result
    }
```