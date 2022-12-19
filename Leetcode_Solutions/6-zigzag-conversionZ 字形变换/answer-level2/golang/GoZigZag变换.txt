### 解题思路
这里我用的思路很简单，用一个二维存储把旋转访问的变量存起来，再按序读取出来就行了。可以用[]string或者我用的[]bytes.Buffer，但是go中的string是不可变的，每次+=都会生产新的，效率很低，所以我采用的是bytes.Buffer，不是特别在乎时间的，其实都可以

### 代码

```golang
func convert(s string, numRows int) string {
    if numRows <= 1 {
        return s
    }

    vec := make([]bytes.Buffer, numRows)
    for i, length := 0, len(s); i < length; {
        //column
        for j := 0; j < numRows && i < length; j++ {
            vec[j].WriteByte(s[i])
            i++
        }

        //row
        for j := numRows - 2; j > 0 && i < length; j-- {
            vec[j].WriteByte(s[i])
            i++
        }
    }

    ans := bytes.Buffer{}
    for _, rStr := range vec {
        ans.Write(rStr.Bytes())
    }
    return ans.String()
}
```