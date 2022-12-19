# 解题思路

此题解法繁多，下面一一进行论述比较。

## 暴力解法

通过一个判断是否回文串的辅助函数，然后枚举所有可能的子串，判断是否为回文串，然后保存并返回最长的回文串。有几个细节需要注意：

- 在子函数`subString`当中的临时指针变量`*tmp`需要动态分配空间，否则在调用`strncpy`函数的时候会有报错`null pointer passed as argument1`
- 既然在子函数当中用`malloc`函数动态分配了内存，那么在返回主函数以后，在用完以后需要释放内存，不然`Leetcode`很快就会报**超出内存限制**的错误，提交失败

现在再来看看本解法的时间复杂度，首先主函数当中两重`for`循环，妥妥的$O(n^2)$，判断是否回文串的子函数里面又是一重`for`循环，也是`O(n)`，总体的时间复杂度是$O(n^3)$，最终也会因为**超出时间限制**而提交失败。

具体代码将解法一。

## 中心扩展解法

我们知道回文串一定是关于中心对称的，所以我们每次循环的时候选择一个中心进行左右两边扩展，判断左右字符是否相等即可。

由于可能存在奇数或者偶数个字符的回文字符串，所以我们需要从一个字符开始扩展，或者从两个字符之间开始扩展，如下图所示，总共有`n + n - 1`个中心需要遍历。

