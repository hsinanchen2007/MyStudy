执行用时 :
4 ms
, 在所有 Go 提交中击败了
87.96%
的用户
内存消耗 :
2.8 MB
, 在所有 Go 提交中击败了
100.00%
的用户

### 解题思路
先取到最高点，然后向两边遍历

### 代码

```golang
// import"fmt"

var count int = 0
func trap(height []int) int {
    count = 0
    l :=len(height)
    if l < 2{
        return 0
    }
    i,_ := maxs(height)
    left := height[:i]
     countRainL(left)
    if i + 1 < len(height){
         right := height[i+1:]
           Reverse(&right)
           countRainL(right)
    }
   
   
    // fmt.Println(count)
  
    // fmt.Println(count)
    return count

}

func Reverse(arr *[]int) {
    var temp int
    length := len(*arr)
    for i := 0; i < length/2; i++ {
        temp = (*arr)[i]
        (*arr)[i] = (*arr)[length-1-i]
        (*arr)[length-1-i] = temp
    }
}


func countRainL(height []int) {
    index,value := maxs(height)
   
    for _,v := range height[index:]{
        count += value -v
    }
    if len(height[:index]) >0{
		countRainL(height[:index])
	}
    
}




func maxs (h []int)(index int,value int){
    r := [...]int{0,0}
    for i,v:=range h{
          
        if v > r[1]{
            r[0] = i
            r[1] = v
        }
    }
    return r[0], r[1]
}


```