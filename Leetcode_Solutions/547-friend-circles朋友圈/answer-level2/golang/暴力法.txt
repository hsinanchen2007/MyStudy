```
func findCircleNum(M [][]int) int {
    if len(M)<=0{
        return 0
    }
    res:=0
    queue:=make([]int,0)
    l1 := len(M)
    l2 := len(M[0])
    for i:=0;i<l1;i++{
        for j:=0;j<l2;j++{
            //找到一个朋友圈入口
            if M[i][j]==1{
                res++
                //将所有朋友加入
                queue = append(queue,i,j)
                for len(queue)>0{
                    c := queue[0]
                    queue = queue[1:]
                    for k:=0;k<l2;k++{
                        //消灭该朋友圈
                        if M[c][k]==1{
                            queue = append(queue,k)
                            M[c][k] =0
                        }
                    }
                }
            }
        }
    }
    return res
}
```
