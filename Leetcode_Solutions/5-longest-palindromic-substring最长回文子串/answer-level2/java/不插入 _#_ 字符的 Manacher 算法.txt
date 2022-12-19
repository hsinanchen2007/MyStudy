> 原文发布于我的博客： [最长回文子串——Manacher 算法](https://blog.by24.cn/archives/manacher.html)  
---

### 前言
前面在做 leetocode 的 [最长回文子串][1] 题目时，使用了  *O*(*n*²）的算法，性能不如人意，翻看题解看到了 Manacher 算法（马拉车算法），可以做到  *O*(*n*）的时间复杂度，赶紧了解记录一下。

## 基础知识


想要更好的理解马拉车算法，先了解两个与之相关的基础知识是很有必要的。

### 插入分隔符

马拉车算法会先对字符串做一个预处理：在每个字符间隔插入分隔符，此处以`#`作为示例

![image.png](https://pic.leetcode-cn.com/a46c3e1fa8149e2bccf1b6e4b8bab00d5db5eac590a0a638ef5af4619d9ba0d4-image.png)

插入分隔符可以带来以下好处：

- 分隔符将原有的两种回文形式统一为一种，便于统一查找。
  - `abba` 和 `aba`这两种形式，中心字符数分别为 2 和 1，带来不便

- 分隔符不会破坏原有的回文字符串，原本就是回文的，仍然是回文。
  - 此处需要注意，分隔符需要选择原字符串中未出现过的字符。



那么我们先构造一个测试数据 `s = "aaccbdbccec" `备用，先按照本节进行分隔符预处理：

![image.png](https://pic.leetcode-cn.com/8a16f679a846048cfc307995d362ccc02b963f76e9291638839260cd64fa8a01-image.png)


### 回文对称原则

简单来说就是，如果一个回文的左半部分包含一个回文，那它右侧一定包含着一个相同的回文。

还是用上面的测试数据 `s = "aaccbdbccec" `，我们来看一下示意：

![image.png](https://pic.leetcode-cn.com/972d7c1b689a275879ac32a6c54f6efae37e049c758e1fe58197ee8ff45cf179-image.png)


第一行中，标注蓝色的是一个完整的回文 `#c#c#b#d#b#c#c#`，回文的中心为 `s[11]`

第二行中，深绿色部分是一个已知的回文 `#c#c#`，回文的中心为 `s[6]`

很显然，在右边与它相对称的位置，一定存在一个相同的回文，中心为 `s[16]`



当然，此处我们需要注意两种特殊情况，我们修改一下测试样例来看：

#### 左侧子回文太长越界

![image.png](https://pic.leetcode-cn.com/4450ecbbeb01bc805c6a992d5349095a57eb833fc3efdb12018b46e05e5f8555-image.png)


可以看到，修改样例之后，左侧子回文的边界，已经超出了上面的父回文的边界，此时，右边就未必是完全等同长度的回文了。

也就是说，超出父回文边界的红色字符需要被排除在外，我们找到的回文只能在父回文边界内。

#### 右侧子回文比左侧子回文长度更长

![image.png](https://pic.leetcode-cn.com/6f2e69446ad98d00df74c2bd5448876d9b2189aabc99b40692c6b21bce2e4c2a-image.png)


和上述情况类似，只是这次是右侧更长，也就是说，我们通过左侧回文推断出的右侧子回文，虽然确实是回文，但并不一定就是最长的那个。

如果我们需要确认右侧的回文最长有多长，就需要自己从越界部分的红色字符重新尝试。

## 开始马拉车

好了，知道前面两个，其实马拉车算法已经基本成型了，马拉车算法说白了就是什么呢？



- 把以当前这个位置为中心，最长的回文找出来。
  - 如果当前位置处于某个回文的右半边，那么只需要先照搬对称侧的答案
    - 从答案标定的位置，再复查下有没有更长的
  - 如果当前位置没什么特殊的，就正常查找
- 找下一个位置



那马拉车为什么能省时间呢？

**因为每当你走上『前人已经走过的路』，就能得到锦囊一枚，可以跳过大量无须判断的格子。**

平均下来来看，虽然也需要套两层循环，但是大部分内层循环并不需要左右观望就可以退出，马拉车的时间复杂度可以被粗略认为是   *O*(*n*）级别。



你以为接下来就是写代码了嘛？nonono，我偏不按常理出牌

### 我偏不加你这分隔符

翻了许多关于马拉车的介绍，基本上一开篇都是在介绍插入分隔符，而且大部分插入的都是 `#`这个字符。

且不论性能损耗问题，关键是 leetcode 上的这道题，**并没有说字符串内不会出现 `#`字符啊**。

从严谨考虑的角度来说，题目没给这个条件，就不能臆测它不包含某个字符。

那么，不用分隔符行不行呢？我赶紧又画了两张示意图：

![image.png](https://pic.leetcode-cn.com/97572e1079242d581a04b30bc9b9dd0bd3990002291699a9a5669632901f7694-image.png)

![image.png](https://pic.leetcode-cn.com/206d2ef1129c66371fd539a70cf9c800ef1a7ddac8b1c61e1a94072a88d7b96e-image.png)


这样看起来，好像也没什么区别嘛，无非就是两种情况分别处理嘛。

这里需要注意的是，对于双中心的回文，在对称后，下标需要处理。

那就这么决定了，代码按照这样写吧，不加那些分隔符了。

## 代码

还是老样子，很多细节暂时懒得去优化了，凑合着用

```java
class Solution {
    int max_left = 0, max_mid = 0, max_right = 0, max_flag = 0; //记录最长回文

    // 和原版一致，先弄个 R 数组出来。代表每个 center 能拓展多长的回文出来
    // R 的下标计算方式为 pos * 2 + flag
    // flag 为 0，R 下标为偶数的时候，代表这是个奇数回文
    // R 的取值为半边侧翼的长度
    int[] R;
    char[] str;

    public String longestPalindrome(String s) {
        if (s.length() <= 1)
            return s;

        // 考虑到间隙，R数组的容量需要增加
        R = new int[s.length() * 2];
        str = s.toCharArray();

        for (int i = 0; i < s.length(); i++) {
            if ((str.length - i) * 2 <= max_right - max_left + 1)
                break;
            check(i, 0);
            check(i, 1);
        }

        return s.substring(max_left, max_right + 1);
    }

    //flag 为 1，代表查找偶数回文，pos 是第一个字符
    //flag 为 0，代表查找奇数回文，pos 是中间的字符
    public void check(int pos, int flag) {
        int step = 0;
        // 可重复利用先前数据
        if (pos > max_mid && pos < max_right){
            int look = (max_mid - (pos - max_mid) - flag) * 2 + flag;
            if (look > 0)
                step = Math.min(R[look] , max_right - max_mid);

            // TODO 如果左侧回文完全包含于大回文，其实可以不用看了
        }

        for (; step < str.length - pos; step++) {
            int left = pos - (step + 1) + flag;
            int right = pos + (step + 1);
            if ((left < 0 || right >= str.length) ||   // 越界
                    (str[left] != str[right]))    // 非回文
                break;
        }

        // 将 step 写入 R[] ，并判断是否更长了
        R[pos * 2 + flag] = step;
        if (step * 2 + (flag+1) % 2 > max_right - max_left + 1) {
            max_mid = pos;
            max_left = pos - step + flag;
            max_right = pos + step;
            max_flag = flag;
        }

    }
}
```



提交之后比之前还算是提升了不少，耗时变成了 10 ms

![](https://pic.leetcode-cn.com/d6e7b88b254d57f614bfc5609e595844a48d3b7c6e8768aa5482a5d90b568692-file_1583867876684)


也许你会问，怎么还有 21% 的代码跑的更快呢？
这一方面是因为我上面的代码写的比较粗糙，另一方面其实也和 leetcode 的测试用例有关。
查看一下跑的更快的题解可知，都针对『连续重复字符』采取了特殊处理，恰好 leeetcode 的测试用例中这类数据占比比较大，从而取得了更大的时间优势。

  [1]: https://blog.by24.cn/archives/leetcode-longest-palindromic-substring.html