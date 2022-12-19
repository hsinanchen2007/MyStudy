/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

/*

https://leetcode.cn/problems/implement-strstr/

28. 实现 strStr()
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

 
示例 1：

输入：haystack = "hello", needle = "ll"
输出：2

示例 2：

输入：haystack = "aaaaa", needle = "bba"
输出：-1
 

提示：

1 <= haystack.length, needle.length <= 104
haystack 和 needle 仅由小写英文字符组成
通过次数692,871提交次数1,687,126

*/

// @lc code=start
class Solution100 {
public:
    // 2022.7.23, by Hsinan, use existing STL's find() to see if it can return needle in haystack or not
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};


class Solution99 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md
    /*
        本题是KMP 经典题目。

        以下文字如果看不进去，可以看我的B站视频：

        帮你把KMP算法学个通透！B站（理论篇）
        帮你把KMP算法学个通透！（求next数组代码篇）
        KMP的经典思想就是:当出现字符串不匹配时，可以记录一部分之前已经匹配的文本内容，利用这些信息避免从头再去做匹配。

        本篇将以如下顺序来讲解KMP，

        什么是KMP
        KMP有什么用
        什么是前缀表
        为什么一定要用前缀表
        如何计算前缀表
        前缀表与next数组
        使用next数组来匹配
        时间复杂度分析
        构造next数组
        使用next数组来做匹配
        前缀表统一减一 C++代码实现
        前缀表（不减一）C++实现
        总结
        读完本篇可以顺便把leetcode上28.实现strStr()题目做了。

        什么是KMP
        说到KMP，先说一下KMP这个名字是怎么来的，为什么叫做KMP呢。

        因为是由这三位学者发明的：Knuth，Morris和Pratt，所以取了三位学者名字的首字母。所以叫做KMP

        KMP有什么用
        KMP主要应用在字符串匹配上。

        KMP的主要思想是当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，可以利用这些信息避免从头再去做匹配了。
        所以如何记录已经匹配的文本内容，是KMP的重点，也是next数组肩负的重任。

        其实KMP的代码不好理解，一些同学甚至直接把KMP代码的模板背下来。
        没有彻底搞懂，懵懵懂懂就把代码背下来太容易忘了。

        不仅面试的时候可能写不出来，如果面试官问：next数组里的数字表示的是什么，为什么这么表示？
        估计大多数候选人都是懵逼的。

        下面Carl就带大家把KMP的精髓，next数组弄清楚。

        什么是前缀表
        写过KMP的同学，一定都写过next数组，那么这个next数组究竟是个啥呢？

        next数组就是一个前缀表（prefix table）。
        前缀表有什么作用呢？

        前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。
        为了清楚的了解前缀表的来历，我们来举一个例子：

        要在文本串：aabaabaafa 中查找是否出现过一个模式串：aabaaf。
        请记住文本串和模式串的作用，对于理解下文很重要，要不然容易看懵。所以说三遍：
        要在文本串：aabaabaafa 中查找是否出现过一个模式串：aabaaf。
        要在文本串：aabaabaafa 中查找是否出现过一个模式串：aabaaf。
        要在文本串：aabaabaafa 中查找是否出现过一个模式串：aabaaf。

        如动画所示：

        KMP详解1

        动画里，我特意把 子串aa 标记上了，这是有原因的，大家先注意一下，后面还会说道。
        可以看出，文本串中第六个字符b 和 模式串的第六个字符f，不匹配了。如果暴力匹配，会发现不匹配，此时就要从头匹配了。

        但如果使用前缀表，就不会从头匹配，而是从上次已经匹配的内容开始匹配，找到了模式串中第三个字符b继续开始匹配。
        此时就要问了前缀表是如何记录的呢？

        首先要知道前缀表的任务是当前位置匹配失败，找到之前已经匹配上的位置，再重新匹配，此也意味着在某个字符失配时，
        前缀表会告诉你下一步匹配中，模式串应该跳到哪个位置。

        那么什么是前缀表：记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀。

        最长公共前后缀？
        文章中字符串的前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串。

        后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。
        正确理解什么是前缀什么是后缀很重要!

        那么网上清一色都说 “kmp 最长公共前后缀” 又是什么回事呢？
        我查了一遍 算法导论 和 算法4里KMP的章节，都没有提到 “最长公共前后缀”这个词，也不知道从哪里来了，我理解是用
        “最长相等前后缀” 更准确一些。

        因为前缀表要求的就是相同前后缀的长度。
        而最长公共前后缀里面的“公共”，更像是说前缀和后缀公共的长度。这其实并不是前缀表所需要的。

        所以字符串a的最长相等前后缀为0。 字符串aa的最长相等前后缀为1。 字符串aaa的最长相等前后缀为2。 等等.....。

        为什么一定要用前缀表
        这就是前缀表，那为啥就能告诉我们 上次匹配的位置，并跳过去呢？

        回顾一下，刚刚匹配的过程在下标5的地方遇到不匹配，模式串是指向f，如图： KMP精讲1
        然后就找到了下标2，指向b，继续匹配：如图： KMP精讲2

        以下这句话，对于理解为什么使用前缀表可以告诉我们匹配失败之后跳到哪里重新匹配 非常重要！

        下标5之前这部分的字符串（也就是字符串aabaa）的最长相等的前缀 和 后缀字符串是 子字符串aa ，因为找到了最长
        相等的前缀和后缀，匹配失败的位置是后缀子串的后面，那么我们找到与其相同的前缀的后面从新匹配就可以了。

        所以前缀表具有告诉我们当前位置匹配失败，跳到之前已经匹配过的地方的能力。
        很多介绍KMP的文章或者视频并没有把为什么要用前缀表？这个问题说清楚，而是直接默认使用前缀表。

        如何计算前缀表
        接下来就要说一说怎么计算前缀表。

        如图：

        KMP精讲5

        长度为前1个字符的子串a，最长相同前后缀的长度为0。（注意字符串的前缀是指不包含最后一个字符的所有以第一个字符
        开头的连续子串；后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串。）

        KMP精讲6 长度为前2个字符的子串aa，最长相同前后缀的长度为1。
        KMP精讲7 长度为前3个字符的子串aab，最长相同前后缀的长度为0。

        以此类推： 长度为前4个字符的子串aaba，最长相同前后缀的长度为1。 长度为前5个字符的子串aabaa，最长相同前后缀
        的长度为2。 长度为前6个字符的子串aabaaf，最长相同前后缀的长度为0。

        那么把求得的最长相同前后缀的长度就是对应前缀表的元素，如图： KMP精讲8
        可以看出模式串与前缀表对应位置的数字表示的就是：下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀。

        再来看一下如何利用 前缀表找到 当字符不匹配的时候应该指针应该移动的位置。如动画所示：

        KMP精讲2

        找到的不匹配的位置， 那么此时我们要看它的前一个字符的前缀表的数值是多少。
        为什么要前一个字符的前缀表的数值呢，因为要找前面字符串的最长相同的前缀和后缀。
        所以要看前一位的 前缀表的数值。

        前一个字符的前缀表的数值是2， 所有把下标移动到下标2的位置继续比配。 可以再反复看一下上面的动画。
        最后就在文本串中找到了和模式串匹配的子串了。

        前缀表与next数组
        很多KMP算法的时间都是使用next数组来做回退操作，那么next数组与前缀表有什么关系呢？

        next数组就可以是前缀表，但是很多实现都是把前缀表统一减一（右移一位，初始位置为-1）之后作为next数组。

        为什么这么做呢，其实也是很多文章视频没有解释清楚的地方。

        其实这并不涉及到KMP的原理，而是具体实现，next数组即可以就是前缀表，也可以是前缀表统一减一（右移一位，
        初始位置为-1）。

        后面我会提供两种不同的实现代码，大家就明白了。

        使用next数组来匹配
        以下我们以前缀表统一减一之后的next数组来做演示。

        有了next数组，就可以根据next数组来 匹配文本串s，和模式串t了。

        注意next数组是新前缀表（旧前缀表统一减一了）。

        匹配过程动画如下：

        KMP精讲4

        时间复杂度分析
        其中n为文本串长度，m为模式串长度，因为在匹配的过程中，根据前缀表不断调整匹配的位置，可以看出匹配的过程是O(n)，
        之前还要单独生成next数组，时间复杂度是O(m)。所以整个KMP算法的时间复杂度是O(n+m)的。

        暴力的解法显而易见是O(n × m)，所以KMP在字符串匹配中极大的提高的搜索的效率。

        为了和力扣题目28.实现strStr保持一致，方便大家理解，以下文章统称haystack为文本串, needle为模式串。
        都知道使用KMP算法，一定要构造next数组。

        构造next数组
        我们定义一个函数getNext来构建next数组，函数参数为指向next数组的指针，和一个字符串。 代码如下：

        void getNext(int* next, const string& s)
        构造next数组其实就是计算模式串s，前缀表的过程。 主要有如下三步：

        初始化
        处理前后缀不相同的情况
        处理前后缀相同的情况
        接下来我们详解详解一下。

        初始化：
        定义两个指针i和j，j指向前缀末尾位置，i指向后缀末尾位置。

        然后还要对next数组进行初始化赋值，如下：

        int j = -1;
        next[0] = j;
        j 为什么要初始化为 -1呢，因为之前说过 前缀表要统一减一的操作仅仅是其中的一种实现，我们这里选择j初始化为-1，
        下文我还会给出j不初始化为-1的实现代码。

        next[i] 表示 i（包括i）之前最长相等的前后缀长度（其实就是j）

        所以初始化next[0] = j 。

        处理前后缀不相同的情况
        因为j初始化为-1，那么i就从1开始，进行s[i] 与 s[j+1]的比较。

        所以遍历模式串s的循环下标i 要从 1开始，代码如下：

        for (int i = 1; i < s.size(); i++) {
        如果 s[i] 与 s[j+1]不相同，也就是遇到 前后缀末尾不相同的情况，就要向前回退。

        怎么回退呢？

        next[j]就是记录着j（包括j）之前的子串的相同前后缀的长度。

        那么 s[i] 与 s[j+1] 不相同，就要找 j+1前一个元素在next数组里的值（就是next[j]）。

        所以，处理前后缀不相同的情况代码如下：

        while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
            j = next[j]; // 向前回退
        }
        处理前后缀相同的情况
        如果 s[i] 与 s[j + 1] 相同，那么就同时向后移动i 和j 说明找到了相同的前后缀，同时还要将j（前缀的长度）
        赋给next[i], 因为next[i]要记录相同前后缀的长度。

        代码如下：

        if (s[i] == s[j + 1]) { // 找到相同的前后缀
            j++;
        }
        next[i] = j;
        最后整体构建next数组的函数代码如下：

        void getNext(int* next, const string& s){
            int j = -1;
            next[0] = j;
            for(int i = 1; i < s.size(); i++) { // 注意i从1开始
                while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                    j = next[j]; // 向前回退
                }
                if (s[i] == s[j + 1]) { // 找到相同的前后缀
                    j++;
                }
                next[i] = j; // 将j（前缀的长度）赋给next[i]
            }
        }
        代码构造next数组的逻辑流程动画如下：

        KMP精讲3

        得到了next数组之后，就要用这个来做匹配了。

        使用next数组来做匹配
        在文本串s里 找是否出现过模式串t。

        定义两个下标j 指向模式串起始位置，i指向文本串起始位置。

        那么j初始值依然为-1，为什么呢？ 依然因为next数组里记录的起始位置为-1。

        i就从0开始，遍历文本串，代码如下：

        for (int i = 0; i < s.size(); i++) 
        接下来就是 s[i] 与 t[j + 1] （因为j从-1开始的） 进行比较。

        如果 s[i] 与 t[j + 1] 不相同，j就要从next数组里寻找下一个匹配的位置。

        代码如下：

        while(j >= 0 && s[i] != t[j + 1]) {
            j = next[j];
        }
        如果 s[i] 与 t[j + 1] 相同，那么i 和 j 同时向后移动， 代码如下：

        if (s[i] == t[j + 1]) {
            j++; // i的增加在for循环里
        }
        如何判断在文本串s里出现了模式串t呢，如果j指向了模式串t的末尾，那么就说明模式串t完全匹配文本串s里的某个子串了。

        本题要在文本串字符串中找出模式串出现的第一个位置 (从0开始)，所以返回当前在文本串匹配模式串的位置i 减去 模式串的长度，
        就是文本串字符串中出现模式串的第一个位置。

        代码如下：

        if (j == (t.size() - 1) ) {
            return (i - t.size() + 1);
        }
        那么使用next数组，用模式串匹配文本串的整体代码如下：

        int j = -1; // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < s.size(); i++) { // 注意i就从0开始
            while(j >= 0 && s[i] != t[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (s[i] == t[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (t.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - t.size() + 1);
            }
        }
        此时所有逻辑的代码都已经写出来了，力扣 28.实现strStr 题目的整体代码如下：
    */
    // 前缀表统一减一 C++代码实现
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; // 向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};


