```
func twoSum(numbers []int, target int) []int {
    l,r := 0,len(numbers)-1
    arr := []int{}
    for l<r{
      if numbers[l]+numbers[r]== target{
        arr = []int{l+1,r+1}
        return arr
    }else if numbers[l]+numbers[r]> target{
        r--
      }else{
          l++
      }  
    }
    return arr
}
```
