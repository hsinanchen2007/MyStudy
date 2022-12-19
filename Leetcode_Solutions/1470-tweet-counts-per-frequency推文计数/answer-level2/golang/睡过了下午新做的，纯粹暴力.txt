简单粗暴的状态模拟，这代码肯定不够简洁，凑合看吧。
写这个其实就是为了证明，这题GO能过，献丑了。
```
type TweetCounts struct {
    Name []string //我也不知道我为什么想定义这个变量，其实没用
    Time [][]int
    Dict map[string]int //免得一次一次找，确认和Time对应
}


func Constructor() TweetCounts {
    return TweetCounts{Name:make([]string,0),Time:make([][]int,0),Dict:make(map[string]int)}
}


func (this *TweetCounts) RecordTweet(tweetName string, time int)  {
    if i,ok:=(this.Dict)[tweetName];ok{
        this.Time[i]=append(this.Time[i],time)
        sort.Ints(this.Time[i])
    }else{
        this.Name=append(this.Name,tweetName)
        this.Time=append(this.Time,[]int{time})
        this.Dict[tweetName]=len(this.Time)-1
    }
}


func (this *TweetCounts) GetTweetCountsPerFrequency(freq string, tweetName string, startTime int, endTime int) []int {
    var length,site,tmpl,tmpr int
    switch freq{
        case "minute":
        site=60
        case "hour":
        site=3600
        case "day":
        site=3600*24
    }
    length=(endTime-startTime)/site+1
    if length==1{
            tmpl=startTime
            tmpr=endTime
    }else{
            tmpl=startTime
            tmpr=startTime+site-1
    }
    ans:=make([]int,length)
    if _,ok:=this.Dict[tweetName];!ok{
        return ans
    } //判断这东西不存在
    count:=0
    for _,j:=range(this.Time[this.Dict[tweetName]]){
        if count==length{
            break
        }
        if j<tmpl{
            continue
        }
        if j>=tmpl&&j<=tmpr{
            ans[count]++
        }else{
            for{
                tmpl=tmpr+1
                if tmpr+site<endTime{
                    tmpr+=site
                }else{
                    tmpr=endTime
                }
                count++
                if (j>=tmpl&&j<=tmpr){
                    ans[count]++
                    break
                }
                if tmpl>endTime{
                    break
                }
            }
        }        
    }
    return ans
    
}


/**
 * Your TweetCounts object will be instantiated and called as such:
 * obj := Constructor();
 * obj.RecordTweet(tweetName,time);
 * param_2 := obj.GetTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
```
