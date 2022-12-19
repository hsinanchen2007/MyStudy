1.递归
```
func letterCombinations(digits string) []string {
    if digits == "" {
        return []string{}
    }

    nlMap := map[byte]string{
        '2': "abc",
        '3': "def",
        '4': "ghi",
        '5': "jkl",
        '6': "mno",
        '7': "pqrs",
        '8': "tuv",
        '9': "wxyz",
    }

    res := []string{}
    search("", digits, 0, &res, nlMap)

    return res
}

func search(s, digits string, i int, res *[]string, nlMap map[byte]string) {
    //terminator
    if i == len(digits) {
        *res = append(*res, s)
        return
    }

    //process logic of current level
    letters := nlMap[digits[i]]
    for j := 0; j < len(letters); j++ {
        //drill down
        search(s+fmt.Sprintf("%c",letters[j]), digits, i+1, res, nlMap)
    }

    //reverse
}
```
