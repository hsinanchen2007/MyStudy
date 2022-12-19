### 解题思路
1.现将数组排序
2.遍历排序的数组，每个节点的元素，如果比上一个元素小，则 加上 两个元素之间的差值 + 1
distance = a[i] - a[i - 1] + 1
count = count + distance
![Swift刷题](https://pic.leetcode-cn.com/a9f378eb14128a8912d64c58aa2c2f613509ced74f296ea556c915429179aace-WechatIMG1.jpeg)

### 代码

```swift
class Solution {
  func minIncrementForUnique(_ A: [Int]) -> Int {
     if A.count == 0 {
         return 0
     }
     var temp =  Int.min

    let a = A.sorted()
     
     var count = 0
     for item in a {
         var temp1 = item
        if temp >= temp1 {
            let distance = temp - temp1 + 1
            temp1 = temp1 + distance
            count += distance
        }

         temp = temp1
     }
     return count
  }
}
```