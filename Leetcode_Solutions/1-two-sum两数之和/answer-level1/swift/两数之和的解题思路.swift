题目概要:有一个数组,里面有若干元素, 另外有一个目标值, 在数组中找到两个元素相加恰好等于目标值,这里称之为两数之和;

第一种思路: 暴力解题, 通过两次循环对数组中的元素两两相加比对,最终找出目标下标, 时间复杂度为O(n^2);

代码如下:

```
func twoNumSun(nums : [Int], target : Int)->[Int]{
    let n = nums.count;
    for i in 0..<n{
        let j = i + 1
        for index in j..<n {
            if nums[i] + nums[index] == target {
                return[i, index]
            }
        }
    }
    return []
}
```


第二种:通过key value映射,时间复杂度为O(1);
```
let n = nums.count
    var dict : [Int:Int] = [:]
    var i = 0;
    for index in 0..<n {
        let temp = target - nums[index]
        if dict.keys.contains(temp)  && i != index  {
            let j : Int = dict[temp]!
            return [j, index]
        }
        dict.updateValue(index, forKey: nums[index])
        i = index
    }
    return []
```




