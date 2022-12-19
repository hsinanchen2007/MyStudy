### 解题思路
思路如下：
    1.对原数组intervals按元素中首元素大小排序
    2.申请一个切片：[][]int{},用于存储合并后的值。
    3.依次遍历排序后的数组，每遍历一个，判断这个元素是否的左区间是否大于上一个元素的右区间
        3.1 若大于，则在这两个区间中找到的四个数中，找到最小值为左值left，最大值为右值right(程序中的判断方法只是其中一种)，修改res最后一个元素
        3.2 若不大于，则将这个元素直接添加到res中
    4.返回res

### 代码

```golang
func merge(intervals [][]int) [][]int {
    res:=[][]int{}
    if len(intervals)==0{
        return res
    }

    //1 go语言排序语法
    sort.Slice(intervals,func(i,j int)bool{  
                            return intervals[i][0]<intervals[j][0]
                                })
    //2 申请空间res
    res=append(res,intervals[0])
    
    i:=1
    //3.开始遍历
    for i<len(intervals){
        resEnd:=res[len(res)-1]
        //2.1 大于，找到left和right，然后修改res最后一个元素
        if resEnd[len(resEnd)-1]>=intervals[i][0]{
            left:=resEnd[0]
            right:=max(resEnd[len(resEnd)-1],intervals[i][len(intervals[i])-1])
            res[len(res)-1]=[]int{left,right}
        }else{//2.3 不大于直接添加
            res=append(res,intervals[i])
        }
        i++
    }

    return res
}

func max(a,b int) int{
    if a<b{
        return b
    }

    return a
}
```