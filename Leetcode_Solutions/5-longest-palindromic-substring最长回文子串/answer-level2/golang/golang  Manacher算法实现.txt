【转】Manacher算法的详细讲解 - 简书 https://www.jianshu.com/p/116aa58b7d81
相似的Golang实现

```
import "fmt"
func longestPalindrome(s string) string {
    n:=len(s)
    if(n<2){
        return s
    }
    shaped_str:=string_shape(s)
    //在字符间的空位插入井号，便于检索位置
    palinds:=make([]int,2*n+1)
    R,C:=-1,-1 
    max_palind_length:=0
    posi:=0
    for i:=0 ; i < n*2+1 ; i++{
        palinds[i]=1
        if(R>i){
            palinds[i]=Min(palinds[2*C-i],R-i+1)
        }
        for{
            if(i+palinds[i]>= 2*n+1 || i<palinds[i]){
                break
            }
            if(shaped_str[i-palinds[i]]==shaped_str[i+palinds[i]]){
                palinds[i]++
            }else{
                break
            }

        }
        if(i+palinds[i]>R){
            R=i+palinds[i]-1;
            C=i;
        }
        if(palinds[i]>max_palind_length){
            max_palind_length=palinds[i]
            posi=i
        }
    }
 
    
    
    if(posi%2==1){
        posi/=2
        max_palind_length=max_palind_length/2-1
        s=s[(posi-max_palind_length):(posi+max_palind_length+1)]
    }else{
        posi/=2
        max_palind_length/=2       
        s=s[(posi-max_palind_length):(posi+max_palind_length)]
    }
        

    return s
}

func string_shape(s string)string{ //这个函数用来在字符间的空位插入井号
    out_str:="#" 
    for _, v := range s {
        out_str+=string(v)+"#"
    }
    return out_str
}

func Min(x, y int) int {
    if x < y {
        return x
    }
    return y
}
```
