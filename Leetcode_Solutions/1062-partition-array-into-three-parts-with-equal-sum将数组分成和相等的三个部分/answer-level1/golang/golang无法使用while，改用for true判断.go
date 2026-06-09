1. 常规思路：三等分的前提是sum(A)被整除，其次采用双指针的形式对加和进行判断。
2. 平时用golang写for true的循环习惯在开头写判断导致错误，因为有对边界条件用到的变量值的改变，break判断一定放最后（加粗部分）
3. 异常情况判断：sum(A)=0的边界判断,必须让sum1和sum3至少进入一次进入if，否则在sum(A)=0时可能有误判，例如[1,-1,-1,1]如果不增加sum*==0的if判断，可能sum1和sum3为初始值，也就是说一、三部分不存在。
代码如下：
```
func canThreePartsEqualSum(A []int) bool {
sum:=0
 for _,i:=range A{
  sum+=i
 }
 if sum%3!=0{
  return false
 }
 sum1:=0
 sum3:=0
 i:=0
 j:=len(A)-1
 for{
  if sum1!=sum/3|| sum1==0{
   sum1+=A[i]
   i++
  }
  if sum3!=sum/3|| sum3==0{
   sum3+=A[j]
   j--
  }
  ** if i>j{
   break
  }**
  println(i,j,sum1,sum3)
  if sum1==sum/3 && sum3==sum/3 {

   return true
  }

 }
 return false
}
```
