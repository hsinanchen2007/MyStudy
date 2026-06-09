什么叫真正的笨方法
```
class Solution {
    func sortArrayByParityII(_ A: [Int]) -> [Int] {
        var arr = A.sorted{ (a, b) -> Bool in
            a%2==0
        }
        var result = [Int]()
        var arr1 = [Int](arr[0..<arr.count/2])
        var arr2 = [Int](arr[arr.count/2..<arr.count])
        for i in 0..<arr1.count{
            result.append(arr1[i])
            result.append(arr2[i])
        }
        return result
    }
}
```
聪明的方法，参考pingcoool的题解。
```
class Solution {
    func sortArrayByParityII(_ A: [Int]) -> [Int] {
        var arr = A
        var odd = 1
        var even = 0
        while odd<A.count && even<A.count {
            while odd<A.count && arr[odd]%2==1 {
                odd += 2
            }
            while even<A.count && arr[even]%2==0 {
                even += 2
            }
            if odd<A.count && even<A.count {
                arr.swapAt(odd, even)
            }
            print(odd,even)
        }
        return arr
    }
}
}
```

