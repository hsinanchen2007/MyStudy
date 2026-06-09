### 解题思路 1
利用数组和sort()的沙雕常规法，效率一般...

### 代码

```swift
class Solution {
    func uniqueOccurrences(_ arr: [Int]) -> Bool {
        
        //初始化一个临时数组，用来记录原数组的每个数字的出现次数（注意原数组中可能会出现负数，所以要仔细考虑临时数组的长度）
        var temp = Array(repeating: 0, count: 2001)
        
        //遍历原数组，将各个数字的出现次数记录到临时数组内
        for (_,value) in arr.enumerated() {
            if value >= 0 {
                temp[temp.index(arr.startIndex, offsetBy: value)] += 1
            } else {
                temp[temp.index(arr.startIndex, offsetBy: -value + 1000)] += 1
            }
            
            
        }
        
        //定义返回值
        var ans = true
        
        //给sort传入一个闭包，看看得到的新数组内是否存在相邻的元素相同且不为0的情况（即原数组内有两个以上的数字出现的次数相同）
        //因为闭包可以捕捉上下文的变量，所以由此决定返回值
        temp.sort { num1, num2 in
            if num1 == num2 && num1 != 0 {
                ans = false
            }
            return num1 > num2
        }

        return ans
    }
}
```


### 解题思路 2
利用字典的解法

### 代码

```swift
class Solution {
    func uniqueOccurrences(_ arr: [Int]) -> Bool {
        
        //初始化一个词典，用来存储各个数字的出现次数
        var CountOfNums = [Int:Int]()
        
        //遍历原数组，将数组中的每个元素作为字典的key，每个元素出现的次数作为字典的value插入到字典中
        for num in arr {
            
            if let count = CountOfNums[num] {
                CountOfNums.updateValue(count + 1, forKey: num)

            } else {
                CountOfNums.updateValue(1, forKey: num)
            }
        }
        
        //如果原数组中有n个不同的数，那么当且仅当每个数字出现的次数的情况亦为n时返回true
        let counts = Array(Set(CountOfNums.values))
        let nums = Array(Set(arr))

        return counts.count == nums.count
        
    }
}
```
