### 解题思路
用切片模拟栈来实现

### 代码

```golang
func longestValidParentheses(s string) int {
    var num=1
    var nums []int=[]int{-1}
    var tar int
    for i:=0;i<len(s);i++{

        if s[i:i+1]=="("{
            nums=append(nums,i)
            num++
        }else{           
            nums=nums[:num-1]            
            if len(nums)==0{
                nums=append(nums,i)              
            }else{
                num--
                // fmt.Println("res=",i-nums[num-1])
                tar=res(tar,i-nums[num-1])
            }
        }

    }
    return tar
}

func res(data int,data1 int) int{
    if data>data1{
        return data
    }
    return data1
}
```