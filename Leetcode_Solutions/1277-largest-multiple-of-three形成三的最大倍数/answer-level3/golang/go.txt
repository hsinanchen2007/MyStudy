
```golang
func largestMultipleOfThree(digits []int) string {
    sort.Ints(digits) 

    sum := 0 

    for i := range digits{
        sum += digits[i]
    }

    if sum == 0 {
        return "0"
    }

    var result string
    if sum % 3 == 0 {
        result = helper(digits)
    } else if sum % 3 == 1 {
        for i:=0; i < len(digits); i++ {
            if digits[i] % 3 == 1 {
                digits[i] = -1
                result = helper(digits)
                break
            }
        }
        
        if result == "" {
            count := 0
            for i:=0; i < len(digits); i++ {
                if digits[i] % 3 == 2 {
                    digits[i] = -1
                    count++
                }
                if count == 2 {
                    result = helper(digits)
                    break
                }
            }
           
        }
        
    } else {
        for i:=0; i < len(digits); i++ {
            if digits[i] % 3 == 2 {
                digits[i] = -1
                result = helper(digits)
                break
            }
        }

        if result == "" {
            count := 0 
            for i:=0; i < len(digits); i++ {
                if digits[i] % 3 == 1 {
                    digits[i] = -1
                    count++
                }
                if count == 2 {
                    result = helper(digits)
                    break
                }
            }
        }
    }

    return result
}

// 思路1 ： 之和的 变形题

func helper(nums []int) string{
    var result string 

    for i:=len(nums)-1; i >=0; i-- { 
        if nums[i] != -1 {
            result += strconv.Itoa(nums[i]) 
        }
    }
    return result
}
```