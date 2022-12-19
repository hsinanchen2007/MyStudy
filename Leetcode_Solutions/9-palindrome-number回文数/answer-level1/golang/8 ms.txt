```
func isPalindrome(x int) bool {
    temp :=x

    if x < 0{
        return false
    }

    ans := 0
    for x != 0{

        ans = ans * 10 + x % 10

        if !(-(1 << 31) <= ans && ans <= (1 << 31) - 1){
            return false
        }
        x = x / 10
    }

    if ans == temp{
        return true
    }
    return false 
}
```
