### 解题思路 1

原地修改

### 代码

```swift
class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        
        //因为swift中不用inout修饰的形参无法修改，所以先定义一个和形参同名的数组用来接收实参
        var nums = nums
        
        //定义返回数组
        var ans = [Int]()
        
        //遍历原数组，将每个元素-1的值当做索引，把对应索引位置上的元素取反用以标记该索引对应的数字存在
        for num in nums {
            
            nums[ abs(num) - 1 ] = abs(nums[ abs(num) - 1 ]) * -1
 
        }
        
        //再次遍历原数组，如果某个索引上的元素不为负数，则该索引+1的值即为缺失的数字
        for (index, num) in nums.enumerated() {
            if num > 0 {
                ans.append(index + 1)
            }
        }

        return ans
        
    }
}

```

### 解题思路 2

哈希表

### 代码 2

```swift

class Solution {
    func findDisappearedNumbers(_ nums: [Int]) -> [Int] {
        
        
        var ans = [Int]()
        
        if nums.isEmpty {
            return ans
        }

        //初始化数组
        for i in 1...nums.count {
            ans.append(i)
        }
        
        //将原数组中已有的数从返回数组中删除
        for num in nums {
            if num == ans[num - 1] {
                ans[num - 1] = 0
            }
        }
        
        return ans.filter{ $0 > 0 }
        
    }
}
```