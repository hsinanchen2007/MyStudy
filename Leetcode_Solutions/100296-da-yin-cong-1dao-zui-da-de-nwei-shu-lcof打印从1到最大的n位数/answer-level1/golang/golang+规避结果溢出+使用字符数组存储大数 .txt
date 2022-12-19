
 剑指offer原题考点是， 考虑结果溢出问题，故打印结果应为字符串。
 代码可在本地ide上运行
```
func printNumbers(n int) {
    if n==0 {
        return 
    }
    arr :=make([]byte,n)
    for i := range arr {
        arr[i]='0'
    }
    
    for !isFinished(arr) {
        print(arr)
    }
}

func isFinished(arr []byte) bool{
    
    var (
      overNum int 
    )
    n := len(arr)
    
    for i:=n-1;i>=0; i-- {
        num := int(arr[i]-'0')+overNum
        if i==n-1{
            num++
        }
        
        if num >= 10 {
            if i==0 {
                return true
            }else{
                overNum=1
                arr[i]='0'
            }
        }else{
            arr[i]=byte(num+'0')
            break
        }
    }
    return false
}

func print(arr []byte){
    var flag bool
    for i:=0;i<len(arr);i++{
        if arr[i] != '0' && !flag{
            flag=true
        }
        if flag{
            fmt.Printf("%s\n",arr[i:])
            break
        }
    }
}
```
