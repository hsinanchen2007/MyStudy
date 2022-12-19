/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

/*

https://leetcode.cn/problems/reverse-words-in-a-string/

151. 颠倒字符串中的单词
给你一个字符串 s ，颠倒字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅
用单个空格分隔，且不包含任何额外的空格。

 
示例 1：

输入：s = "the sky is blue"
输出："blue is sky the"

示例 2：

输入：s = "  hello world  "
输出："world hello"
解释：颠倒后的字符串中不能存在前导空格和尾随空格。

示例 3：

输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
 

提示：

1 <= s.length <= 104
s 包含英文大小写字母、数字和空格 ' '
s 中 至少存在一个 单词
 

进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。

通过次数277,763提交次数548,347

*/

// @lc code=start
class Solution100 {
private:
    // 2022.7.23, by https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md
    /*
        这道题目可以说是综合考察了字符串的多种操作。

        一些同学会使用split库函数，分隔单词，然后定义一个新的string字符串，最后再把单词倒序相加，那么这道
        题题目就是一道水题了，失去了它的意义。所以这里我还是提高一下本题的难度：不要使用辅助空间，空间复杂度
        要求为O(1)。

        不能使用辅助空间之后，那么只能在原字符串上下功夫了。

        想一下，我们将整个字符串都反转过来，那么单词的顺序指定是倒序了，只不过单词本身也倒序了，那么再把单词
        反转一下，单词不就正过来了。

        所以解题思路如下：

        移除多余空格
        将整个字符串反转
        将每个单词反转
        举个例子，源字符串为："the sky is blue "

        移除多余空格 : "the sky is blue"
        字符串反转："eulb si yks eht"
        单词反转："blue is sky the"
        这样我们就完成了翻转字符串里的单词。

        思路很明确了，我们说一说代码的实现细节，就拿移除多余空格来说，一些同学会上来写如下代码：

        void removeExtraSpaces(string& s) {
            for (int i = s.size() - 1; i > 0; i--) {
                if (s[i] == s[i - 1] && s[i] == ' ') {
                    s.erase(s.begin() + i);
                }
            }
            // 删除字符串最后面的空格
            if (s.size() > 0 && s[s.size() - 1] == ' ') {
                s.erase(s.begin() + s.size() - 1);
            }
            // 删除字符串最前面的空格
            if (s.size() > 0 && s[0] == ' ') {
                s.erase(s.begin());
            }
        }
        逻辑很简单，从前向后遍历，遇到空格了就erase。

        如果不仔细琢磨一下erase的时间复杂度，还以为以上的代码是O(n)的时间复杂度呢。

        想一下真正的时间复杂度是多少，一个erase本来就是O(n)的操作，erase实现原理题目：数组：
        就移除个元素很难么？，最优的算法来移除元素也要O(n)。erase操作上面还套了一个for循环，
        那么以上代码移除冗余空格的代码时间复杂度为O(n^2)。

        那么使用双指针法来去移除空格，最后resize（重新设置）一下字符串的大小，就可以做到O(n)的时间复杂度。
        如果对这个操作比较生疏了，可以再看一下这篇文章：数组：就移除个元素很难么？是如何移除元素的。

        那么使用双指针来移除冗余空格代码如下： fastIndex走的快，slowIndex走的慢，最后slowIndex
        就标记着移除多余空格后新字符串的长度。

        void removeExtraSpaces(string& s) {
            int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
            // 去掉字符串前面的空格
            while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
                fastIndex++;
            }
            for (; fastIndex < s.size(); fastIndex++) {
                // 去掉字符串中间部分的冗余空格
                if (fastIndex - 1 > 0
                        && s[fastIndex - 1] == s[fastIndex]
                        && s[fastIndex] == ' ') {
                    continue;
                } else {
                    s[slowIndex++] = s[fastIndex];
                }
            }
            if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
                s.resize(slowIndex - 1);
            } else {
                s.resize(slowIndex); // 重新设置字符串大小
            }
        }
        有的同学可能发现用erase来移除空格，在leetcode上性能也还行。主要是以下几点；：

        leetcode上的测试集里，字符串的长度不够长，如果足够长，性能差距会非常明显。
        leetcode的测程序耗时不是很准确的。
        此时我们已经实现了removeExtraSpaces函数来移除冗余空格。

        还做实现反转字符串的功能，支持反转字符串子区间，这个实现我们分别在344.反转字符串和541.反转字符串II里已经讲过了。

        代码如下：

        // 反转字符串s中左闭又闭的区间[start, end]
        void reverse(string& s, int start, int end) {
            for (int i = start, j = end; i < j; i++, j--) {
                swap(s[i], s[j]);
            }
        }
        本题C++整体代码
    */
    // 版本一
    // 反转字符串s中左闭又闭的区间[start, end]
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    // 移除冗余空格：使用双指针（快慢指针法）O(n)的算法
    void removeExtraSpaces(string& s) {
        int slowIndex = 0, fastIndex = 0; // 定义快指针，慢指针
        // 去掉字符串前面的空格
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉字符串中间部分的冗余空格
            if (fastIndex - 1 > 0
                    && s[fastIndex - 1] == s[fastIndex]
                    && s[fastIndex] == ' ') {
                continue;
            } else {
                s[slowIndex++] = s[fastIndex];
            }
        }
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') { // 去掉字符串末尾的空格
            s.resize(slowIndex - 1);
        } else {
            s.resize(slowIndex); // 重新设置字符串大小
        }
    }

