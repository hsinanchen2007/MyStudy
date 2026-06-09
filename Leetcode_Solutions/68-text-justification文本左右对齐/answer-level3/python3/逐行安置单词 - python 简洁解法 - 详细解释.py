### 解题思路

一共有一下变量：

  ans   最后的答案

  cur_c 当前行的字母数

  cur_w 当前行的单词数

  wl    当前行的单词列表

然后一个单词一个单词的过，判断加上这个单词是否会超过最大长度，一行的最低长度是：

```python
    cur_c + cur_w - 1
```

如果这个大于 maxWidth，就把这一行加入 ans 中。

所有单词过完了再把余下的词放入最后一行。

再看如何安排每一行的单词：

1. 如果这一行只有一个单词
   单词最对齐，后面补满空格
2. 一行多个单词
   1. 空格正好可以平均分配
      求出平均每个间隔几个空格，直接用 python 字符串的 join 方法就可以了
   2. 有多余的空格
      题目要求左边空格多于右边，先算算平均每个间隔几个空格，然后余下几个，如果平均 b 个，余下 x 个，则前 x 个间隔空 b + 1 个，后面的都空 b 个。

### 代码

```python
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []   # 最后的答案
        cur_c = 0  # 当前行的字母数
        cur_w = 0  # 当前行的单词数
        wl = []    # 当前行的单词列表
        for i, wd in enumerate(words):
            l = len(wd)
            if cur_c + l + cur_w > maxWidth: # 加上这个单词是否会超过最大长度
                if cur_w == 1: # 当前行仅有一个超长的单词，后面全部补空格
                    ans.append(wl[0] + ' ' * (maxWidth-cur_c))
                else:
                    left = maxWidth - cur_c # 这行一共有几个空格
                    if left % (cur_w-1) == 0: # 空格刚好平均分配
                        ans.append((' '*(left//(cur_w-1))).join(wl))
                    else: # 空格不能平均分配
                        x = left % (cur_w-1)  # 多余的空格
                        b = left // (cur_w-1) # 平均每个间隔最少的空格数
                        cans = wl[0]
                        for i in range(x): # 前 x 个间隔空 b + 1 个
                            cans += ' ' * (b+1) + wl[i+1]
                        for i in range(x+1, len(wl)): # 后面的都空 b 个
                            cans += ' ' * b + wl[i]
                        ans.append(cans)
                cur_c = l
                cur_w = 1
                wl = [wd]
            else:
                cur_c += l
                cur_w += 1
                wl.append(wd)

        if cur_w > 0: # 所有单词过完了把余下的词放入最后一行
            cans = ' '.join(wl)
            cans += ' ' * (maxWidth - len(cans))
            ans.append(cans)
        return ans
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)