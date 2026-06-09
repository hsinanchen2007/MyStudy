步骤：
　　（1）初始化一个大小为numCourses的数组indegree；
　　（2）将图中个节点的入度保存到数组中，将数组中第一个入度为0的节点找出，并将该节点在数组中的值设为-1，将数组中所有以该顶点为入度的顶点入度减一，将其push到vector中；
　　（3）重复（2）numCourses次，若期间在indegree数组中没有找到入度为0的顶点，则返回空;

```
func findOrder(numCourses int, prerequisites [][]int) []int {
    outDegree := make([]int,numCourses) //存储每门课的入度
    linkTable := make([][]int,numCourses)
    for _,v := range prerequisites {
        from := v[1]
        to := v[0]
        linkTable[from] = append(linkTable[from],to)
        outDegree[to]++
    }

    helper := []int{} //模拟辅助queue
    for i,v := range outDegree {
        if v==0 {
            helper=append(helper,i)
        }
    }
    
    for i := 0;i < len(helper);i++ {
        for _,v := range linkTable[helper[i]] {
            outDegree[v]--
            if outDegree[v] == 0{
                helper=append(helper,v)
            }
        }
    }
    if len(helper) != numCourses {
        return []int{}
    }
    return helper
}
```
