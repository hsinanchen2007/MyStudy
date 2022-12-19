func threeSum(nums []int) [][]int {
    maps := make(map[int]int)
    resultMap:=make(map[string]bool)
    result := make([][]int, 0)
    for i, v := range(nums){
        //从0到i寻找另外两个index,保证两数之和是-v
        for j := 0; j < i;j++{
            //寻找nums[k] = -v-nums[j]
            if v, ok := maps[-v-nums[j]]; ok && v != j{
                entry := make([]int, 0)
                entry = append(entry, nums[i], nums[j], nums[v])
                sort.Ints(entry)
                entryJson,err := json.Marshal(entry)
                if err != nil {
                    panic(err)
                }
                entryStr := string(entryJson)
                if _,ok := resultMap[entryStr];!ok{
                    resultMap[entryStr] = true
                    result = append(result, entry)
                }
            }
        } 
        maps[v] = i
    }
    return result
}
思路：
首先遍历，确定结果三个数中最后面一个数i以及对应数值v
从0遍历到i，对于j，再找到第三个数-v-nums[j]
如果能找到就判断是否重复，不重复则加入
判断过程使用map，将字符串排序后转换成string判断是否重复。
golang香啊