class Solution98 {
public:
    // 2022.7.23, from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md
    /*
        那么前缀表就不减一了，也不右移的，到底行不行呢？

        行！

        我之前说过，这仅仅是KMP算法实现上的问题，如果就直接使用前缀表可以换一种回退方式，找j=next[j-1] 
        来进行回退。

        主要就是j=next[x]这一步最为关键！

        我给出的getNext的实现为：（前缀表统一减一）

        void getNext(int* next, const string& s) {
            int j = -1;
            next[0] = j;
            for(int i = 1; i < s.size(); i++) { // 注意i从1开始
                while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                    j = next[j]; // 向前回退
                }
                if (s[i] == s[j + 1]) { // 找到相同的前后缀
                    j++;
                }
                next[i] = j; // 将j（前缀的长度）赋给next[i]
            }
        }
        此时如果输入的模式串为aabaaf，对应的next为-1 0 -1 0 1 -1。

        这里j和next[0]初始化为-1，整个next数组是以 前缀表减一之后的效果来构建的。

        那么前缀表不减一来构建next数组，代码如下：

            void getNext(int* next, const string& s) {
                int j = 0;
                next[0] = 0;
                for(int i = 1; i < s.size(); i++) {
                    while (j > 0 && s[i] != s[j]) { // j要保证大于0，因为下面有取j-1作为数组下标的操作
                        j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
                    }
                    if (s[i] == s[j]) {
                        j++;
                    }
                    next[i] = j;
                }
            }
        此时如果输入的模式串为aabaaf，对应的next为 0 1 0 1 2 0，（其实这就是前缀表的数值了）。
        那么用这样的next数组也可以用来做匹配，代码要有所改动。

        实现代码如下：

        总结
        我们介绍了什么是KMP，KMP可以解决什么问题，然后分析KMP算法里的next数组，知道了next数组就是前缀表，
        再分析为什么要是前缀表而不是什么其他表。接着从给出的模式串中，我们一步一步的推导出了前缀表，得出前缀表无论
        是统一减一还是不减一得到的next数组仅仅是kmp的实现方式的不同。其中还分析了KMP算法的时间复杂度，并且和
        暴力方法做了对比。

        然后先用前缀表统一减一得到的next数组，求得文本串s里是否出现过模式串t，并给出了具体分析代码。
        又给出了直接用前缀表作为next数组，来做匹配的实现代码。

        可以说把KMP的每一个细微的细节都扣了出来，毫无遮掩的展示给大家了！
    */
    // 前缀表（不减一）C++实现
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};


