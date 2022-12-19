1. 利用元组存储已经添加的日程
2. 在新的加入的时候遍历已添加的进行区间交错的比较
```
class MyCalendar {

    init() {
        
    }
    
    var calendars:[(Int,Int)] = []
    func book(_ start: Int, _ end: Int) -> Bool {
        for item in calendars {
            if start >= item.0 && start < item.1 {
                return false
            }
            if end > item.0 && end < item.1 {
                return false
            }
            if start < item.0 && end >= item.1 {
                return false
            }
        }
        calendars.append((start,end))
        return true
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * let obj = MyCalendar()
 * let ret_1: Bool = obj.book(start, end)
 */
```
