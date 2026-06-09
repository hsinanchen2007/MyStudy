```
func intersection(nums1 []int, nums2 []int) []int {
    nums1 = sortAndUniq(nums1)
    nums2 = sortAndUniq(nums2)
    
    var len1, len2 = len(nums1), len(nums2)
    length := min(len1, len2)
    
    var result []int
    if length == 0 {
        return result
    }
    
    var i, j int
    for {
        
        if nums1[i] == nums2[j] {
            result = append(result, nums1[i])
        }
        
        if nums1[i] > nums2[j] {
            j++
        } else {
            i++
        }
        
        if i >= len1 || j >= len2 {
            break
        }
        
    }
    
    return result
    
}

func min(num1, num2 int) int {
    if num1 > num2 {
        return num2
    } else {
        return num1
    }
}

func sortAndUniq(nums []int) []int {
    var result []int
    if len(nums) == 0 {
        return result
    }
    
    sort.Ints(nums)
    last := nums[0]
    result = append(result, last)
    for _, num := range nums[1:] {
        
        if num != last {
            result = append(result, num)
            last = num
        } 
        
    }
    
    return result
}
```
