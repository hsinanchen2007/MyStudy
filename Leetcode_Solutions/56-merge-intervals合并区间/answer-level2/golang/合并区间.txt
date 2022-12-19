### 解题思路
此处撰写解题思路

### 代码
先排序

然后用merged保存合并后的结果

```golang
func merge(intervals [][]int) [][]int {
    for i :=0;i<len(intervals);i++{
        for j := 0;j<len(intervals)-1-i;j++{
            if intervals[j][0]>intervals[j+1][0]{
                intervals[j],intervals[j+1]=intervals[j+1],intervals[j]
            }
        }
    }
    merged := make([][]int,0)
    for i := 0;i <len(intervals);i++{
        if len(merged)==0 || merged[len(merged)-1][1]<intervals[i][0]{
            merged = append(merged,intervals[i])
        }else{
            if intervals[i][1] > merged[len(merged)-1][1]{
                merged[len(merged)-1][1] = intervals[i][1]
            }
        }
        
    }
    return merged
}
```