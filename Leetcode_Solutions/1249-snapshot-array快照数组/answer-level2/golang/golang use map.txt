思路： set的时候，使用map记录当前修改的数字和对应当前快照号。 map的key为 
`[2]int{} // snapId + idx` 

get的时候从当前快照号往前找，如果map中有这条记录，说明这是最后一次修改，直接返回即可。如果不存在，继续往前找
```
type SnapshotArray struct {
	snapId int
	snap map[[2]int]int
}


func Constructor(length int) SnapshotArray {
	return SnapshotArray{
		snap: make(map[[2]int]int),
	}
}


func (this *SnapshotArray) Set(index int, val int)  {
	this.snap[[2]int{this.snapId, index}] = val
}


func (this *SnapshotArray) Snap() int {
	this.snapId++
	return this.snapId - 1
}


func (this *SnapshotArray) Get(index int, snap_id int) int {
	for snap_id >= 0 {
		if v, ok := this.snap[[2]int{snap_id, index}]; ok {
			return v
		}
		snap_id--
	}
	return 0
}

```
