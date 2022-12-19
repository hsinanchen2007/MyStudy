```
type Node struct {
    dis int
    worker int
    bike int
}

type NodeArr []Node

func (arr NodeArr)Len() int {
    return len( arr )
}

func (arr NodeArr)Swap( i, j int ) {
    arr[i], arr[j] = arr[j], arr[i]
}

func (arr NodeArr)Less( i, j int ) bool {
    if arr[i].dis == arr[j].dis {
        if arr[i].worker == arr[j].worker {
            return arr[i].bike < arr[j].bike
        } else {
            return arr[i].worker < arr[j].worker
        }
    } else {
        return arr[i].dis < arr[j].dis
    }
}

func abs( a int ) int {
    if a >= 0 {
        return a
    }
    return -a
}

func assignBikes(workers [][]int, bikes [][]int) []int {
    bikeVisited := make( []bool, len( bikes ) )
    workerVisited := make( []bool, len( workers ) )
    res := make( []int, len( workers ) )
    record := make( []Node, 0 )
    for i := 0; i < len( workers ); i++ {
        for j := 0; j < len( bikes ); j++ {
            var tmp Node
            tmp.dis = abs( workers[i][0] - bikes[j][0] ) + abs( workers[i][1] - bikes[j][1] )
            tmp.worker = i
            tmp.bike = j
            record = append( record, tmp )
        }
    }
    sort.Sort( NodeArr( record ) )
    for i := 0; i < len( record ); i++ {
        if !bikeVisited[ record[i].bike ] && !workerVisited[ record[i].worker ] {
            res[ record[i].worker ] = record[i].bike
            bikeVisited[record[i].bike] = true
            workerVisited[record[i].worker] = true
        }
    }
    return res
}
```
