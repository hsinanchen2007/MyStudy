### 解题思路
&emsp;&emsp;看到这个题目，首先想到的就是暴力for循环了。编写后执行通过，没再想就提交了，可leetcode用了长度为2000的数组，告诉我时间过长。这时候我就想到了工作中的代码问题，最后选择了map命中。这样将本来时间复杂度n*n,o(*2),变成了o。

### 代码

```golang
func findRepeatNumber(nums []int) int {
  hashMap:=make(map[int]bool,0)
  var result int
  for _,v:=range nums{
   if hashMap[v]{
       result=v
       break
   }else{
    hashMap[v]=true
   }
  }
  return result
}
```