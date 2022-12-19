
![image.png](https://pic.leetcode-cn.com/8b2836f3c543aab4794be4cc406e672061ac5dd17d14890ef01638946c703e89-image.png)

因为不能确定输入字符串有多长，即不能确定有多少重循环，所以考虑用递归来处理。

代码
```
var table = map[byte]string{            // 键盘映射表
    '0':" ",'1':"*", '2':"abc",
    '3':"def", '4':"ghi", '5':"jkl",
    '6':"mno", '7':"pqrs", '8':"tuv",
    '9':"wxyz",
}

func dfs(n int, cur string, digits string, ans []string) []string { 
    if n >= len(digits) {               // 所有数字都考虑过了
        if cur != "" {
            ans = append(ans, cur)
        }
        return ans
    }
    buttonChars := table[digits[n]]
    for i:=0; i<len(buttonChars); i++ { // 遍历当前数字可能对应的字母
        ans = dfs(n+1, cur+string(buttonChars[i]), digits, ans)
    }
    return ans
}

func letterCombinations(digits string) []string {
    return dfs(0, "", digits, []string{})
}
```