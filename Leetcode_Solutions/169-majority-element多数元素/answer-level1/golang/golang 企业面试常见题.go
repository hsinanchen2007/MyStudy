企业经常出的题是这样的：
给你一个文件，找出文件中出现次数最多的词。昨天面试刚考，所以采用了昨天的方式做了两次循环，复杂度o(2n),其实可以直接在循环中判断map的值是否大于等于n/2，直接返回。
##
思路：
1. 选用常见的kv的map思路，同时引用动态规划来增加max判断。
2. 适用于任意求最大的情况。
##
```
func majorityElement(nums []int) int {
 nMap:=make(map[int]int,0)
 max:=len(nums)/2
 for _,j:=range nums{
  if _,ok:=nMap[j];ok{
   println(j,nMap[j])
   nMap[j]++
  }else {
   nMap[j]=1
  }
  max=maxNum(max,nMap[j])
 }
 for k,v:=range nMap{
  if v==max{
   return k
  }
 }
 return -1
}
func maxNum(i int ,j int ) int{
 if i<j{
  return j
 }else{
  return i
 }
}
```
