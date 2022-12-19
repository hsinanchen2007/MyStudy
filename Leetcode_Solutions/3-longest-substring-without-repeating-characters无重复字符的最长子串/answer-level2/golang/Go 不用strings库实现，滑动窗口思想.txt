### 解题思路
1、通过定义两个i，j变量，将j不断的指向下一个元素，并判断原有元素中是否包含j指向的元素，如果不含就将i下移动，同时将j重置为i的下一个下标
2、每次加入新元素都算一下最大值，最后直接返回该值


### 代码

```golang
func lengthOfLongestSubstring(s string) int {
    bytes:=[]byte(s)
    if len(bytes)<=1{
        return len(bytes)
    }
    //设定i,j两个滑动窗口
    i:=0
    j:=0
    //找出所有子串,与最大值进行比较
    // allStr:=[]string{}
    //存放子串
    ret:=[]byte{bytes[0]}
    currMaxLen:=1
    for (i <len(bytes) && j <len(bytes)){
        j++
        // fmt.Println(i,j)
        if j>=len(bytes){
            break
        }
        next:=bytes[j]
        if checkExist(ret,next){
            // allStr=append(allStr,string(ret))
            i++
            ret=[]byte{bytes[i]}
            j=i
        }else{
            ret=append(ret,next) 
        }
        if currMaxLen<len(ret){
            currMaxLen=len(ret)
        }
    }
    // fmt.Println(allStr)
    return currMaxLen
}

func checkExist(ret []byte,target byte)bool{
    for _,v:=range ret{
        if v==target{
            return true
        }
    }
    return false
}
```