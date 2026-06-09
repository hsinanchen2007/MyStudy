这题主要思路就是二分查找，事件时间按照升序排列，在所有时间中找最后一个小于小要插入的开始时间，找不到的话，如果原来事件列表为空直接插入，不为空的话，说明所有事件都在插入事件的后面，判断第一个事件是否满足插入事件时间，满足则插入，找到的话，判断下一个事件的开始时间是否大于插入事件的结束时间，大于则插入
```
type MyCalendar struct {
	events []Event
}

type Event struct {
	start int
	end   int
}

func Constructor() MyCalendar {
	return MyCalendar{}
}

func (this *MyCalendar) Book(start int, end int) bool {
	//找最后一个结束事件小于等于start的事件
	//idx := this.halfsearch(start, end,0, len(this.events)-1)
	idx := -1
	startIndex := 0
	endIndex := len(this.events)-1
	///最后一个结束时间小于 要插入的开始时间
	for endIndex >= startIndex {
        mid := startIndex + (endIndex-startIndex)/2
		if this.events[mid].end <= start {
			if mid == len(this.events)-1 || this.events[mid+1].end > start {
				idx = mid
				break
			}
			startIndex = mid + 1
		} else {
			endIndex = mid - 1
		}
	}
	event := Event{start: start, end: end}
	//没找到的话，判断第一个数据是否大于要插入的值
	if idx == -1 {
		if len(this.events) == 0 {
			this.events = append(this.events, event)
			return true
		} else {
			firstEvent := this.events[0]
			if firstEvent.start >= end {
				temp := this.events
				this.events = append([]Event{}, event)
				this.events = append(this.events , temp...)
				return true
			}
		}
	}else {
		if idx == len(this.events)-1 {
			this.events = append(this.events, event)
			return true
		} else {
			nextEvent := this.events[idx+1]
			if nextEvent.start >= end {
				temp := this.events
				this.events = append([]Event{}, temp[:idx+1]...)
				this.events = append(this.events, event)
				this.events = append(this.events, temp[idx+1:]...)
				return true
			} else {
				return false
			}
		}
	}
	return false
}
```
