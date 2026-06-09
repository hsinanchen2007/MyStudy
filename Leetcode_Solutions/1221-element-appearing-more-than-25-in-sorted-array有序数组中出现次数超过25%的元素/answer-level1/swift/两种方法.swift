### 解题思路 1

遍历统计法

### 代码

```swift
class Solution {
    func findSpecialInteger(_ arr: [Int]) -> Int {
        
        //记录输入数组的长度
        let length = arr.count
        //初始化用来计算当前元素的出现个数
        var count = 0
        //初始化指针
        var pointer = arr.first!
        
        //遍历输入数组
        for num in arr {

            //如果指针指向的下一个元素依然没变，则count++。否则指针指向当前元素，count复值为1
            if num == pointer {
                count += 1
            } else {
                pointer = num
                count = 1
            }
            
            //如果当前元素的的出现次数超过输入数组长度的25%则返回指针当前指向的元素
            //⚠️swift里int 和double 的比较必须显示转换为统一类型后进行
            if count * 4 >  length {
                return pointer
            }
            
        }
        
        return 0
    }
}
```


### 解题思路 2

二分法

### 代码

```
class Solution {
    func findSpecialInteger(_ arr: [Int]) -> Int {
        
        //记录输入数组的长度
        let length = arr.count
        //指定满足要求的最小索引区间
        let range = length / 4
        
        //遍历输入数组，当切仅当指定区间内的所有元素都为同一值时返回该值
        for (index,num) in arr.enumerated() {
            
            if (index + range) < arr.endIndex && num == arr[index + range] {
                return num
            }
        }
 
        return 0
    }
}
```
