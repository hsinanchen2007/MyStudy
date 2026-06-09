只有获取到最大深度后，才能知道其余元素的深度，故先遍历一次用DFS求出最大深度，然后再遍历一次计算sum，每次递归的时候深度减一即可。
func depthSumInverse(nestedList []*NestedInteger) int {
    depth:=getDepth(nestedList)
    return getSum(nestedList,depth)
}

func getSum(nestedList []*NestedInteger,curDepth int)int{
    var sum int
    for _,ni:=range nestedList{
        if ni.IsInteger(){
            sum+=ni.GetInteger()*curDepth
        }else{
            sum+=getSum(ni.GetList(),curDepth-1)
        }
    }
    return sum
}

func getDepth(nestedList []*NestedInteger)int{
    depth:=1
    for _,ni:=range nestedList{
        if !ni.IsInteger(){
            curDepth:=getDepth(ni.GetList())
            if curDepth+1>depth{
                depth=curDepth+1
            }
        }
    }
    return depth
}