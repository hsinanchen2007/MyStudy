### 解题思路
此处撰写解题思路
go 广度优先解法
利用一个chan当队列
从第0个房间开始  把钥匙放入队列 
每次取队列长度的钥匙 确认房间是否访问过
没访问过的把钥匙存入chan
直到chan为空 退出
检查 是否有房间没访问到

### 代码

```golang
func canVisitAllRooms(rooms [][]int) bool {
    if len(rooms)  == 0 { 
        return true
    }
    check := make([]bool, len(rooms)) 
    cur := 0;
    ch := make(chan int,3000)
    //从房间0开始 把房间0里面的钥匙放进chan
    check[0] = true;
    for _, key := range rooms[0]{
        ch <- key
    }
    
    for (len(ch) != 0) {
        end := len(ch)
        for i := 0; i < end; i++ {
            cur = <-ch
            // 房间没打开过  拿钥匙
            if check[cur] == false {
                check[cur] = true
                for _, key :=  range rooms[cur] {
                    ch <- key
                }
            }
        }
    }
    for _, v := range check {
        if v == false {
            return false
        }
    }
    return true
}
```