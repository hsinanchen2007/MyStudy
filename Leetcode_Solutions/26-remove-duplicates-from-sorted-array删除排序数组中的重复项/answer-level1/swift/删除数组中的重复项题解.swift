### 方法一：双指针解法

解题思路：
`lastIndex` 是慢指针，`currentIndex` 是快指针。
后面的项逐一与 `lastIndex` 所对应的项进行判断是否相等，相等则跳过，不等则将 `currentIndex` 当前项替换 `lastIndex` 的下一项(即 `lastIndex + 1`)。

```swift
func removeDuplicates(_ nums: inout [Int]) -> Int {
    if nums.isEmpty { return 0 }
    
    var lastIndex = 0
    let count = nums.count
    for currentIndex in 1..<count {
        if nums[currentIndex] != nums[lastIndex] {
            lastIndex += 1
            nums[lastIndex] = nums[currentIndex]
        }
    }
    return lastIndex + 1
}
```

示例：
给定数组 nums = [0,0,1,1,1,2,2,3,3,4],

开始循环：
lastIndex = 0，currentIndex = 1 时，nums = [0,0,1,1,1,2,2,3,3,4]，
lastIndex = 0，currentIndex = 2 时，nums = [0,1,1,1,1,2,2,3,3,4]，lastIndex + 1，
lastIndex = 1，currentIndex = 3 时，nums = [0,1,1,1,1,2,2,3,3,4]，
lastIndex = 1，currentIndex = 4 时，nums = [0,1,1,1,1,2,2,3,3,4]，
lastIndex = 1，currentIndex = 5 时，nums = [0,1,2,1,1,2,2,3,3,4]，lastIndex + 1，
lastIndex = 2，currentIndex = 6 时，nums = [0,1,2,1,1,2,2,3,3,4]，
lastIndex = 2，currentIndex = 7 时，nums = [0,1,2,3,1,2,2,3,3,4]，lastIndex + 1，
lastIndex = 3，currentIndex = 8 时，nums = [0,1,2,3,1,2,2,3,3,4]，
lastIndex = 3，currentIndex = 9 时，nums = [0,1,2,3,4,2,2,3,3,4]，lastIndex + 1，
lastIndex = 4，循环结束。

因此，通过双指针解法返回的实际数组：nums = [0,1,2,3,4,2,2,3,3,4], 返回的新数组长度 5。
你会发现，该方法其实并没有真正的“删除” 数组中的项，而是把重复的项替换调了！并且通过慢指针`lastIndex + 1`返回前面不重复的项的长度。

题目中一条很重要的说明：**你不需要考虑数组中超出新长度后面的元素。**
另外，双指针解法奏效的前提是：假定输入数组 `nums` 已经被排序了。


### 方法二：利用 Swift 的 `Set` 特性

通过 `Set` 过滤重复项，再返回给数组。

```swift
func removeDuplicates(_ nums: inout [Int]) -> Int {
    if nums.isEmpty { return 0 }
    
    let set = Set(nums)
    nums = Array(set)
    nums.sort()
    return nums.count
}
```

