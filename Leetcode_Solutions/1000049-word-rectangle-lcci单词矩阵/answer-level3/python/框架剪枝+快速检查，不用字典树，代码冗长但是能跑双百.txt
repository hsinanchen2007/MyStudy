> 原文发布于我的博客： [leetcode-cn 题解 1490. 单词矩阵
](https://blog.by24.cn/archives/leetcode-word-rectangle-lcci.html)

## 解题思路
搭眼一看，这题肯定要上手爆搜。
转念一想，无脑搜索的话，那肯定是准备好了 TLE 等着你，那就要想办法优化或者剪枝。

悄悄瞄了一眼题解，大家都说要用字典树来优化， DFS 上手再剪枝一下就好了嘛。
那我就偏偏不用 (完整的) 字典树来做，而且我还要跑 **双百**，哈哈~~


思路很简单，先构建框架，再构建格栅，最后才做完整的校验。
之所以先构建框架，因为框架是构成矩形最重要的部分，它直接决定了矩形的面积。
也因为框架只需要最少的单词（上下左右四边）即可确定是否成型，便于早早剪枝。

### 构建框架
老样子我们先画个示意图：

![leetcode-1490.png](https://pic.leetcode-cn.com/8ae29b947e6f140638b11f6fcb5e4f07867969b332fd211b0965f0eb147b641c-leetcode-1490.png)


可以看到，只需要先找出 4 个合适的单词，就可以初步构建出一个框架。

按照 上 左 右 下 的顺序：
- 先随便找一条最长的边作为 上边
- 再找一条和上边头部相同的最长边作为 左边
- 找一条头部和上边尾部相同、长度和左边相同的边作为 右边
- 找一条 头等于左边尾，尾等于右边尾，长度等于上边的边作为 下边

如果中间遇到找不到合适的边的情况，说明压根都无法组成矩形，可以直接剪掉。


### 简单检查
接下来，先做个简单的检查，先不管具体的单词排布，只管首尾：

![leetcode-1490 (1).png](https://pic.leetcode-cn.com/ad135c2f7fe3f41873066e68c9e35db3461b52e27d09ecc236723f47fbd89957-leetcode-1490%20\(1\).png)


先检查下，是否存在 头为 E 尾为 F，长度又等于 AB 的单词，如果没有，那直接剪掉。

以此类推，每一横行，每一纵列都先查查看，先这样大大咧咧的剪枝。


### 完整检查
经过上面的剪枝，虽然不能确定框架一定是答案，但至少框架比较稳固了，接下来再对框架进行仔细检查：


![leetcode-1490 (3).png](https://pic.leetcode-cn.com/3fc82cfa901f8f256a0356181b52960af116e3b032c64b54a609cf0414705b46-leetcode-1490%20\(3\).png)


我们取足够的 行 填入矩阵，让每一行都是一个横向上符合规则的单词。

此时，横行的单词其实已经是『免检』状态，因为都是我们自己填进去的，肯定存在。

那么，只需要检查一下，按照这样的排布，纵向是否也符合规定，不符合的话就检查下一种组合。


### 题外话
好了，基本上全部的逻辑就是这些了，按部就班写代码就好了。

那为什么我说自己没有使用 (完整的)字典树 呢？

可以看到，我的这种方式，经常需要查询 `l 长度 s 开头 e 结尾 的单词` 是否存在。

所以我构造了一个三层字典   `word_map[word_length][word_head][word_end][str]` 来加速查找。

这个三层字典，其实也可以理解为掐头去尾后的『另类』字典树，至少思想上是近似的。

## 代码

由于做了比较多的特殊剪枝，所以代码就变的又臭又长了。

这是按照思路整理后的代码，便于观看，虽然跑的慢一点，但也是双百。

```python
class Solution:
    def __init__(self):
        self.words = []

        self.word_map = dict()
        self.word_all = dict()
        self.word_len_max = 2  # 记录最大单词长度，便于后续遍历

        self.ans_rect = None
        self.ans_area = 0  # 记录当前算出的最大面积

    def maxRectangle(self, words: [str]) -> [str]:
        self.words = words
        self.add_word_to_map()
        self.check_up_edge()

        return self.ans_rect

    # 数据初始化
    def add_word_to_map(self):
        for word_pos, word in enumerate(self.words):
            word_length = len(self.words[word_pos])
            word_head = self.words[word_pos][:1]
            word_end = self.words[word_pos][-1:]

            if word_length not in self.word_map.keys():
                self.word_map[word_length] = dict()
            if word_head not in self.word_map[word_length].keys():
                self.word_map[word_length][word_head] = dict()
            if word_end not in self.word_map[word_length][word_head].keys():
                self.word_map[word_length][word_head][word_end] = []
            self.word_map[word_length][word_head][word_end].append(word_pos)

            self.word_all[word] = word_pos
            if word_length > self.word_len_max:
                self.word_len_max = word_length

    # 选取上边并准备进行检查
    def check_up_edge(self):
        for up_edge_len in range(self.word_len_max, 1, -1):
            # 剪枝，如果上边长乘以最长边都得不到更大的面积，那就没必要算下去了
            if up_edge_len * self.word_len_max <= self.ans_area:
                break
            if up_edge_len in self.word_map:
                for up_edge_head in self.word_map[up_edge_len]:
                    for up_edge_end in self.word_map[up_edge_len][up_edge_head]:
                        for up_edge_word_pos in self.word_map[up_edge_len][up_edge_head][up_edge_end]:
                            # up_edge_word_pos 为上边候选，接下来选取左边候选
                            self.check_left_edge(self.words[up_edge_word_pos])

    # 根据上边，选取左边并准备进行检查
    def check_left_edge(self, up_edge_word):
        for left_edge_len in range(self.word_len_max, 1, -1):
            # 剪枝，上边与左边决定了当前矩形的面积
            if len(up_edge_word) * left_edge_len <= self.ans_area:
                break
            if left_edge_len in self.word_map:
                # 左首 等于 上首
                left_edge_head = up_edge_word[:1]
                if left_edge_head in self.word_map[left_edge_len]:
                    for left_edge_end in self.word_map[left_edge_len][left_edge_head]:
                        for left_edge_word_pos in self.word_map[left_edge_len][left_edge_head][left_edge_end]:
                            self.check_right_edge(up_edge_word, self.words[left_edge_word_pos])

    # 根据上边、左边，选取右边并准备进行检查
    def check_right_edge(self, up_edge_word, left_edge_word):
        # 右长 等于 左长，右首 等于 上尾
        right_edge_len = len(left_edge_word)
        right_edge_head = up_edge_word[-1:]

        if right_edge_head in self.word_map[right_edge_len]:
            for right_edge_end in self.word_map[right_edge_len][right_edge_head]:
                for right_edge_word_pos in self.word_map[right_edge_len][right_edge_head][right_edge_end]:
                    self.check_down_edge(up_edge_word, left_edge_word, self.words[right_edge_word_pos])

    # 根据上边、左边、右边，选取下边并准备进行检查
    def check_down_edge(self, up_edge_word, left_edge_word, right_edge_word):
        # 下长 等于 上长，下首 等于 左尾，下尾 等于 右尾
        down_edge_len = len(up_edge_word)
        down_edge_head = left_edge_word[-1:]
        down_edge_end = right_edge_word[-1:]
        if down_edge_head in self.word_map[down_edge_len]:
            if down_edge_end in self.word_map[down_edge_len][down_edge_head]:
                for down_edge_word_pos in self.word_map[down_edge_len][down_edge_head][down_edge_end]:
                    self.check_frame(up_edge_word, left_edge_word, right_edge_word, self.words[down_edge_word_pos])

    # 对构造出的框架进行检查，先粗筛，后细查
    def check_frame(self, up_edge_word, left_edge_word, right_edge_word, down_edge_word):
        # 先做快速检查，同时得到一个包含了全部可能性的数组
        demo_box = self.quick_check(up_edge_word, left_edge_word, right_edge_word, down_edge_word)
        if not demo_box:
            return

        # 接下来做完全检查
        check_ans = self.full_check(demo_box)
        if check_ans:
            self.ans_rect = check_ans
            self.ans_area = len(check_ans) * len(check_ans[0])

    # 快速检查，先粗略的检查框架是否稳固（是否存在符合框架纵横相应长度和首尾的字符串）
    def quick_check(self, up_edge_word, left_edge_word, right_edge_word, down_edge_word):
        # 先查纵列，因为纵列暂时不存
        for col in range(1, len(up_edge_word) - 1):
            if not self.find_str_by(len(left_edge_word), up_edge_word[col:col + 1], down_edge_word[col:col + 1]):
                return None

        # 再查横排，横排顺手存下来（注意每个位置存的都是字符串数组，代表了所有可能）
        demo_box = [[up_edge_word]]
        for row in range(1, len(left_edge_word) - 1):
            find_res = self.find_str_by(len(up_edge_word), left_edge_word[row:row + 1], right_edge_word[row:row + 1])
            if not find_res:
                return None
            else:
                demo_box.append(find_res)
        # 别忘了加上最后一行
        demo_box.append([down_edge_word])
        return demo_box

    # 根据长度和首尾字符，返回匹配字符串数组
    def find_str_by(self, str_len, str_head, str_end):
        if str_len in self.word_map:
            if str_head in self.word_map[str_len]:
                if str_end in self.word_map[str_len][str_head]:
                    return list(map(lambda x: self.words[x], self.word_map[str_len][str_head][str_end]))
        return None

    # 生成并检查全部存在可能的矩形
    def full_check(self, demo_box, line=0):
        # 矩形生成完毕，就拿去检查一下
        if line >= len(demo_box):
            word_box = list(map(lambda x: x[0], demo_box))
            if self.box_check(word_box):
                return word_box
            else:
                return None

        # 因为存在多种可能性，此处递归一下，将每一行处理成只有一种情况
        for str_canbe in demo_box[line]:
            box_copy = copy.deepcopy(demo_box)
            box_copy[line] = [str_canbe]
            check_res = self.full_check(box_copy, line + 1)
            if check_res:
                return check_res
        return None

    # 检查具体的一个个矩形
    def box_check(self, word_box):
        # 四边在生成的时候已经检查过了
        # 横向直接是使用单词生成的
        # 所以只需要检查纵向部分就好
        for col in range(1, len(word_box[0]) - 2):
            check_word = ""
            for row in range(0, len(word_box)):
                check_word += word_box[row][col]
            if check_word not in self.word_all:
                return False
        return True
```



提交结果：
![WechatIMG4046.png](https://pic.leetcode-cn.com/cd3f181d2a2fdc02850b2622424db58c673d069292e921285e91afe65c60d315-WechatIMG4046.png)



其实还有一份想到哪儿写哪儿，写的乱七八糟的代码，避免被吐槽就不放了，那一份其实跑的更快 hhhh

![Snipaste_2020-03-10_20-13-19.png](https://pic.leetcode-cn.com/302cf73dab1fef92989dd9d9165d0469aa9cb5f225693be2b1ef315136db79ea-Snipaste_2020-03-10_20-13-19.png)
