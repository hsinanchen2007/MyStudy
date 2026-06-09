在回溯法求解全排列的基础上，添加了一个 map 重复，回溯法经典的思想，每次递归中维护一个 map 来检查是否在此阶段将两个相同的数交换了位置，若交换了则必定有所重复。
```Go []
func permuteUnique(nums []int) [][]int {
   	res := [][]int{}
	dfs(nums, &res, 0)
	return res
}

func dfs(nums []int,res *[][]int,index int){
    if index == len(nums){
        *res = append(*res,dump(nums))
    }
    
    m := map[int]int{}
    for i := index;i < len(nums);i++{
        if _,ok:=m[nums[i]];ok{
            continue
        }
        nums[i],nums[index] = nums[index],nums[i]
        dfs(nums,res,index+1)
        nums[i],nums[index] = nums[index],nums[i]
        m[nums[i]]=1
    }
}

func dump(a []int)[]int{
    b := make([]int,len(a))
    copy(b,a)
    return b
}

```