class Solution97 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0028/?h=strstr
    // Time: O((m - n)n), where m = haystack, n = needle
    // Space: O(1)
    int strStr(string haystack, string needle) {
        const int m = haystack.length();
        const int n = needle.length();

        for (int i = 0; i < m - n + 1; i++)
            if (haystack.substr(i, n) == needle)
                return i;

        return -1;
    }
};


class Solution96 {
public:
    // 2022.7.23, from https://www.guozet.me/leetcode/Leetcode-28-Implement-StrStr.html?h=strstr
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int len_m = haystack.size(), len_n = needle.size();
        if (len_m < len_n) return -1;
        for (int i = 0; i <= len_m - len_n; ++i) {
            int j = 0;
            for (j = 0; j < len_n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == len_n) return i;
        }
        return -1;
    }
};


class Solution95 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/implement-strstr.cpp
    // Time:  O(n * k)
    // Space: O(k)
    int strStr(string haystack, string needle) {
        for (int i = 0; i + needle.length() < haystack.length() + 1; ++i) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};


class Solution94 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/implement-strstr.cpp
    // KMP way
    // Time:  O(n + k)
    // Space: O(k)
    // Wiki of KMP algorithm:
    // http://en.wikipedia.org/wiki/Knuth-Morris-Pratt_algorithm
    int KMP(const string& text, const string& pattern) {
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                return i - j;
            }
        }
        return -1;
    }
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        return KMP(haystack, needle);
    }
};


