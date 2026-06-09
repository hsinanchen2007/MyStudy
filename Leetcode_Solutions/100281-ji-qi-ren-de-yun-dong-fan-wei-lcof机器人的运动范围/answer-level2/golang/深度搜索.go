### 解题思路
打卡

### 代码

```golang
func movingCount(m int, n int, k int) int {
    a:=make([][]int,n)
    for i:=0;i<n;i++{
        a[i]=make([]int,m)
    }

    for i:=0;i<n;i++{
        t:=getNum(i)
        for j:=0;j<m;j++{
            a[i][j]=t+getNum(j)
        }
    }
    return todo(a,0,0,n,m,k)
}

func todo(a [][]int,i,j,n,m,k int)int{
    if i<0||j<0||i>=n||j>=m||a[i][j]==-1{
        return 0
    }
    if a[i][j]<=k{
        a[i][j]=-1
        return 1+todo(a,i-1,j,n,m,k)+todo(a,i+1,j,n,m,k)+todo(a,i,j-1,n,m,k)+todo(a,i,j+1,n,m,k);
    }
    return 0
}

func getNum(n int)int{
    res:=0
    for n!=0{
        res+=n%10
        n/=10
    }
    return res
}
```