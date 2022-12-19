func plusOne(digits []int) []int {
    if digits == nil {
        return nil
    }
    if len(digits) == 0 {
        return digits
    }

    result := make([]int, 0)
    left := 0
    for i:=len(digits)-1; i>=0; i-- {
        r := digits[i] + left
        if i == len(digits)-1{
            r = r + 1
        }
       
        if r >= 10 {
            left = 1
            result = append(result, r - 10)
        } else {
            left = 0
            result = append(result, r)
        }
    }

    if left > 0 {
        result = append(result, left)
    }
    
    n := make([]int, 0)
    for i:= len(result)-1;i>=0;i--{
        n = append(n, result[i])
    }
    return n
}