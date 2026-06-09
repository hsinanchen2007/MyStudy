### 解题思路
![image.png](https://pic.leetcode-cn.com/d5db73e22060fc08ad2f84921fd23bd93ec32d497c13bfd70922d636b33c24a2-image.png)
1. 遍历数组，使用 map 记录下所有的数字的数量情况
2. 判断 map的 count是否等于数组 count,是直接返回0
3. 对 map 里的 key也就是数组里面的值排序，不过当前的值唯一了，最坏的情况的时间复杂度O（n - 1）
4. 遍历这个map 的 key,对里面所有 value大于2的key进行模拟move操作，找出最小的可以使用的数字。这个最小的数字 min 的起始值，肯定就是 k + 1 和 min + 1中最大的那个。找到 min 后，min - k 就是我 move操作的次数
5. 记录下每次的 move 次数直到遍历完成。
### 代码

```swift
class Solution {
func minIncrementForUnique(_ A: [Int]) -> Int {

    var map: [Int: Int] = [:]

    for a in A {
        map[a] = (map[a] ?? 0) + 1
    }

    if map.count == A.count {
        return 0
    }

    let keys = map.keys.sorted()

    var minUnused: Int = 0

    var res = 0

    for k in keys {
        while map[k]! > 1 {
            ///需要将 value减小到1
            minUnused = Swift.max(k + 1, minUnused + 1)
            while map[minUnused] != nil {
                minUnused += 1
            }
            // 找到最小的那个可用值
            res += (minUnused - k)
            map[k] = map[k]! - 1
        }
    }

    return res
}
}
```