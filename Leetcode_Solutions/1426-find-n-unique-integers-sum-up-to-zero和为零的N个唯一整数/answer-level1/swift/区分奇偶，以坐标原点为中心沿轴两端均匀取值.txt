### 解题思路
区分奇偶，以坐标原点为中心沿轴两端均匀取值

### 代码

```swift
class Solution {
    func sumZero(_ n: Int) -> [Int] {
        
        //定义一个变量用来记录返回数组中的元素个数
        var count = 0
        //定义一个变量用来记录返回数组
        var ans = [Int]()
        
        //如果得到的整数n是偶数，则返回数组中的元素为以坐标轴原点（不含原点）为起点，分别往左和往右n/2个数
        //如果得到的整数n是奇数，则返回数组中的元素为以坐标轴原地（含原点）为起点，分别往左和往右（n-1)/2个数
        if n % 2 == 0 {
            count = n / 2
        } else {
            count = (n - 1) / 2
            ans.append(0)
        }
        
        for num in stride(from: -count, to: 0, by: 1) {
            ans.append(contentsOf: [-num,num])
        }

        return ans
    }
}
```