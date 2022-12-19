```
先分割text为单词字符串切片
然后开始遍历单词切片
如果指针指向的 当前单词和后一个单词与first和second匹配，那么添加第三个单词，将指针指向第三个单词
否则移动指针到下一个单词
注意：数组下标超限问题
```
```
func findOcurrences(text string, first string, second string) []string {
    temp := strings.Split(text," ")
    var res []string
    for i:= 0; i < len(temp)-2;{
        if temp[i] == first && temp[i+1] == second{
            res = append(res, temp[i+2])
            i +=2 
        }else{
            i++
        }
    }
    return res
}
```

![image.png](https://pic.leetcode-cn.com/091990f599c9a9e5585e0f5c076962636fa3296288120daff3af3bd0f5ed713a-image.png)