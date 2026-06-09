![image.png](https://pic.leetcode-cn.com/0cc8a2239c78a83f841703472475ac3b165bf9f40e5e6373de898c1bfa6f0e4a-image.png)



### 代码

```golang
func maximum69Number (num int) int {
  
    index := 0
    pos := 0;
    num_org := num
    for num>0{
        pos++
        mod := num%10;
        
        if(mod  == 6){
            index = pos
        }
        fmt.Printf("%#v.%#v\r\n",mod,index)
        num /= 10
    }
   if index > 0 {
       index -=1
       return num_org -6* int(math.Pow10(index)) + 9 *int(math.Pow10(index))
   }
   return num_org
}




```