# 方法1：暴力2层循环
```
 func twoSum(nums []int, target int) []int {
    if len(nums)<2{
        return nil
    }else{
        for i:=0;i<len(nums)-1;i++
            for j:=i+1;j<len(nums);j++{
                if nums[i]+nums[j]==target{
                    return []int{i,j}
                }
            }
}
   
```



# 方法2：利用map记录
```
 func twoSum(nums []int, target int) []int {
    	m:=make(map[int]int)
        for i:=0;i<len(nums);i++{
            another:=target-nums[i]
            if _,ok:=m[another];ok{
                return []int{m[another],i}
            }
            m[nums[i]]=i
        }
        return nil
}
```



