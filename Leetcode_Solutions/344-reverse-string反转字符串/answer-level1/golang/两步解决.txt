### 解题思路

第一步，使用for循环，将数组`s`里的最后一位`append`进新数组`result`，以此类推
第二步，将新数组`result`里的值复制到数组`s`即可

### 代码

```golang
func reverseString(s []byte)  {
    var result []byte
    for i:=0;i<len(s);i++{
        result = append(result,s[len(s)-i-1])
    }

    for k,v := range result {
        s[k] = v
    }


}
```