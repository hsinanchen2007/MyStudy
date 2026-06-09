暴力解法
```
func twoSum(nums []int, target int) []int {
    for i := 0;i < len(nums); i++{//双for循环
        for x := 0;x < len(nums); x++{
            if i != x&&nums[i] + nums[x] == target{ //下标不同且两数之和为目标数值
                return []int{i,x}//返回目标切片
            }
        }
    }
    return nil
}
```
效率解法
```
func twoSum(nums []int, target int) []int {
    newMaps = make(map[int]int)
    for index1,value1 = range nums{
        value2 = target - value1
        index2,ok = newMaps[value2];if ok{ 如果这个互补的数字之前已经被放入了map中,ok为true
           return []int{index1,index2}   将下标返回
        }else{
        newMaps[value1] = index1  若没有完成判断，则将所遍历到的数放入map中 
        }
    }
    return nil
}
```