class Solution93 {
public:
    // 2022.7.23, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/347914/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int strStr(string s, string p) {
        if (p.empty()) return 0;
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;

        vector<int> next(m + 1);
        for (int i = 2, j = 0; i <= m; i ++ ) {
            while (j && p[i] != p[j + 1]) j = next[j];
            if (p[i] == p[j + 1]) j ++ ;
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i ++ ) {
            while (j && s[i] != p[j + 1]) j = next[j];
            if (s[i] == p[j + 1]) j ++ ;
            if (j == m) return i - m;
        }

        return -1;
    }

};



class Solution92 {
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/28.%20Implement%20strStr()
    // OJ: https://leetcode.com/problems/implement-strstr/
    // Author: github.com/lzl124631x
    // Time: O(MN)
    // Space: O(1)
    // Solution 1. Brute Force
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            int j = 0;
            for (; j < needle.size() && haystack[i + j] == needle[j]; ++j);
            if (j == needle.size()) return i;
        }
        return -1;
    }
};



class Solution91 {
    typedef long long LL;
public:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/28.%20Implement%20strStr()
    // OJ: https://leetcode.com/problems/implement-strstr/
    // Author: github.com/lzl124631x
    // Time: average O(S+T), worst O(ST)
    // Space: O(1)
    // Solution 2. Rabin Karp
    int strStr(string s, string t) {
        int S = s.size(), T = t.size(), d = 128; 
        if (!S || !T || T > S) return T ? -1 : 0;
        LL m = 1e9+7, p = 1, hs = s[0], ht = t[0];
        for (int i = 1; i < T; ++i) {
            p = (p * d) % m; // we need d^(T-1)
            ht = (ht * d + t[i]) % m;
            hs = (hs * d + s[i]) % m;
        }
        for (int i = 0; i <= S - T; ++i) { // Loop for each start/pop point
            if (hs == ht) { // in case of collision, check the equity.
                int j = 0;
                for (; j < T && s[i + j] == t[j]; ++j);
                if (j == T) return i;
            }
            if (i < S - T) hs = ((hs - s[i] * p) * d + s[i + T]) % m;
            if (hs < 0) hs += m; // we might get negative hs, converting it to positive
        }
        return -1;
    }
};


