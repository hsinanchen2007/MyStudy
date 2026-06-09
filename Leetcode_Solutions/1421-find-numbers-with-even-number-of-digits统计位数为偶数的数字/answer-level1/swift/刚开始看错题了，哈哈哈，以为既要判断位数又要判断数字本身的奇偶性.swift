### 解题思路
此处撰写解题思路
取到数组中各个元素，判断奇偶性，返回 count 即可！
### 代码

```swift
class Solution {
    func findNumbers(_ nums: [Int]) -> Int {
        if nums.count <= 500 {
            var count = 0
            
            for number in nums {
                let numStr = String(number)
                if numStr.count%2==0 && number>0 && number<100001 {
                    count+=1
                }
            }
            return count;
        }
        return 0;
    }
}
```