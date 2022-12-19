
## 双指针解法

### 思路

1. 移动指针
    - 左指针向右移动直至遇到偶数为止
    - 右指针向左移动直至遇到奇数为止
2. 交换左右指针所在处的值

### 代码

```swift
class Solution {
    func exchange(_ nums: [Int]) -> [Int] {
        guard nums.count > 1 else { return nums }

        var arr = nums
        var p1 = 0
        var p2 = arr.count - 1
        var temp: Int

        while p1 < p2 {
            while p1 < p2 && arr[p1] % 2 != 0 { // 左指针一直向右推到偶数为止(使用p1<p2 是为了防止整个数组没有偶数)
                p1 += 1
            }

            while p1 < p2 && arr[p2] % 2 == 0 { // 右指针一直向左推到奇数为止(使用p1<p2 是为了防止整个数组没有奇数)
                p2 -= 1
            }

            if p1 < p2 { // 经过上方的推进后仍然 p1<p2 (说明两指针没有相遇)
                temp = arr[p1]
                arr[p1] = arr[p2]
                arr[p2] = temp
            }
        }
        return arr
    }
}
```

## 开辟新数组解法

### 思路

1. 创建两个数组, `oddNumArr`(存储奇数)与 `evenNumArr`(存储偶数)。
2. 遍历给定数组中的所有元素, 遇到奇数就存进`oddNumArr`, 遇到偶数就存进 `evenNumArr`
3. 最后返回 `oddNumArr+evenNumArr`

### 代码

```swift
class Solution {
    func exchange(_ nums: [Int]) -> [Int] {
        var oddNumArr = [Int]()
        var evenNumArr = [Int]()

        for i in nums {
            if i % 2 == 0 {
                evenNumArr.append(i)
            } else {
                oddNumArr.append(i)
            }
        }

        return oddNumArr + evenNumArr
    }
}
```
