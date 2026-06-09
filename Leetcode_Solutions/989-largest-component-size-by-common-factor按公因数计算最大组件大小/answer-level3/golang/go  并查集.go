### 解题思路
此处撰写解题思路

### 代码

```golang
var temp=make([]int,100010)
//var size=make([]int,100010)
func find(x int) int {
	  for  (temp[x] != x) {
                temp[x] = temp[temp[x]];
                x = temp[x];
            }
            return x;
}

func union(x ,y int){
    a:=find(x)
    b:=find(y)
   
        temp[b]=a
   //     size[b]+=size[a]
 /*   }else{
        temp[a]=b
        size[a]+=size[b]
    }*/
}

func largestComponentSize(A []int) int {
    max:=0
    for i:=0;i<len(A);i++{
        if max<A[i]{
            max=A[i]
        }
    }

    for i:=0;i<max;i++{
        temp[i]=i
      //  size[i]=1
    }
   for _,val:=range A{
       win:=math.Sqrt(float64(val))
       for j:=2;j<=int(win);j++{
           // fmt.Println(val)
           if val%j==0{
               union(val,j)
               union(val,val/j)
           }
       }
   }
    res:=0
   ok:=make([]int,max+1)
    for _,val:=range A{
      //  fmt.Println(val)
        dd:=find(val)
        //fmt.Println(dd)
        ok[dd]++
        if res<ok[dd]{
            res=ok[dd]
        }
    }
    return res

}
```