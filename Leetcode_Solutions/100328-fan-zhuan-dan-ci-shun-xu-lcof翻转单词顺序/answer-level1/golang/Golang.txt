### 代码

```golang
func reverseWords(s string) string {
    res:=""
    for{
        if len(s)>0&&s[0]==' '{
            s=s[1:len(s)]
        }else{
            break
        }
    }
    for{
        if len(s)>0&&s[len(s)-1]==' '{
            s=s[0:len(s)-1]
        }else{
            break
        }
    }
    if len(s)==0{
        return ""
    }
    lo,hi:=len(s)-1,len(s)-1
    for{
        if lo==0{
            res+=s[lo:hi+1]
            break
        }else if s[lo-1]==' '{
            res+=s[lo:hi+1]+" "
            hi=lo-1
            for{
                if s[hi]!=' '{
                    break
                }
                hi--
            }
            lo=hi
        }else{
            lo--
        }
    }
    return res
}
```