![奇偶示意图](https://pic.leetcode-cn.com/8dfbd5738db3db3024c64ae901f0db7667fe9d7db999d600a2c13c002aa5877b.png)

定义一个辅助函数`searchPalindrome`来遍历寻找每个中心进行两边扩散寻找当前中心的最长回文串的长度，如果`i`表示字符串的指针，则从字符本身开始扩展需要遍历调用`searchPalindrome(s, i, i)`，从两个字符之间开始扩展需要遍历调用`searchPalindrome(s, i, i + 1)`，最后取两者之间的较大的`maxLength`即为最大回文串的长度，再每次遍历的时候更新一下最大回文串在原字符串当中的起始指针，用暴力解法当中的`subString`函数返回即可。

现在再来看看本解法的时间复杂度，主函数里面的第一重`for`循环为$O(n)$，里面对于`searchPalindrome`的调用一共需要`n + n - 1`次，因此，总的时间复杂度是$O(n^2)$。

具体代码见解法二。

## 动态规划法

动态规划解题的关键是找到状态转移方程。

我们维护一个二维数组`dp`，让`dp[i][j]`表示字符串区间`[i,j]`是否为回文串，那么有以下几种情况：

- 当`i = j`时，只有一个字符，肯定是回文串
- 当`j = i + 1`时，相邻的两个字符，此时如果`s[i] == s[j]`，则是回文串
- 当`j - i >= 2`时，除了判断`s[i]`和`s[j]`是否相等之外，如果此时`dp[i + 1][j - 1]`也为真，则是回文串

状态转移方程为:`dp[i][j] = dp[i + 1, j - 1] && s[i] == s[j]`

本解法的时间复杂度为$O(n^2)$，具体代码见解法三。

## 马拉车算法

我首先来看看中心扩散解法存在的缺陷，主要有以下两点：

- 由于回文串长度的奇偶性造成了不同性质的对称轴位置，一个是字符本身，另外一个是相邻字符之间的空隙，需要对两种情况分别进行处理
- 很多子串被重复多次访问，造成效率的低下

对于第二个缺陷，可以举一个简单的例子加以说明：

```c
char: a b a b a 
i   : 0 1 2 3 4 
```

当`i = 1`和`i = 2`的时候，左边的子串`aba`分别被遍历了一次，造成执行时间的浪费。

Manacher算法正是针对以上两点不足，对算法进行了优化，提高了算法的效率。

### 解决回文串奇偶性的对称轴位置问题

Manacher算法首先对字符串做一个预处理，在所有的空隙位置(包括首尾)插入同样的符号，要求这个符号是不会在原串中出现的，比如`#`，并且为了使得扩展的过程中，到边界后自动结束，在两端分别插入两个不可能在字符串中出现的字符， 比如`^` 和 `$`，这样中心扩展的时候，判断两端字符是否相等的时候，如果到了边界就一定会不相等，从而出了循环。经过处理，字符串的长度永远都是奇数了。

```c
aba     ------->    ^#a#b#a#$
abba    ------->    ^#a#b#b#a#$
```

这样插入与原字符串不相干的相同字符的巧妙之处在于，对原字符串的回文串不造成影响，原来是回文的串，插完之后还是回文的，原来不是回文的，依然不会是回文。

### 解决重复访问的问题

首先引入一个**回文半径**的概念，定义为一个回文串中最左或者最右位置的字符与其对称轴的距离。然后定义一个回文半径数组`RL`，`RL[i]`表示以第`i`个字符为对称轴的回文串的回文半径，我们一般对字符串从左往右处理，因此这里定义`RL[i]`为第`i`个字符为对称轴的回文串的最右一个字符与字符`i`的距离，`RL[i] - 1` 表示原字符串(处理前)中以第`i`个字符为对称中心的回文子串长度。如果 `RL[i] = 1`，则该回文子串就是 `s[i]` 本身。对于上面插入分隔符之后的两个串，可以得到`RL`数组：

```c
char:    ^ # a # b # a # $
 RL :    1 1 2 1 4 1 2 1 1
RL-1:    0 0 1 0 3 0 1 0 0
  i :    0 1 2 3 4 5 6 7 8 

char:    ^ # a # b # b # a # $
 RL :    1 1 2 1 2 5 2 1 2 1 1
RL-1:    0 0 1 0 1 4 1 0 1 0 0
  i :    0 1 2 3 4 5 6 7 8 9 10
```

上面我们还求了一下`RL[i] - 1`。通过观察再次验证了`RL[i] - 1`的值，正是在原本那个没有插入过分隔符的串中，以位置`i`为对称轴的最长回文串的长度。那么只要我们求出了`RL`数组，就能得到最长回文子串的长度。只知道长度无法定位子串，我们还需要知道子串的起始位置。

我们以下面这串为例进行分析。

```c
char:    ^  #  1  #  2  #  2  #  1  #  2  #  2  #  $
 RL :    1  1  2  1  2  5  2  1  6  1  2  3  2  1  1
RL-1:    0  0  1  0  1  4  1  0  5  0  1  2  1  0  0
 i  :    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14
```

我们还是先来看中间的 `1` 在字符串 `^#1#2#2#1#2#2#$` 中的位置是8，而半径是6，貌似 7-6=2，如果2/2，刚好就是回文子串 `22122` 在原串 `122122` 中的起始位置1。那么我们再来验证下 `bob`，`o` 在 `^#b#o#b#$` 中的位置是4，半径是4，这一减为0，除以2还是0，没有问题。再来验证一下 `noon`，中间的 `#`在字符串 `^#n#o#o#n#$` 中的位置是5，半径也是5，相减并除以2还是0，完美。可以任意试试其他的例子，都是符合这个规律的，原字符串中的最长子串的长度是半径减1，而最长子串在原字符串当中的起始位置是对称轴位置减去半径再除以2。另外，在C/C++当中，因为字符串最末尾的位置是`\0`，最后的`$`不加也没关系。

我们再引入一个辅助变量`MaxRight`，表示当前访问到的所有回文子串，所能触及的最右一个字符的位置。另外还要记录下`MaxRight`对应的回文串的对称轴所在的位置，记为`pos`，它们的位置关系如下:

![total](https://pic.leetcode-cn.com/154608fd572968eb0c98143255ff9cbcc0b22432b7bd33b4fe92cfc7ae457e31.png)

我们从左往右地访问字符串来求`RL`，假设当前访问到的位置为`i`，即要求`RL[i]`，再对应上图，显然的，`i`必然是在`pos`右边的。但我们更关注的是，`i`是在`MaxRight`的左边还是右边。我们分情况来讨论。

#### 当`i`在`MaxRight`的左边

这种情况可以用下图来描述：

![1](https://pic.leetcode-cn.com/8a194bb9d0e4b6fafc07047c716780ae1382b5350285393fa8e562aba93ca354.png)

我们知道，图中两个红色块之间（包括红色块）的串是回文的；并且以`i`为对称轴的回文串，是与红色块间的回文串有所重叠的。我们找到`i`关于`pos`的对称位置`j`，这个`j`对应的`RL[j]`我们是已经算过的。根据回文串的对称性，以`i`为对称轴的回文串和以`j`为对称轴的回文串，有一部分是相同的。这里又有两种细分的情况。

- 以`j`为对称轴的回文串比较短，短到像下图这样:

![3](https://pic.leetcode-cn.com/6f0bd6231ff0e0fd7acf793aa63a610875241ae16b1ff88b2cf29eef164f28f3.png)

这时我们知道`RL[i]`至少不会小于`RL[j]`，并且已经知道了部分的以`i`为中心的回文串，于是可以令`RL[i]=RL[j]`。但是以`i`为对称轴的回文串可能实际上更长，因此我们试着以`i`为对称轴，继续往左右两边扩展，直到左右两边字符不同，或者到达边界。

- 以`j`为对称轴的回文串很长，这么长： 

![4](https://pic.leetcode-cn.com/dc61475c8c1ce9161bf8fe8210da00864535f378d65976d99c7154f9a31aad73.png)

这时，我们只能确定，两条蓝线之间的部分（即不超过`MaxRight`的部分）是回文的，于是从这个长度开始，尝试以`i`为中心向左右两边扩展，直到左右两边字符不同，或者到达边界。

不论以上哪种情况，之后都要尝试更新`MaxRight`和`pos`，因为有可能得到更大的`MaxRight`。

具体步骤如下：

```c
step 1: 令RL[i]=min(RL[2*pos-i], MaxRight-i)
step 2: 以i为中心扩展回文串，直到左右两边字符不同，或者到达边界。
step 3: 更新MaxRight和pos
```

#### 当`i`在`MaxRight`的右边

![4](https://pic.leetcode-cn.com/f99c1fbf2a70d0403d42f95a50d1ca49363bab5966dfdf8eb866d3f133f597c3.png)

遇到这种情况，说明以i为对称轴的回文串还没有任何一个部分被访问过，于是只能从`i`的左右两边开始尝试扩展了，当左右两边字符不同，或者到达字符串边界时停止。然后更新`MaxRight`和`pos`。

Manacher算法的动态过程可以参考这个[链接](http://manacher-viz.s3-website-us-east-1.amazonaws.com/#/)。

具体代码见解法四，先给一个C++的，C对于字符串的预处理好像有些麻烦。

现在分析下本解法的复杂度。

时间复杂度：`for` 循环里边套了一层 `while` 循环，难道不是 $O(n^2)$？不！其实是 $O(n)$。不严谨的想一下，因为 `while` 循环访问 `maxRight` 右边的数字用来扩展，也就是那些还未求出的节点，然后不断扩展，而期间访问的节点下次就不会再进入 `while` 了，可以利用对称得到自己的解，所以每个节点访问都是常数次，所以是 $O(n)$。

空间复杂度也是$O(n)$。



# 代码

## 解法一：暴力解法

```c
//比较两个整数求最大值
int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

//判断是否为回文串
bool isPalindromic(char * s)
{
    int len = strlen(s);

    for(int i = 0; i < len / 2; i++)
    {
        if(s[i] != s[len - 1 - i]) //类似于
        {
            return false;
        }
    }

    return true;
}

//subString 子函数
char * subString(char * s, int startIndex, int endIndex)
{
/*
  s: 需要截取的字符串头指针变量
  startIndex: 截取起始索引
  endIndex: 截取终止索引
 */
    assert(endIndex >= startIndex);
    assert(s != NULL);

    int length = endIndex - startIndex;

    char *tmp = (char *)malloc(1001*sizeof(char));

    strncpy(tmp, s + startIndex, length);

    tmp[length] = '\0';

    return tmp;
}

char * longestPalindrome(char * s)
{
    char *result;
    int len = strlen(s);

    //判断极端条件
    if(len < 2)
    {
        return s;
    }
    
    //最大回文串长度
    int maxLen = 0;
    
    for(int i = 0; i < len; i++)
    {
        for(int j = i + 1; j <=  len; j++)
        {
            char *tmp = subString(s, i, j);
            
            if(isPalindromic(tmp) && strlen(tmp) > maxLen)
            {
                result = subString(s, i, j);
                maxLen = max(maxLen, strlen(result));
            }
            
            free(tmp); //释放内存的位置需要与前面动态分配内存的位置对应
        }
    }

    return result;
}
```

## 解法二：中心扩展解法

```c
int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}


char * subString(char * s, int startIndex, int endIndex)
{
    assert(endIndex >= startIndex);
    assert(s != NULL);

    int length = endIndex - startIndex;

    char *tmp = (char *)malloc(1001*sizeof(char));

    strncpy(tmp, s + startIndex, length);

    tmp[length] = '\0';

    return tmp;
}

//传入一个字符串，搜索回文串，并返回包含最长回文串的长度
int searchPalindrome(char * s, int left, int right)
{
    /*
      char *s: 需要搜索的字符串的头指针
      int left：原字符串搜索中心的左边界
      int right：原字符串搜索中心的右边界
     */
    while(left >= 0 && right < strlen(s) && s[left] == s[right]) //从中心向两边进行扩散
    {
        left--;
        right++;
    }

    return right - left - 1; //返回最长回文串长度
}


char * longestPalindrome(char * s)
{
    int len = strlen(s);
    int startIndex = 0, endIndex = 0;
    
    if (len <= 1)
    {
        return s;
    }

    for(int i = 0; i < len; i++)
    {
        int maxLength = max(searchPalindrome(s, i, i), searchPalindrome(s, i, i + 1));  //获取最长回文串的长度

        if(maxLength > endIndex - startIndex)                                           //更新最长回文串在原字符串当中头尾指针
        {
            startIndex = i - (maxLength - 1) / 2;
            endIndex = i + maxLength / 2;
        }
    }

    return subString(s, startIndex, endIndex + 1);                                     //调用subString函数返回结果，注意endIndex+1
}
```

## 解法三：动态规划解法

```c
//subString 子函数
char * subString(char * s, int startIndex, int endIndex)
{
/*
  s: 需要截取的字符串头指针变量
  startIndex: 截取起始索引
  endIndex: 截取终止索引
 */
    assert(endIndex >= startIndex);
    assert(s != NULL);

    int length = endIndex - startIndex;

    char *tmp = (char *)malloc(1001*sizeof(char));

    strncpy(tmp, s + startIndex, length);

    tmp[length] = '\0';

    return tmp;
}

char * longestPalindrome(char * s)
{
    int len = strlen(s);
    int startIndex = 0, maxLength = 1;
    int dp[1001][1001];                                                    //dp二维数组初始化，很遗憾，用len来初始化会报错
    
    if (len <= 1)
    {
        return s;
    }

    for(int j = 0; j < len; j++)
    {
        dp[j][j] = 1;

        for(int i = 0; i < j; i++)
        {
            dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));  //动态计算dp值
            if(dp[i][j] &&  maxLength < j - i + 1)                         //更新回文串起始指针位置和最大长度
            {
                maxLength = j - i + 1;
                startIndex = i;
            }
        }
    }

    return subString(s, startIndex, startIndex + maxLength);
}
```

## 解法四：马拉车算法（Manache's Algorithm）

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        // 插入前缀 '^#'
        string t = "^#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }
        int RL[t.size()];
        
        // 记录最长半径范围
        int maxRight = 0, Pos = 0;
        // 记录最长回文字符串长度
        int maxLength = 0;
        // 当前最长半径的对称轴
        int currentPosition = 0;

        for (int i = 1; i < t.size(); ++i) 
        {
            /*
            如果 maxRight > i, 则 RL[i] = min( RL[2 * Pos - i] , maxRight - i )

            否则，RL[i] = 1
            */

            RL[i] = maxRight > i ? min(RL[2 * Pos - i], maxRight - i) : 1;
            
            while (t[i + RL[i]] == t[i - RL[i]]) 
                ++RL[i];
            
            if (maxRight < i + RL[i])
            {
                maxRight = i + RL[i];
                Pos = i;
            }

            if (maxLength < RL[i])
            {
                maxLength = RL[i];
                currentPosition = i;
            }
        }
        return s.substr((currentPosition - maxLength) / 2, maxLength - 1);
    }
};
```

# 参考资料

- [详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-bao-gu/)
- [[LeetCode] 5. Longest Palindromic Substring 最长回文子串](https://www.cnblogs.com/grandyang/p/4464476.html)
- [最长回文子串——Manacher 算法](https://segmentfault.com/a/1190000003914228)
- [最长回文子串](https://www.jianshu.com/p/2c6515e8b1b2)