public:
    string reverseWords(string s) {
        removeExtraSpaces(s); // 去掉冗余空格
        reverse(s, 0, s.size() - 1); // 将字符串全部反转
        int start = 0; // 反转的单词在字符串里起始位置
        int end = 0; // 反转的单词在字符串里终止位置
        bool entry = false; // 标记枚举字符串的过程中是否已经进入了单词区间
        for (int i = 0; i < s.size(); i++) { // 开始反转单词
            if (!entry) {
                start = i; // 确定单词起始位置
                entry = true; // 进入单词区间
            }
            // 单词后面有空格的情况，空格就是分词符
            if (entry && s[i] == ' ' && s[i - 1] != ' ') {
                end = i - 1; // 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
            }
            // 最后一个结尾单词之后没有空格的情况
            if (entry && (i == (s.size() - 1)) && s[i] != ' ' ) {
                end = i;// 确定单词终止位置
                entry = false; // 结束单词区间
                reverse(s, start, end);
            }
        }
        return s;
    }
    // 当然这里的主函数reverseWords写的有一些冗余的，可以精简一些，精简之后的主函数为：
    /* 主函数简单写法
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        for(int i = 0; i < s.size(); i++) {
            int j = i;
            // 查找单词间的空格，翻转单词
            while(j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
    */
};


