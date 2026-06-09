### 解题思路
看题目分析：把（看成1  把）看成-1 检测到前缀和==0时候  就把字符串分段
之后再去掉每个分段的首尾
( (   ) (  )     )   (   (  )  )
1 1  -1 1 -1   -1    1   1  -1  -1
### 代码

```golang
func removeOuterParentheses(S string) string {
    if len(S)==0{
        return ""
    }

    res:=make([]string,0)
     temp:=make([]string,0)
     temp1:=make([]string,0)
    start:=0
    sum:=0
    for i:=0;i<len(S);i++{
        
        if  S[i]=='('{
            sum+=1
            res=append(res,string(S[i]))
        }else if S[i]==')'{
             res=append(res,string(S[i]))
            sum-=1
        }
        if sum==0{
            temp=append(temp,S[start:i+1])
            start=i+1
        }
    }
    for _,val:= range temp{
        temp1=append(temp1,val[1:len(val)-1])
    }

   
    return strings.Join(temp1,"")
        

}
```