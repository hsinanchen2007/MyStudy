> 原文发布于我的博客： [leetcode-cn 题解 151. 翻转字符串里的单词](https://blog.by24.cn/archives/leetcode-reverse-words-in-a-string.html)

## 解题思路

利用各个语言的内置方法，其实可以简简单单 split 再反转再拼接，但是那也太没意思了。

直接抄起 C 语言，来试试  *O*(1) 额外空间复杂度的原地解法。



先来构造一个样例：`"   hello haha  world! "`

这个样例同时包含了多种多余空格：前导空格、连续空格、尾部空格。

为了便于查看，图示中使用 `#` 来代指空格。

样例看起来就像 `"###hello#haha##world!#"`，在内存中大概是下图这样。

![image.png](https://pic.leetcode-cn.com/a0222363778d502768d83aa8d51393be1cdf28b7ade52d6bb51020ad2e8b7ccd-image.png)


那么我们首先通过对 s 指针进行移动，把前面多余空格跳过。

![image.png](https://pic.leetcode-cn.com/d7b38b04d6d61902297cefbd0f669ce006115aad358b1f8eb8a0cd70da131c1a-image.png)


接下来使用 `left, right` 两个变量，构造窗口寻找单词。

![image.png](https://pic.leetcode-cn.com/9d786c3880519e6b0434e5cb88db5cb3e5e53e825489495b4c59041296ea2d46-image.png)


`right` 找到空格之后，意味着黄色区域为一整个单词。

![image.png](https://pic.leetcode-cn.com/42601a115a642d7bfef8a1a289ab9940a3876c84019b7dcd6b4fe0746955319e-image.png)


对黄色区域进行翻转，翻转完成后将 `left` 指向 `right+1`，也就是下一个单词的开头位置。

![image.png](https://pic.leetcode-cn.com/a7538a6e66cfdb94156d2bef01c0c2288fedd2f687c7af4a5c8e3e699466c580-image.png)


以上是正常情况，接下来处理连续空格的情况，当处理完 `haha` 这个单词的翻转之后， `left` `right` 同时遇到了空格，此时记录一下 `offset`  偏移量。

![image.png](https://pic.leetcode-cn.com/984e07b5c4c7a975d1522cee9ffcecf3bc4249ee4a1a62efaa0ee19c12d41702-image.png)


多余的空格我们先不处理，继续找单词，找到合适的单词准备翻转。

![image.png](https://pic.leetcode-cn.com/c87a03b01ff0c0e75e1e9e61961a998dbcbcae4cf36f3aa8f5dbef67824bef83-image.png)


翻转的时候需要注意，因为 `offset` 的存在，实际上这个翻转过程是斜着的，类似于先将单词平移，再进行翻转。（代码中并不需要两个步骤，合理利用 `offset` 变量即可）

![image.png](https://pic.leetcode-cn.com/35bcb281cde566a84c8f4882e230d09dbbbc8db2a10ab0f5c4249a0b63ffe61d-image.png)


终于，我们跑到了字符串的尾部，也就是 `\0` ，需要注意的是，如果尾部紧跟着空格， `offset` 标记也要自增。

![image.png](https://pic.leetcode-cn.com/26458c8637142171c347905e610cf27e65b08950b0ee56c7c76c4af42728a9d5-image.png)


接下来的工作就很轻松了，我们首先处理长度，`offset` 标记告诉我们，这个字符串里有两个多余的空格，所以我们直接算出合适的位置，将字符串截断一下。

![image.png](https://pic.leetcode-cn.com/b04d5907db40487482412d9ddef33afd3476a1c89c82c6d7212452fc91137d71-image.png)


然后，将整个字符串翻转一下就搞掂啦~

![image.png](https://pic.leetcode-cn.com/3c9232bd37532bcb0b12590a3f2a2710046912aa87bdb60cca27d34db42ff22e-image.png)




## 解答
C 代码
```c
char *reverseWords(char *s) {
    // 处理特殊情况
    while (s[0] == ' ')
        s += 1;
    if (s[0] == '\0')
        return s;

    int offset = 0, left = 0, right = 0;
    while (++right) {
        if (s[right] == ' ' || s[right] == '\0') {
            if (right == left) {    
                // 遇到连续空格
                offset += 1;    
            } else {
                // 遇到单词，将单词倒序，注意 offset          
                for (int i = 0; i < (right - left + offset + 1) / 2; i++) {
                    char tmp = s[left + i - offset];
                    s[left + i - offset] = s[right - 1 - i];
                    if (i >= offset)
                        s[right - 1 - i] = tmp;
                }
                // 注意补空格
                if (offset != 0)    
                    s[right - offset] = ' ';
            }
            // 将 left 指到下一个单词的开头
            left = right + 1;       
        }
        if (s[right] == '\0')
            break;
    }

    // 截断字符串
    right -= offset;
    s[right] = '\0';    
    // 将字符串倒序
    for (int j = 0; j < right / 2; j++) {
        char tmp = s[j];
        s[j] = s[right - 1 - j];
        s[right - 1 - j] = tmp;
    }
    return s;
}
```



实际上，对字符串倒序的时候也可以不声明 `j` 变量，也可以直接用 `right` `left` 双向，不过影响不大就不折腾了。



原地解法效率不错，轻松双百：

![image.png](https://pic.leetcode-cn.com/eef1a7b2d3be6383fd50de6f9a574e958cf188b459e7ad4dfd38eba15743f716-image.png)
