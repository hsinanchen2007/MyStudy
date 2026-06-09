方法一： 暴力解法
双重for循环搞定，最暴力的解法，没啥好解释的

```
   func twoSum(_ nums: [Int], _ target: Int)  -> [Int] {

        for (i,num) in nums.enumerated() {

            for index in (i + 1..<nums.count){
                if(target - num) == nums[index]{
                    return[i,index]
                }
            }
        }
        return[]
    }

```

运行时间：600多ms，果然效率比较低
![image.png](https://pic.leetcode-cn.com/d0a9e1729e8780abefd3e3bef96cf52baa6267540bbba4cb9db8283ce42e083c-image.png)

方法二： 数组组合解法，swift 数组特性，首先遍历取出数组中的值和下标，然后查找target - num值是否在数组中存在，采用的是contains方法，这里耗时最长，contains方法个人认为是获取数组的引用后，根据引用对应的值进行对比，这是其一，其二是firstIndex 这个对比查找

```
 func twoSum(_ nums: [Int], _ target: Int)  -> [Int] {
        
     for (i,num) in nums.enumerated() {
        
        if let index1 = nums.firstIndex(of: (target - num)) {
            if nums.contains(target - num) == true && index1 != i {
                return  [i,index1]
            }
        }
        
    }
    
    return []
    }
```
运行时间： 超出时间限制，效率太低了，但是充分使用swift特性，欢迎大家一起讨论

![image.png](https://pic.leetcode-cn.com/9d0af2b805235ca712746479aedb2b8058df6ea8b93c2065c6d0882c7d82a435-image.png)

方法三： 2遍哈希表解法，采用swift 字典存储特性
```
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic  = [Int:Int]()
        for (key,value) in nums.enumerated() {
            dic[value] = key
        }
        for (index,n) in nums.enumerated() {
            if dic.keys.contains(target-n) && index != dic[target - n]{
                return [index,dic[target - n]!]
            }
            
        }
         return []
}
```
运行时间： 60ms,速度还是挺快的，效率也很高，占用空间23MB

![image.png](https://pic.leetcode-cn.com/62dae269ff32fc99ffd2133ca22e57d29bbf5a3d54029941240613a566c8cb87-image.png)

方法四：1遍哈希表解法，采用swift 字典存储特性
```
 func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic  = [Int:Int]()
        for (index,n) in nums.enumerated() {
            let complement = target - n
            if dic.keys.contains(complement) && index != dic[complement] {
                return [dic[complement]!,index]
            }
            dic[n] = index
        }
       return []
    }
```
运行时间：52ms，目前效率最高，占用空间：21.3MB
    
![image.png](https://pic.leetcode-cn.com/88415faab19a4871f4ec09725943b4b7978c176425e924068db8e096d5ee5a6e-image.png)

综合看法：
空间对比   暴力解法 < 1遍哈希表算法  < 2遍哈希表算法， 数组组合算法待定
时间对比   1遍哈希表算法  < 2遍哈希算法 < 暴力解法 < 数组组合算法



