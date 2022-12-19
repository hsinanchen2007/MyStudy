
![屏幕快照 2019-08-08 21.47.17.png](https://pic.leetcode-cn.com/1cd5d182a0dc56daed843a4bfb6562314194ca3f73f8c022d963701ef0e1fcc2-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-08-08%2021.47.17.png)

简单的空间换时间，多用了个slice记录议员有效状态

func predictPartyVictory(senate string) string {
    rc,dc := 0,0//双方阵营活着的议员
    rd,dd := 0,0//双方阵营需要“死亡”的议员
    cache := make([]int,len(senate))
    for _,c := range senate {
        if c == 'R'{
            rc++
        }else {
            dc++
        }
    }
    for ;rc!=0&&dc!=0 ;{
        for i,c:= range senate{
            if cache[i]!=0{
                continue
            }
            switch c{
                case 'R':
                if rd>0 {
                    rd--
                    rc--
                    cache[i]=1
                }else {
                    dd++
                }
                case 'D':
                if dd>0 {
                    dd--
                    dc--
                    cache[i]=1
                }else {
                    rd++
                }
            }        
        }
    }
    if rc == 0{
        return "Dire"
    }
    return "Radiant"
}