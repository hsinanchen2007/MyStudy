```
func detectCapitalUse(word string) bool {
    isMatch,_ := regexp.MatchString("(^[A-Z]+)$|(^[a-z]+$)|(^[A-Z]{1}[a-z]*$)", word)
    return isMatch
}
```
