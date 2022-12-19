![Snip20200325_11.png](https://pic.leetcode-cn.com/35ea689e66d5fc255bd1b76c19720af24896e3e554fa530a08007bf3a7c93bba-Snip20200325_11.png)

### 解题思路
1.  如果目标值大于当前数值，跳出当前循环
2.  value == target， 直接返回 i
    target < value   直接返回 value对应的i索引， 也就是要插入的位置
3. 如果循环遍历完了，仍然没有返回，那就说明target比数组中所有的值都大，放到数组后面nums.count的位置
### 代码

```swift
class Solution {
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
               
        for (i, value) in nums.enumerated() {
 
            if (target > value) { continue }  
        
            return i
        }
        return nums.count 
    }
}
```