第一种方法 执行用时56ms

![屏幕快照 2019-05-13 下午7.16.56.png](https://pic.leetcode-cn.com/4343ac9e7a1cfd787d320095ee945cb3a065625da03554df4cda1f9b26bf1c04-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-05-13%20%E4%B8%8B%E5%8D%887.16.56.png)
使用哈希表
首先定义一个哈希表，将数组元素作为key，元素下标作为value，依次添加到字典中。
然后遍历数组，在字典中查找key为（目标值-数组元素）的元素，取其下标，和此时数组元素的下标，即为解。
```
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        
        var dict = Dictionary<Int,Int>()
        var i = 0;
        for n in nums {//遍历数组将每一项数组值作为key，对应的数组下标作为value添加到字典里
            dict[n] = i
            i = i+1
        }
        var arr = [-1,-1]
        
        var j = 0;
        for n in nums {//遍历数组，直接在上述字典中依次查找key为（target - n）的value,找到此value且与j值不同，即为答案
            if dict.keys.contains(target - n) && j != dict[target - n]
            {
                arr[0] = j
                arr[1] = dict[target - n] ?? -1
                return arr
            }
            j = j+1
        }
        return arr
    }
```

第二种方法 执行用时616ms。。。差距还是挺大的

![屏幕快照 2019-05-13 下午11.03.33.png](https://pic.leetcode-cn.com/59ef61eb9c3d406d80c8f82842dc558e3a228d40869f6816410e1cdb435a96b6-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-05-13%20%E4%B8%8B%E5%8D%8811.03.33.png)
双层遍历
```
        for i in 0..<nums.count-1 {
            let nn = nums[i]
            for j in i+1..<nums.count {
                let mm = nums[j]
                if nn + mm == target
                {
                    return [i,j]
                }
            }
        }
        return [-1,-1]
```