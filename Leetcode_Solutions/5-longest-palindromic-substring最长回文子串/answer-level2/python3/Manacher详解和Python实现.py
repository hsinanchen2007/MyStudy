这里借用[***](https://www.***.org/manachers-algorithm-linear-time-longest-palindromic-substring-part-1/)上系列文章的图解释一下。

# 基础

对于奇数长度的回文字符串，其中间点为中间的字符；对于偶数长度的回文字符串，其中间点在中间两个字符之间。现假设我们要暴力找一个字符串所有的子字符串，则其所有可能成为子字符串中间点的位置如下（字符之间的位置用竖线表示）：

![ltlp1.jpg](https://pic.leetcode-cn.com/a1fa89449d0c2b46239b10f9e0c258497a76561e1a7ad2864c05c8c23c54aa42-ltlp1.jpg)

例如对于上图中的字符串'abaaba'，所有竖线（算上首尾）和字符，共13个position。此时，我们为图中所有position都赋一个值（或者说建立一个下标为position的数组），这个数组的值是以对应位置为中心的最长回文字符串（Longest Palindromic Substring，LPS）长度（记为数组d）。

例如position=2处，左边是a，右边是b，d[2]=0；position=3处，以其为中心的最长回文字符串为'aba'，所以d[3]=3。另一方面，如果把竖线也当作一个字符，则很容易证明d还有另一种解释：以该position为中心的LPS，向两边延展的步数。例如position=3处，从b向左向右各3步，得到'|a|b|a|'，为回文串，因此d[3]=3；position=6处，从|向左向右各6步，得到'|a|b|a|a|b|a|'，为回文串，因此d[6]=6。

# 思路
显然，求解了d数组就可以知道最长回文串。如果在每个位置上从中心扩展求d，其实就是暴力的 [公式] 算法。如何更有效的求解d数组？或者说，什么样的情况下可以不需要暴力求解？

仍以'abaaba'为例，可以发现一个规律：d[6]=6，以其为中心，d[5]=d[7]=1，d[4]=d[8]=0。其原理很好解释：由于d[6]=6，而d[4]=0，d[5]=1，说明中心position为4和5的短LPS，都在中心position为6的长LPS内部，在长LPS右半部分必然也对应同样的短LPS。所以d[7]=d[5]=1，d[8]=d[4]=0，而不用中心扩展求d。

但这种情况并不一定发生。那么，在已知左边点的d时，什么情况下可以通过左边某个点的d求现在点的d？某种程度上，这也是动态规划思想的体现，充分利用现有的信息。

# 情况分解

现将问题抽象表示如下：

![v2-515c3b52186258a55506aea5aeb5e512_1440w.jpg](https://pic.leetcode-cn.com/05dcc3c69b5cbbca715c6b4ab4c4736610883efdc45f599f4d8608c567f4da39-v2-515c3b52186258a55506aea5aeb5e512_1440w.jpg)

- 我们从左到右遍历，求解每个position的d。假设现在遍历到点i，在求解d[i]的过程中，尽量用到i左侧点d的已知信息。
- 设在i左侧有一个点C，Center Position。其右边界为Center right position，记为R；左边界为Center left position，记为R'。C的特点是：在i左侧的所有点中，C的LPS右边界最靠右。可以认为C的LPS即上例中的长LPS。
- position i关于C的对称点是Current left position，即i'。d[i']也是已知的（即上文的左侧短LPS。

现在的问题是，在何种情况下，可以用上文提及的规律，即d[i]=d[i']？

可将情况分类如下：

- Case 1：当i>R时，i'和i超出C的LPS范围，显然不符合要求；
- 当i<=R时，也不一定符合：
    - Case 2：当d[i']<i'-R'，也即d[i']<R-i的时候，i'点LPS被C点LPS包围，且i'点LPS左端在C点LPS左端的右侧，则i点的LPS必然与i'处一致（因为从C到R和从C到R'的情况完全一致）。亦即上文的理想情况，此时d[i]=d[i']。
    - Case 3：当d[i']=R-i，即i'点LPS左端与C点LPS左端重叠时，i'点LPS延展到R'，由于对称性，则i点LPS至少也延展到R（d[i]>=d[i']），但再向外就不确定了。需要逐步扩展确定d[i]。
    - Case 4：当d[i']>R-i时，i'点LPS超出了C点LPS的范围。此时则d[i]=R-i。即i点LPS右边界为R。原因是，如果i点LPS超过R，考虑R+1点的情况：该点关于i点的对称点m必然在C的LPS范围内，再求m关于C的对称点n，n关于i'的对称点为R'-1，根据前面的条件，R+1，m，n，R'-1处的字符都相同，而R+1与R'-1处的字符相同与C点的LPS长度矛盾。

很多文章在Case 4有错误，觉得d[i]=R-i后还要继续扩展，但其实没必要。不过这不影响程序的时间复杂度，因为显然扩展1次就在两侧碰到不同字符，直接终止，反而在写程序时省了一个分支。

可以将严格的判断过程用伪代码写出：

```Pseudocode
if i >= R: # Case 1
    d[i] = 0
    从d[i]逐步继续扩展，求d[i]
else:
    if d[i'] < R - i: # Case 2
        d[i] = d[i']
    else if d[i'] = R - i: # Case 3
        d[i] = d[i']
        从d[i]逐步继续扩展，求d[i]
    else: # Case 4
        d[i] = R - i
```

# 更新C和R

首先看中心扩展法会在什么情况下使用：

- i>R，则从i开始扩展；
- i<=R，此时如果需要扩展，右边界仍是从R开始。

上文提到，C为遍历到i点时，左侧所有点中，LPS右边界最靠右的点。这样的选择，保证扩展的步数最少。

从另一个角度想，i对应的LPS右边界超过了现在的R时，改变C位置，并将R位置更新到i的LPS右边界。

# 为什么是线性时间复杂度

在前文伪代码外层有一个循环，是从左到右遍历所有position。伪代码内有一个循环，是中心扩展法求d[i]。

由上一部分可以看出，R只会向右，不会回退。而在上文i>R的情况下，扩展法的扩展步数小于R的移动位数，i<=R的情况下，扩展法的步数等于R向右移动的位数。即扩展法在整个程序中被执行的总次数是O(n)级别。

综上，整个算法的时间复杂度是O(n)。

# 程序实现

在实际程序中，把竖线记为任意符号，如#。另外还注意到：

- 每个真实字符所对应的position与该字符在字符串中下标index的转换关系是index=i//2。
- 竖线右侧的字符在原字符串中的下标index=i//2。

并将前文伪代码逻辑调整，使分支更简洁，用Python将程序写完整：

```python
def longestPalindrome(s: str) -> str:

    s_ext = '#' + '#'.join(list(s)) + '#'

    slen = len(s_ext)
    distance = [0] * slen
    center = right = 0
    for idx in range(1, slen-1):
        i_mirror = 2 * center - idx
        if right > idx:
            distance[idx] = min(distance[i_mirror], right-idx)

        while (idx+1+distance[idx] < slen and
               idx-1-distance[idx] >= 0 and
               s_ext[idx+1+distance[idx]] == s_ext[idx-1-distance[idx]]):
            distance[idx] += 1

        if idx + distance[idx] > right:
            center = idx
            right = idx + distance[idx]

    idx = distance.index(max(distance))
    start = (idx - distance[idx]) // 2

    return s[start: start+distance[idx]]
```

另一个技巧是，在s_ext两侧再各加一个字符，如`^`或`$`。假设字符串里不可能出现`^`或`$`，如此，扩展到边界的时候代码里的while循环自然检测到两侧字符不相同而终止。

这样写减少了while循环的判断条件，但不严谨。