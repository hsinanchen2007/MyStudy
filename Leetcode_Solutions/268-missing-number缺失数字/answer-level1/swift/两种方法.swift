### 解题思路 1

用另一个完整的数列的和依次减去输入数列中的元素

### 代码

```swift
class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        let n = nums.count
        let sum = n * (n + 1) / 2 //d=1的等差数列求和

        return nums.reduce( sum, - )
    }
}
```

### 解题思路 2

异或运算

### 代码 2

```swift
class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        
        //异或运算 1^1 = 0, 1^0 = 1， 1^1^2^2^3 = 3
        //所以让输入数列的每个元素，和0...n的完整序列中的每个元素依次做异或运算，最后得到的就是缺失的数字了
        var ans = nums.count
        
        for (index, num) in nums.enumerated() {
            
            ans ^= index
            ans ^= num
            //print(index)
        }
        
        return ans
    }
}
```