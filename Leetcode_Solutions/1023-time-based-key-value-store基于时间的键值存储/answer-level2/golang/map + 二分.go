```
type ValueStruct struct {
	Values []string
	Timestamps []int
}

type TimeMap struct {
	MAP map[string]*ValueStruct
}

/** Initialize your data structure here. */
func Constructor() TimeMap {
	m := make(map[string]*ValueStruct)
	return TimeMap{MAP:m}
}


func (this *TimeMap) Set(key string, value string, timestamp int)  {
	if this.MAP[key] != nil {
		this.insertValue(this.MAP[key], value, timestamp)
	}else {
		values := []string{value}
		times := []int{timestamp}
		s := &ValueStruct{Values:values,Timestamps:times}
		this.MAP[key] = s
	}
}

func (this *TimeMap)insertValue(VS *ValueStruct, value string, time int)  {
	VS.Timestamps = append(VS.Timestamps, time)
	if time >= len(VS.Timestamps)-2{
		VS.Values = append(VS.Values, value)
		return
	}
	idx := len(VS.Timestamps)-1
	for i := len(VS.Timestamps)-2; i>=0;i++  {
		if VS.Timestamps[i] > VS.Timestamps[idx] {
			VS.Timestamps[i],VS.Timestamps[idx] = VS.Timestamps[idx],VS.Timestamps[i]
			idx = i
		}
	}
	a := VS.Values[idx:]
	VS.Values = append(append(VS.Values[:idx], value),a...)
}


func (this *TimeMap) Get(key string, timestamp int) string {
	if this.MAP[key] != nil {
		vs := this.MAP[key]
		if len(vs.Timestamps) == 0 || timestamp < vs.Timestamps[0] {
			return ""
		}

		if timestamp >= vs.Timestamps[len(vs.Timestamps) - 1] {
			return vs.Values[len(vs.Values)-1]
		}

		l := len(vs.Timestamps)-1
		left := 0
		right := l-1
		mid := left+(right-left)/2
		for left <= right  {
			mid = left+(right-left)/2
			if vs.Timestamps[mid] <= timestamp {
				if mid == len(vs.Timestamps)-1 || vs.Timestamps[mid+1] > timestamp {
					break
				}
				left = mid+1
			}else {
				right = mid-1
			}
		}
		return vs.Values[mid]
	}else {
		return ""
	}
}
```
