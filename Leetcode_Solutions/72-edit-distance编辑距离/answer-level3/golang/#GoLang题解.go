# DFS实现
```
//DFS实现
func minDistance(word1 string, word2 string) int {
    return dfs(word1,word2,len(word1)-1,len(word2)-1)
}

func dfs(word1 string,word2 string,i,j int)int{
    //出递归条件
    if i==-1 {
        return j+1
    } 
    if j==-1{
        return i+1
    }
    
    if word1[i]==word2[j]{
        return dfs(word1,word2,i-1,j-1)
    }else{
        return min(dfs(word1,word2,i-1,j)+1,dfs(word1,word2,i,j-1)+1,dfs(word1,word2,i-1,j-1)+1)
    }
}


func min(x,y,z int)int{
    if x<=y && x<=z{
        return x
    }else if y<=x && y<=z{
        return y
    }else{
        return z
    }
}
```
# DP实现
```
//DP实现
func minDistance(word1 string, word2 string) int {
    m,n:=len(word1),len(word2)
    dp:=make([][]int,m+1)
    for i:=0;i<m+1;i++{
        dp[i]=make([]int,n+1)
    }
    //初始值
    for i:=0;i<m+1;i++{
        dp[i][0]=i
    }
    for j:=0;j<n+1;j++{
        dp[0][j]=j
    }
    
    for i:=1;i<m+1;i++{
        for j:=1;j<n+1;j++{
            if word1[i-1]==word2[j-1]{
                dp[i][j]=dp[i-1][j-1]
            }else{
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)
            }
        }
    }
    return dp[m][n]
}


func min(x,y,z int)int{
    if x<=y && x<=z{
        return x
    }else if y<=x && y<=z{
        return y
    }else{
        return z
    }
}
```
# DP实现加上输出所走的路线

```
//实现具体的路径
type Node struct{
    val int//代表最少操作数
    choice int//代表操作(0:啥都不干 1:插入 2:删除 3:替换)
}

func minDistance(word1 string, word2 string) int {
    m,n:=len(word1),len(word2)
    dp:=make([][]Node,m+1)
    for i:=0;i<m+1;i++{
        dp[i]=make([]Node,n+1)
    }
    //初始值
    for i:=0;i<m+1;i++{
        dp[i][0].val=i
    }
    for j:=0;j<n+1;j++{
        dp[0][j].val=j
    }
    
    for i:=1;i<m+1;i++{
        for j:=1;j<n+1;j++{
            if word1[i-1]==word2[j-1]{
                dp[i][j].val=dp[i-1][j-1].val
                dp[i][j].choice=0
            }else{
                dp[i][j].val=min(dp[i-1][j].val+1,dp[i][j-1].val+1,dp[i-1][j-1].val+1)
                if dp[i-1][j].val < dp[i][j-1].val && dp[i-1][j].val < dp[i-1][j-1].val{
                    dp[i][j].choice=2
                }else if dp[i][j-1].val < dp[i-1][j].val && dp[i][j-1].val < dp[i-1][j-1].val{
                    dp[i][j].choice=1
                }else{
                    dp[i][j].choice=3
                }
            }
        }
    }
    
    for _,col:=range dp{
        for _,val:=range col{
            fmt.Printf("%d\t",val.choice)
        }
        fmt.Println()
    }
    return dp[m][n].val
}

func min(x,y,z int)int{
    if x<=y && x<=z{
        return x
    }else if y<=x && y<=z{
        return y
    }else{
        return z
    }
}
```
## 求具体路径时发现：word1 = "intention", word2 = "execution"时，路径为交换word1和word2的前5个字符就行
## 说明实现最短路径的方式不止一种，那就有个新问题出来了，如何求最短距离的同时，求解所有满足条件的路径；


# 以上所写内容学习自微信公众号labuladong
![74a9636e10b730c858fedbbfdf415233813f1aba33ea9f3cf354ecf35ad7eac8-file_1570330407052.png](https://pic.leetcode-cn.com/6cc689d3f0347b7f204dd2a4f988b99cb5c5be940b162d12228c1286777f54b6-74a9636e10b730c858fedbbfdf415233813f1aba33ea9f3cf354ecf35ad7eac8-file_1570330407052.png)

