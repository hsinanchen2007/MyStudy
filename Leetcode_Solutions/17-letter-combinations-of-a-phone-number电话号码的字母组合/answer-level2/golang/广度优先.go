### 解题思路
#### 广度优先搜索
比起深度优先更加简单和高效，几乎无中间内存使用。

+ 执行用时 : 0 ms, 在所有 golang 提交中击败了100.00%的用户
+ 内存消耗 : 2 MB, 在所有 golang 提交中击败了100.00%的用户

```go
var table []string = []string {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    result := []string{""}

    for i := 0; i < len(digits); i++ {
        t := table[digits[i] - '0']
        temp := []string{}
        for j := 0; j < len(t); j++ {
            for z := 0; z < len(result); z++ {
                temp = append(temp, result[z] + string([]byte{t[j]}))
            }
        }
        result = temp
    }

    return result
}
```

### 代码

```golang
var table []string = []string {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}

func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    result := []string{""}

    for i := 0; i < len(digits); i++ {
        t := table[digits[i] - '0']
        temp := []string{}
        for j := 0; j < len(t); j++ {
            for z := 0; z < len(result); z++ {
                temp = append(temp, result[z] + string([]byte{t[j]}))
            }
        }
        result = temp
    }

    return result
}



/**
    这题使用广度优先搜索比较简单

*/
```