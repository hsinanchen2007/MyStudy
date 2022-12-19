仔细考虑课程之间每种可能性
```
type MyCalendarThree struct {
    l *list.List
    maxOrder int
}

type book struct {
    start, end int
    times int
}

func Constructor() MyCalendarThree {
      return MyCalendarThree{
        l: list.New(),
    }
}

func (this *MyCalendarThree) Book(start int, end int) int {
    return this.bookByEle(start, end, this.l.Front())
}

func (this *MyCalendarThree) bookByEle(start int, end int, e *list.Element) int {
    b := book{start, end, 1}
    for ; e != nil; e = e.Next() {
        now, _ := e.Value.(book)
        // c d a b
        if b.end <= now.start {
            this.l.InsertBefore(b, e)
            break
        }
        // a b c d
        if b.start >= now.end {
            continue
        }
        // c a d b
        if b.start <= now.start && b.end <= now.end {
            same := book{now.start, b.end, now.times+1}
            if same.times > this.maxOrder {
                this.maxOrder = same.times
            }
            if b.start < now.start {
                t := book{b.start, now.start, 1}
                this.l.InsertBefore(t, e)
            }
            this.l.InsertBefore(same, e)
            if b.end < now.end {
                t := book{b.end, now.end, now.times}
                this.l.InsertBefore(t, e)
            }
            this.l.Remove(e)
            break
        }
        // a c d b
        if b.start >= now.start && b.end <= now.end {
            same := book{b.start, b.end, now.times+1}
            if same.times > this.maxOrder {
                this.maxOrder = same.times
            }
            if b.start > now.start {
                t := book{now.start, b.start, now.times}
                this.l.InsertBefore(t, e)
            }
            this.l.InsertBefore(same, e)
            if b.end < now.end {
                t := book{b.end, now.end, now.times}
                this.l.InsertBefore(t, e)
            }
            this.l.Remove(e)
            break
        }
        // a c b d
        if b.start >= now.start && b.end >= now.end {
            same := book{b.start, now.end, now.times+1}
            if same.times > this.maxOrder {
                this.maxOrder = same.times
            }
            if now.end == b.end {
                break
            }
            this.bookByEle(now.end, b.end, e.Next())
            if now.start < b.start {
                t := book{now.start, b.start, now.times}
                this.l.InsertBefore(t, e)
            }
            this.l.InsertBefore(same, e)
            this.l.Remove(e)
            break
        }
        // c a b d
        if b.start <= now.start && b.end >= now.end {
            same := book{now.start, now.end, now.times+1}
            if same.times > this.maxOrder {
                this.maxOrder = same.times
            }
            if now.end == b.end {
                break
            }
            this.bookByEle(now.end, b.end, e.Next())
            if b.start < now.start {
                t := book{b.start, now.start, 1}
                this.l.InsertBefore(t, e)
            }
            this.l.InsertBefore(same, e)
            this.l.Remove(e)
            break
        }
    }
    this.l.PushBack(b)
    if b.times > this.maxOrder {
        this.maxOrder = b.times
    }
    return this.maxOrder
}
```
