1. 先排序，在进行字符串比较
2.  
```
func CheckPermutation1(_ s1: String, _ s2: String) -> Bool {
        if s1.count != s2.count {
            return false
        }
        if s1 == s2 {
            return false
        }
        
       let  new_s1 =  s1.sorted()
       let new_s2 = s2.sorted()
        if new_s1 != new_s2 {
            return false
        }
        return true;
    }
```
2. 可以转成数组，再进行排序比较
3. ```
func CheckPermutation2(_ s1: String, _ s2: String) -> Bool {
        if s1.count != s2.count {
            return false
        }
        if s1 == s2 {
            return false
        }
        var arr1 = [Character]()
        for c in s1 {
            arr1.append(c)
        }
        var arr2 = [Character]()
        for c in s2 {
            arr2.append(c)
        }
        let new_arr1 = arr1.sorted()
        let new_arr2 = arr2.sorted()
        
        for (index,value) in new_arr2.enumerated() {
            if value != new_arr1[index] {
                return false
            }
        }
        return true;
    }
```
