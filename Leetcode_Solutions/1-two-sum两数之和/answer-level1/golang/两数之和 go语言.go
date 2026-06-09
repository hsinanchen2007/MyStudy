func twoSum(nums []int, target int) []int {
    dict := make (map[int]int)
    arr := make([]int, 2)
    for idx, num := range (nums){
        idx1, ok := dict[target-num]
        if !ok {
            dict[num] = idx
        }else{
            arr[0] = idx1
            arr[1] = idx
            break;
        }
    }    
    return arr 
}