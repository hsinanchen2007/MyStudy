# 思考


## 字符串遍历

- 从字符串末尾开始向前遍历，其中主要有两种情况
- 第一种情况，以字符串 `"Hello World"` 为例，从后向前遍历直到遍历到头或者遇到空格为止，即为最后一个单词 `"World"` 的长度 `5` 
- 第二种情况，以字符串 `"Hello World"`  为例，需要先将末尾的空格过滤掉，再进行第一种情况的操作，即认为最后一个单词为 `"World"` ，长度为5
- 所以完整过程为先从后过滤掉空格找到单词尾部，再从尾部向前遍历，找到单词头部，最后两者相减，即为单词的长度
- 时间复杂度:O(n)， `n` 为结尾空格和结尾单词总体长度


## Go实现
学习自[elliotxx](https://leetcode-cn.com/problems/two-sum/solution/0ms-de-go-shi-xian-by-elliotxx-2/)

```go
func lengthOfLastWord(s string) int {
    s = strings.Trim(s, " ") // Trim() 去除字符串前后多余空格
    str_list := strings.Split(s, " ") // 用去掉s中出现的sep的方式进行分割，会分割到结尾，并返回生成的所有片段组成的切片
    if len(str_list) == 0 {
        return 0
    } else {
        return len(str_list[len(str_list)-1])
    }
}

func lengthOfLastWord(s string) int {
    str_list := strings.Fields(s) // strings.Fields返回将字符串按照空白分割的多个字符串
    if len(str_list) == 0 {
        return 0
    } else {
        return len(str_list[len(str_list)-1])
    }
}
```