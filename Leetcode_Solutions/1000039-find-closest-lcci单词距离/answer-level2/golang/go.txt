### 解题思路
此处撰写解题思路

### 代码

```golang
func findClosest(words []string, word1 string, word2 string) int {
    var (
        result int
        X      int
        Y      int
    ) 
    result = len(words) -1 
    X = -1
    Y = -1
    for i := range words {
        if words[i] == word1 {
            X = i
        }
        if words[i] == word2 {
            Y = i
        }
        if X != -1 && Y != -1 && abs(X-Y) < result{
            result = abs(X-Y)
        }
    }

    return result 
}

func abs(number int) int{
    if number < 0 {
        return -number
    }
    return number
}
```