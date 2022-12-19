### 解题思路
1、用数组 or 切片
2、用map

### 代码

```golang
func countCharacters(words []string, chars string) int {
    chars1, chars2 := [26]int{}, [26]int{}
    for i := 0;i < len(chars);i++ {
        chars1[chars[i]-'a']++
        chars2[chars[i]-'a']++
    }

    length := 0
    for i := 0;i < len(words);i++ {
        tempLen := 0
        for j := 0;j < len(words[i]);j++ {
            if chars2[words[i][j] - 'a'] <= 0 {
                tempLen = 0
                break
            }
            chars2[words[i][j] - 'a']--
            tempLen++
        }
        chars2 = chars1
        length += tempLen
    }
    return length
}
```
[leetcode的golang AC代码](https://github.com/laijinhang/leetcode-golang/)