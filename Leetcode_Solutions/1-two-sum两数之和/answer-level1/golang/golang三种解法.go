方法一：
两个for循环，o(n2)
func twoSum(nums []int, target int) []int {
for i:=0;i<len(nums);i++{
for j:=i+1;j<len(nums);j++{
if nums[i]+nums[j]==target{
return []int{i,j}
}
}
}
return[]int{-1,-1}
}
方法二：
先遍历一遍，保存值和索引的映射关系。再遍历一遍，查看对应的值是否存在。这里注意一个特殊的地方，如果数组中存在多个相同的值会被覆盖，因此map的key应该是一个切片map[int][]int。时间o(n1),空间o(n).
func twoSum(nums []int, target int) []int {
indexMap:=make(map[int][]int)
for i:=0;i<len(nums);i++{
indexMap[nums[i]]=append(indexMap[nums[i]],i)
}
for i:=0;i<len(nums);i++{
if nums[i]==target-nums[i]{
if len(indexMap[nums[i]]) > 1{
return []int{i,indexMap[nums[i]][1]}
}else{
continue
}
}
if v,ok:=indexMap[target-nums[i]];ok{
return []int{i,v[0]}
}

}
return[]int{-1,-1}
}
方法三：
再第一遍遍历的时候可以查找当前的map中是否已经存在对应的元素。时间o(n1),空间o(n)，其实也没有量级的改进，只是少遍历了一遍数组。
func twoSum(nums []int, target int) []int {
indexMap:=make(map[int][]int)
for i:=0;i<len(nums);i++{
if val,ok:=indexMap[target-nums[i]];ok{
return []int{val[0],i}

    }
    indexMap[nums[i]]=append(indexMap[nums[i]],i)

}

return[]int{-1,-1}
}

作者：fei-176
链接：https://leetcode-cn.com/problems/two-sum/solution/golangsan-chong-jie-fa-by-fei-176/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。