class Solution99 {
private:
    // 2022.7.23, by https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.md
    //版本二：
    //原理同版本1，更简洁实现。
    void reverse(string& s, int start, int end){ //翻转，区间写法：闭区间 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {//去除所有空格并在相邻单词之间添加空格, 快慢指针。
        int slow = 0;   //整体思想参考Leetcode: 27. 移除元素：https://leetcode.cn/problems/remove-element/
        for (int i = 0; i < s.size(); ++i) { //
            if (s[i] != ' ') { //遇到非空格就处理，即删除所有空格。
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); //slow的大小即为去除多余空格后的大小。
    }

public:
    string reverseWords(string s) {
        removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
        reverse(s, 0, s.size() - 1);
        int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};


class Solution98 {
public:
    // 2022.7.23, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/151.%20Reverse%20Words%20in%20a%20String
    // OJ: https://leetcode.com/problems/reverse-words-in-a-string/
    // Author: github.com/lzl124631x
    // Time: O(S)
    // Space: O(1)
    void reverseWords(string &s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            while (j < s.size() && s[j] == ' ') ++j;
            if (i != 0 && j != s.size()) s[i++] = ' ';
            while (j < s.size() && s[j] != ' ') s[i++] = s[j++];
        }
        s.erase(i);
        i = j = 0;
        while (i < s.size()) {
            j = i;
            while (j < s.size() && s[j] != ' ') ++j;
            reverse(s.begin() + i, s.begin() + j);
            i = j + 1;
        }
        reverse(s.begin(), s.end());
    }
};


class Solution97 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/151.%20Reverse%20Words%20in%20a%20String
    // OJ: https://leetcode.com/problems/reverse-words-in-a-string/
    // Author: github.com/lzl124631x
    // Time: O(S)
    // Space: O(S)
    string reverseWords(string s) {
        string ans;
        for (int i = s.size() - 1; i >= 0;) {
            while (i >= 0 && s[i] == ' ') --i;
            if (i < 0) break;
            if (ans.size()) ans += ' ';
            int j = i;
            while (j >= 0 && s[j] != ' ') --j;
            for (int k = j + 1; k <= i; ++k) ans += s[k];
            i = j;
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/151.%20Reverse%20Words%20in%20a%20String
    // OJ: https://leetcode.com/problems/reverse-words-in-a-string/
    // Author: github.com/lzl124631x
    // Time: O(S)
    // Space: O(S)
    string reverseWords(string s) {
        istringstream ss(s);
        string word, ans;
        while (ss >> word) {
            reverse(word.begin(), word.end());
            if (ans.size()) ans += ' '; 
            ans += word;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution95 {
public:
    // 2022.7.25, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/151.%20Reverse%20Words%20in%20a%20String
    // OJ: https://leetcode.com/problems/reverse-words-in-a-string/
    // Author: github.com/lzl124631x
    // Time: O(S)
    // Space: O(S)
    string reverseWords(string s) {
        istringstream ss(s);
        string word, ans;
        while (ss >> word) {
            if (ans.size()) word += " ";
            ans = word + ans;
        }
        return ans;
    }
};


class Solution94 {
public:
    // 2022.7.23, from https://walkccc.me/LeetCode/problems/0151/
    string reverseWords(string s) {
        reverse(begin(s), end(s));          // reverse the whole string
        reverseWords(s, s.length());        // reverse each word
        return cleanSpaces(s, s.length());  // clean up spaces
    }

private:
    void reverseWords(string& s, int n) {
        int i = 0;
        int j = 0;

        while (i < n) {
        while (i < j || i < n && s[i] == ' ')  // skip spaces
            ++i;
        while (j < i || j < n && s[j] != ' ')  // skip non spaces
            ++j;
        reverse(begin(s) + i, begin(s) + j);  // reverse the word
        }
    }

    // trim leading, trailing, and middle spaces
    string cleanSpaces(string& s, int n) {
        int i = 0;
        int j = 0;

        while (j < n) {
        while (j < n && s[j] == ' ')  // skip spaces
            ++j;
        while (j < n && s[j] != ' ')  // keep non spaces
            s[i++] = s[j++];
        while (j < n && s[j] == ' ')  // skip spaces
            ++j;
        if (j < n)  // keep only one space
            s[i++] = ' ';
        }

        return s.substr(0, i);
    }
};


class Solution93 {
public:
    // 2022.7.23, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-words-in-a-string.cpp
    // note that the function return is changed from void to string below
    // Time:  O(n)
    // Space: O(1)
    string reverseWords(string &s) {
        // Reverse the whole string first.
        reverse(s.begin(), s.end());

        size_t begin = 0, end = 0, len = 0;
        while ((begin = s.find_first_not_of(" ", end)) != string::npos) {
            if ((end = s.find(" ", begin)) == string::npos) {
                end = s.length();
            }
            // Reverse each word in the string.
            reverse(s.begin() + begin, s.begin() + end);

            // Shift the word to avoid extra space.
            move(s.begin() + begin, s.begin() + end, s.begin() + len);
            len += end - begin;
            s[len++] = ' ';
        }
        s.resize(len ? len - 1 : 0);

        // Modified by Hsinan. LC changed the return from void to string of the given string now
        return s;
    }
};


class Solution92 {
public:
    // 2022.7.23, from AcWing
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/245/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    // 算法
    // (数组翻转) O(n)O(n)
    // 分两步操作：
    //
    // 将字符串中的每个单词逆序，样例输入变为: "eht yks si eulb"；
    // 将整个字符串逆序，样例输入变为："blue is sky the"；
    // 时间复杂度分析：整个字符串总共扫描两遍，所以时间复杂度是 O(n)O(n)。
    // 且每次翻转一个字符串时，可以用两个指针分别从两端往中间扫描，每次交换两个指针对应的字符，
    // 所以额外空间的复杂度是 O(1)O(1)。
    string reverseWords(string s) {
        int k = 0;
        for (int i = 0; i < s.size();)
        {
            int j = i;
            while (j < s.size() && s[j] == ' ') j ++ ;
            if (j == s.size()) break;
            i = j;
            while (j < s.size() && s[j] != ' ') j ++ ;
            reverse(s.begin() + i, s.begin() + j);
            if (k) s[k ++ ] = ' ';
            while (i < j) s[k ++ ] = s[i ++ ];
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());

        return s;
    }
};


class Solution91 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/151
    /*
        这道题让我们翻转字符串中的单词，题目中给了我们写特别说明，如果单词之间遇到多个空格，只能返
        回一个，而且首尾不能有单词，并且对C语言程序员要求空间复杂度为O(1)，所以我们只能对原字符串
        s之间做修改，而不能声明新的字符串。那么我们如何翻转字符串中的单词呢，我们的做法是，先整个字符
        串整体翻转一次，然后再分别翻转每一个单词（或者先分别翻转每一个单词，然后再整个字符串整体翻转一次），
        此时就能得到我们需要的结果了。那么这里我们需要定义一些变量来辅助我们解题，storeIndex表示
        当前存储到的位置，n为字符串的长度。我们先给整个字符串反转一下，然后我们开始循环，遇到空格直接
        跳过，如果是非空格字符，我们此时看storeIndex是否为0，为0的话表示第一个单词，不用增加空格；
        如果不为0，说明不是第一个单词，需要在单词中间加一个空格，然后我们要找到下一个单词的结束位置
        我们用一个while循环来找下一个为空格的位置，在此过程中继续覆盖原字符串，找到结束位置了，下面
        就来翻转这个单词，然后更新i为结尾位置，最后遍历结束，我们剪裁原字符串到storeIndex位置，
        就可以得到我们需要的结果，代码如下：

        C++ 解法一：
    */
    // Note, need to change the return from void to string, and add return at the end to pass new LC
    string reverseWords(string &s) {
        int storeIndex = 0, n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != ' ') {
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                while (j < n && s[j] != ' ') s[storeIndex++] = s[j++];
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
        return s;
    }
};


class Solution90 {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/151
    /*
        下面我们来看使用字符串流类stringstream的解法，我们先把字符串装载入字符串流中，然后定义一个临时
        变量tmp，然后把第一个单词赋给s，这里需要注意的是，如果含有非空格字符，那么每次>>操作就会提取连在
        一起的非空格字符，那么我们每次将其加在s前面即可；如果原字符串为空，那么就不会进入while循环；如果
        原字符串为许多空格字符连在一起，那么第一个>>操作就会提取出这些空格字符放入s中，然后不进入while循环，
        这时候我们只要判断一下s的首字符是否为空格字符，是的话就将s清空即可，参见代码如下：

        C++ 解法二：
    */
    string reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(!s.empty() && s[0] == ' ') s = "";
        return s;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/grandyang/leetcode/issues/151
    /*
        下面这种方法也是使用stringstream来做，但是我们使用了getline来做，第三个参数是设定分隔字符，
        我们用空格字符来分隔，这个跟上面的>>操作是有不同的，每次只能过一个空格字符，如果有多个空格字符
        连在一起，那么t会赋值为空字符串，所以我们在处理t的时候首先要判断其是否为空，是的话直接跳过，
        参见代码如下：

        C++ 解法三：
    */
    string reverseWords(string &s) {
        istringstream is(s);
        s = "";
        string t = "";
        while (getline(is, t, ' ')) {
            if (t.empty()) continue;
            s = (s.empty() ? t : (t + " " + s));
        }
        return s;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

