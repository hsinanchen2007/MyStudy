### 解题思路
1：calendars 记录所有不重叠的预订时间；calendarsRepeat记录所有双重预订的时间；
2：根据本次book的时间段time[start,end]，遍历calendars，对于calendars中每个预订时间time0[start,end]，作如下处理：
   2.1：判断time[start,end]和time0[start,end]是否有交集，如果没有，则继续判断calendars中下一个预订时间。
   2.2：计算time[start,end]和time0[start,end]重叠时间段，判断是否和calendarsRepeat中记录时间有重叠，如果有重叠，则本次添加失败，直接退出；如果没有重叠，将本次新产生的重叠         时间段添加到calendarsRepeat中。
   2.3：计算time[start,end]和time0[start,end]非重叠的时间段，每个非重叠时间段再次使用BookFirst方法尝试添加，如果添加失败，则本次任务结束；如果添加成功，将非重叠时间段添加到calendars中。
3：注意，如果添加失败了，记得回退本次处理过程中的数据。

### 代码

```golang

type MyCalendarTwo struct {
    calendars []time
	calendarsRepeat []time
}
type time struct {
	start int
	end int
}

func Constructor() MyCalendarTwo {
    var myCalendarTwo = MyCalendarTwo{calendars:make([]time,0),calendarsRepeat:make([]time,0)}
    return myCalendarTwo
}

func getRepeatTime(s0,e0,s1,e1 int)(start,end int)  {
	start,end = s0,e0
	if start < s1 {start = s1}
	if end > e1 {end = e1}
    return
}
func getSplitTime(s0,e0,s1,e1 int) (res []time){
	if s0 < s1{res =  append(res,time{s0,s1})}
	if e0 > e1{res =  append(res,time{e1,e0})}
    return
}
func (this *MyCalendarTwo) Book(start int, end int) bool {
    oldCalendars,oldCalendarsRepeat := this.calendars,this.calendarsRepeat
    if this.BookFirst(start,end){
    	return true
	}else {
		this.calendars,this.calendarsRepeat = oldCalendars,oldCalendarsRepeat
		return false
	}
}
func (this *MyCalendarTwo) BookFirst(start int, end int) bool {
    for _,t := range this.calendars{
        if end <= t.start || start >= t.end {
            continue
		}
		s,e := getRepeatTime(start,end,t.start,t.end)
        if !this.BookRepeat(s,e){
			return false
		}
		this.calendarsRepeat = append(this.calendarsRepeat,time{s,e})
        tmp := getSplitTime(start,end,t.start,t.end)
        if nil == tmp {
        	return true
		}
        for _,tp := range tmp{
            if !this.BookFirst(tp.start,tp.end){
				return false
			}
		}
		return true
	}
    this.calendars = append(this.calendars, time{start:start,end:end})
	return true
}

func (this *MyCalendarTwo) BookRepeat(start int, end int) bool {
	for _,v := range this.calendarsRepeat{
		if !(start >= v.end || end <= v.start) {
			return false
		}
	}
	return true
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.BookFirst(start,end);
 */
```

![image.png](https://pic.leetcode-cn.com/3988756223a563b493388db1fd817ecd1c6c7ecdf44d3422f8670431734421a4-image.png)
