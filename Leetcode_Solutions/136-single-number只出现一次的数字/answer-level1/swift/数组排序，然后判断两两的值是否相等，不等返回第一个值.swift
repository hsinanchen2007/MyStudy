因为重复元素固定是2个，那就先给数组排序，然后判断两两的值是否相等
```
func singleNumber(_ nums: [Int]) -> Int {
        var array = nums.sorted()
        let count = array.count / 2
        for index in 0...count {
            if index == count {
                return array.last!
            }
            let one = array[index * 2]
            let two = array[index * 2 + 1]
            if one != two {
                return one
            }
        }
        return 0
    }
```