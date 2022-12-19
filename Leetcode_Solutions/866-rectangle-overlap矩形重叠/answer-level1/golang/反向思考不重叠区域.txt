正向涉及情况太多，需要列举很多，反向则简单很多，只要rec2的左下端点在rec1右上端点的右上方，rec2的右上端点rec1左下端点的左下方就是不重叠的情况。在纸上画图比较清晰，语言表达的可能不是很清楚，此题重点是想法，代码没啥技巧。

```
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
    tag:=1
   if rec2[3]<=rec1[1]||rec2[2]<=rec1[0]||rec2[0]>=rec1[2]||rec2[1]>=rec1[3]{
       tag=0
   }
   if tag==0{
       return false
   }else{
       return true
   }
}
```
