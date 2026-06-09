### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def reverseString(s: Array[Char]): Unit = {
     var i=0
    while(i<s.length/2){
      var temp=' '
      temp=s(s.length-1-i)
      s(s.length-1-i)=s(i)
      s(i)=temp
      i+=1
    } 
    }
}
```