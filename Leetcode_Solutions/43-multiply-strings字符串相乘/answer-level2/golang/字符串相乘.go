### 解题思路
注释

### 代码

```golang
func multiply(num1 string,num2 string) string{

    if (len(num1)==1 && num1[0]=='0') || (len(num2)==1 && num2[0]=='0'){
        return "0"
    }

    var res int      
    var rest string
    //先从最后的len（num1）-1开始循环
    for i:=len(num1)-1;i>=0;i--{
        var ans string
        var end string
        var temp int
        var carry int
        for j:=len(num2)-1;j>=0;j--{//与num2相乘
            res=int(num2[j]-'0')*int(num1[i]-'0')+carry
            carry=res/10
            temp=res%10

            ans=string(temp+'0')+ans
        }

        if carry !=0{
            ans=string(carry+'0')+ans
        }
        k:=0//num1="34",num1[i]=4的话，end为空，当num1=3时，end=“0”，以此类推,相当于（30+4）*num2
        for k<len(num1)-1-i{
            end+="0"
            k++
        }
        
        rest=addstr(rest,ans+end)

        
    }
    return rest
}

//两个字符串相加得到的数
func addstr(num1 string,num2 string) string{

    var temp int
    var ans string
    i:=len(num1)-1
    j:=len(num2)-1
    for i>=0 || j>=0{
        var n1 int
        var n2 int
        if i>=0{
            n1=int(num1[i]-'0')
        }else{
            n1=0
        }

        if j>=0{
            n2=int(num2[j]-'0')
        }else{
            n2=0
        }
        
        res:=n1+n2+temp

        temp=res/10

        res%=10

        ans=string(res+'0')+ans
        i--
        j--
    }

    if temp != 0{
        ans="1"+ans
    }

    return ans
}
//这个是先一个一个地转成整数再相乘，可是int长度达到一定时会溢出，只能算小一点的数，大的数无法用此方法
// func multiply(num1 string, num2 string) string {
//     if len(num1)==1 && num1[0]=='0' || len(num2)==1 && num2[0]=='0'{
//         return "0"
//     }
//     var n1 int
//     var temp int
//     for i:=0;i<len(num1);i++{
//         n1=n1*10+int(num1[i]-'0')
//     }
    
//     for i:=0;i<len(num2);i++{
//         temp=temp*10+int(num2[i]-'0')
//     }

//     res:=n1*temp
//     var ans string
//     var n2 int
//     for res !=0{

//         n2=res%10
//         ans+=string(n2+'0')
//         res/=10

//     } 
   
//     return digui(ans)
// }

// func digui(str string)string{

//     if len(str)==1{
//         return str
//     }

//     return str[len(str)-1:]+digui(str[:len(str)-1])

// }
```