class Solution90 {
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/28.%20Implement%20strStr()
    // OJ: https://leetcode.com/problems/implement-strstr/
    // Author: github.com/lzl124631x
    // Time: O(M+N)
    // Space: O(N)
    // Solution 3. KMP
    vector<int> getLps(string &s) {
        int N = s.size(), j = 0;
        vector<int> lps(N);
        for (int i = 1; i < N; ++i) {
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            j += s[i] == s[j];
            lps[i] = j;
        }
        return lps;
    }
public:
    int strStr(string s, string t) {
        if (t.empty()) return 0;
        int M = s.size(), N = t.size(), i = 0, j = 0;
        auto lps = getLps(t);
        while (i < M) {
            if (s[i] == t[j]) {
                ++i;
                ++j;
            }
            if (j == N) return i - j;
            if (i < M && s[i] != t[j]) {
                if (j) j = lps[j - 1];
                else ++i;
            }
        }
        return -1;
    }
};


class Solution89 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/28
    /*
        这道题让我们在一个字符串中找另一个字符串第一次出现的位置，那首先要做一些判断，如果子字符串为空，
        则返回0，如果子字符串长度大于母字符串长度，则返回 -1。然后开始遍历母字符串，这里并不需要遍历整
        个母字符串，而是遍历到剩下的长度和子字符串相等的位置即可，这样可以提高运算效率。然后对于每一个
        字符，都遍历一遍子字符串，一个一个字符的对应比较，如果对应位置有不等的，则跳出循环，如果一直都
        没有跳出循环，则说明子字符串出现了，则返回起始位置即可，代码如下：
    */
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/28
    /*
        我们也可以写的更加简洁一些，开头直接套两个 for 循环，不写终止条件，然后判断假如j到达 needle 
        的末尾了，此时返回i；若此时 i+j 到达 haystack 的长度了，返回 -1；否则若当前对应的字符不匹配，
        直接跳出当前循环，参见代码如下：

        解法二：
    */
    int strStr(string haystack, string needle) {
        for (int i = 0; ; ++i) {
            for (int j = 0; ; ++j) {
                if (j == needle.size()) return i;
                if (i + j == haystack.size()) return -1;
                if (needle[j] != haystack[i + j]) break;
            }
        }
        return -1;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

