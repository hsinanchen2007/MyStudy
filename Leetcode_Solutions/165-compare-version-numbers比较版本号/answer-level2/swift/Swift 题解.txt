1. 先通过"."对字符串进行分割，得到 2 个字符串数组：array1,array2
2. 遍历最小数组的长度，将数组中的字符串转换成 Int 类型进行比较，去除前置 0
    - 大于返回 1
    - 小于返回 -1
    - 等于继续比较
3. 此时长度最短的数组已经比较完毕，代表前面都一样，然后比较还没有遍历完的数组
    - array1 没有遍历完，后面任意一位值大于 0，则返回 1
    - array2 没有遍历完，后面任意一位值大于 0，则返回 -1
4. 剩余情况就是相等，返回 0 

```
func compareVersion(_ version1: String, _ version2: String) -> Int {
    let array1 = version1.split(separator: ".")
    let array2 = version2.split(separator: ".")
    let minLength = min(array1.count, array2.count)
    
    var temp1 : String
    var temp2 : String
    for i in 0..<minLength {
        
        temp1 = "\(array1[i])"
        temp2 = "\(array2[i])"
        if Int(temp1)! > Int(temp2)! {
            return 1
        } else if Int(temp1)! < Int(temp2)! {
            return -1
        }
    }
    
    if minLength < array1.count {
        for i in minLength..<array1.count {
            temp1 = "\(array1[i])"
            if Int(temp1)! > 0 {
                return 1
            }
        }
    } else if minLength < array2.count {
        for i in minLength..<array2.count {
            temp2 = "\(array2[i])"
            if Int(temp2)! > 0 {
                return -1
            }
        }
    }
    
    return 0
}
```
