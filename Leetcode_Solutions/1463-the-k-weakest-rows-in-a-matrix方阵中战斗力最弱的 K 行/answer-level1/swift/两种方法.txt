### 解题思路 1
使用字典

### 代码

```swift
class Solution {
    func kWeakestRows(_ mat: [[Int]], _ k: Int) -> [Int] {
        
        //定义字典用来记录在输入矩阵各行找到的”1“的数量
        var numbersOfOneInmat = [Int:Int]()
        
        //遍历矩阵，将矩阵各行”1“的数量和对应的行索引插入字典
        for (index,arr) in mat.enumerated() {
            if let lastIndexOfOne = arr.lastIndex(of: 1) {
                numbersOfOneInmat.updateValue(lastIndexOfOne + 1, forKey: index)
            } else {
                numbersOfOneInmat.updateValue(0, forKey: index)
            }
        }
        
        //给.sorted()自定义一个方法用来筛选最弱的k行索引
        let ans = numbersOfOneInmat.sorted(by: { s1,s2 in
            if s1.value < s2.value {
                return true
            }
            else if s1.value == s2.value && s1.key < s2.key {
                return true
            }
            
            return false

        }).dropLast(mat.count - k).map{ (s1, _) in s1 }
 
        return ans
    }
}
```

### 解题思路 2
使用数组


### 代码

```
class Solution {
    func kWeakestRows(_ mat: [[Int]], _ k: Int) -> [Int] {
        

        //定义并初始化一个数组，用来记录矩阵各行的”1“的数量和对应的行索引
        var numbersOfOneInmat = Array(repeating: 0, count: mat.count)
        
        //遍历矩阵，将矩阵各行”1“的数量和对应的行索引插入数组
        for (index,arr) in mat.enumerated() {
            if let lastIndexOfOne = arr.lastIndex(of: 1) {
                numbersOfOneInmat[index] += lastIndexOfOne + 1
            }
        }
        
        //给sorted()自定义一个方法，用来筛选最弱的k行索引
        //注意对于array，sorted()要用在enumerated()之后！
        let ans = numbersOfOneInmat.enumerated().sorted(by: { s1,s2 in
            if s1.element < s2.element {
                return true
            }
            else if s1.element == s2.element && s1.offset < s2.offset {
                return true
            }
            
            return false
        }).dropLast(mat.count - k).map{(offset, _) in offset }
        

 
        return ans
    }
}
```
