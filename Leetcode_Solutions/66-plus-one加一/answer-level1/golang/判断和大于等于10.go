### 解题思路
此处撰写解题思路

### 代码

```golang
func plusOne(digits []int) []int {
    n := len(digits)
    pre := 1
    
    for i:= n-1;i>=0;i--{
        pre,digits[i] = plus(digits[i],pre)

        if i == 0 && pre >0 {
            return append([]int{pre},digits...)
        }
        
    }
    return digits
    
}

func plus(v,pre int)(n,m int){
    s := v+pre
    if s >=10{
        return 1,s-10
    }else {
        return 0,s
    }
}
```