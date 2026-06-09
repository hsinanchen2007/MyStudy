func removeDuplicates(nums []int) int {
    n := len(nums)
    if n < 2{  //特殊
        return n
    }
    l, r := 0, 1
    for r < n{
        if nums[l] < nums[r]{ //利用数组有序，未判别的大于等于之前的
            l++
            nums[l] = nums[r]
        } 
        r++
    }
    return l + 1
}