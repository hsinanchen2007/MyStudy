### 解题思路
此处撰写解题思路
 //x<0直接返回false 
 //1、先取余 得到该轮的加树
 //2、往轮*10+本轮依次类推即可反转
 //3、 x/10 直至=0 
 //4、其他情况就是x=0啦 
### 代码

```golang
func isPalindrome(x int) bool {
    temp:=x 
    var temp_x int
    //x<0直接返回false 
    if x <0  {
        return false
    }else if x>0 {
        //1、先取余 得到该轮的加树
        //2、往轮*10+本轮依次类推即可反转
        //3、 x/10 直至=0      
        for x!=0{
           fan:=x%10
           temp_x=temp_x*10+fan
           x=x/10
        }
        if temp_x==temp {
            return true
        }
    }else {
        //4、其他情况就是x=0啦
        return true 
    }
   return false 
}
```