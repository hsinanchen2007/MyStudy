### 解题思路
首先Golang的字符串是不可变的，故我们需要采用`unsafe`的方法将其强制转换为可变的`[]byte`
然后我们对字符串进行原地翻转，用了一些小技巧跳过空格
翻转后的字符串能忽略空格并从0开始，例如以下两个案例我们希望能翻转成这样：
`case 1: "  hello world!  "  expect: "!dlrow olleh h  "` 其中结尾的`" h  "`是多余的内容
`case 2: "a good   example"  expect: "elpmaxe doog a a"` 其中结尾的`" a"`是多余的内容
最后我们将每个单词进行翻转即可
### 翻转详细思路
1. 首先我们需要维护一个指针`curLeft`，它指代的是当前遍历到的有效字符串
2. 然后执行一次普通的翻转，从`0`到`len(s) / 2`逐个遍历
3. 在遍历中，我们并不完全的交换头(`i`)尾(`len(s) - i - 1`)元素，而是将头元素无差别地复制到尾，尾元素则需特判是否为单词或空格，然后有选择地复制到`curLeft`处
4. 然后再执行一次遍历，从`len(s) / 2`到`len(s)`逐个遍历
5. 在这一次遍历中，我们则按特判的法则将头(`i`)元素复制到`curLeft`处，即忽略空格复制单词的法则
6. 两次遍历结束后我们得到了一串反转后的字符串，且原先被视为无用的空格被塞在了最尾部，在这里对`curLeft - 1`的元素特判是否为空格，如果是的话需要削掉。
7. 最后再执行一次遍历，从`0`到`curLeft`逐个遍历
8. 最后一次遍历中，我们需要维护双指针`left`和`right`，表示我们找到的一个单词的开始和结束的位置
9. 每当找到一个单词，也就是`left`和`right`之间的元素，对其执行翻转

### 代码

```golang
// 两个强制转换函数，具体方法请翻源码思考，这里不多做解释
func str2bytes(s string) []byte {
    x := (*[2]uintptr)(unsafe.Pointer(&s))
    h := [3]uintptr{x[0], x[1], x[1]}
    return *(*[]byte)(unsafe.Pointer(&h))
}

func bytes2str(b []byte) string {
    return *(*string)(unsafe.Pointer(&b))
}

func reverseWords(s string) string {
    sArr := str2bytes(s)
    sSize := len(sArr)
    mid := sSize / 2
    curLeft := 0  // 维护的一个实际有用长度的指针
    find := false // 表示是否找到单词
    for i := 0; i < mid; i++ {
        // 先将左边元素无条件复制到右边
        tmp := sArr[sSize - i - 1]
        sArr[sSize - i - 1] = sArr[i]

        // 如果发现了单词
        if find {
            // 将当下元素复制到实际的左指针
            sArr[curLeft] = tmp
            curLeft++
            if tmp == 32 {
                find = false // 发现空格后 要将发现单词的状态置否
            }
        } else {
            if tmp != 32 {
                // 否则发现单词，开始复制
                sArr[curLeft] = tmp
                curLeft++
                find = true
            }
        }
    }
    for i := mid; i < sSize; i++ {
        // 到这个循环，字符串的右半边都是反转过的左半边
        // 所以从右半边遍历，按刚刚的方法一个个将元素复制到实际的左指针
        if find {
            sArr[curLeft] = sArr[i]
            curLeft++
            if sArr[i] == 32 {
                find = false
            }
        } else {
            if sArr[i] != 32 {
                sArr[curLeft] = sArr[i]
                curLeft++
                find = true
            }
        }
    }
    // 判断有用长度是否为0
    if curLeft == 0 {
        return ""
    }
    // 判断最后一个元素是不是空格
    if sArr[curLeft - 1] == 32 {
        curLeft--
    }
    find = false
    // 双指针，记录单词的开始下标和结束下表
    left := 0
    right := 0
    for i := 0; i < curLeft; i++ {
        if find {
            if sArr[i] == 32 {
                find = false
                right = i - 1
                // 当发现单词，对left到right执行一次翻转
                for left < right {
                    tmp := sArr[left]
                    sArr[left] = sArr[right]
                    sArr[right] = tmp
                    left++
                    right--
                }
            }
        } else {
            if sArr[i] != 32 {
                find = true
                left = i
            }
        }
    }
    // 最后一个单词被忽略了，这里补回
    right = curLeft - 1
    for left < right {
        tmp := sArr[left]
        sArr[left] = sArr[right]
        sArr[right] = tmp
        left++
        right--
    }
    // 最后将有用长度的字符串返回为答案即可
    return bytes2str(sArr[0:curLeft])
}
```
### 复杂度分析
时间复杂度：$O(N)$，N代表要处理的字符串长度，算法中一共执行2次完整的遍历字符串
空间复杂度：$O(1)$，只用了常数级的额外空间