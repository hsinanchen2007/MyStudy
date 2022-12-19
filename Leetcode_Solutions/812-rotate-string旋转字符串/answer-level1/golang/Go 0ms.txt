```
func rotateString(A string, B string) bool {
    lenA := len(A)
    lenB := len(B)
    if lenA != lenB{
        return false
    }
    if lenA == 0{
        return true
    }
    for i:= 0; i < lenA; i++{
        temp, j := i, 0
        for j < lenB{
            if A[temp%lenA] != B[j]{
                break
            }
            temp++
            j++
        }
        if j == lenB{
            return true
        }
    }
    return false    
}
```