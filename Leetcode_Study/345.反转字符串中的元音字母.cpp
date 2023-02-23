/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

/*

https://leetcode.cn/problems/reverse-vowels-of-a-string/

345. 反转字符串中的元音字母

简单
283
company
苹果 Apple
company
Facebook
company
彭博 Bloomberg

给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。

示例 1：

输入：s = "hello"
输出："holle"

示例 2：

输入：s = "leetcode"
输出："leotcede" 

提示：

1 <= s.length <= 3 * 105
s 由 可打印的 ASCII 字符组成

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.22, from https://www.acwing.com/solution/content/370/
    // 作者：yxc
    // 链接：https://www.acwing.com/solution/content/370/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    /*
        算法
        (双指针扫描，字符串处理) O(n)

        用两个指针分别从首尾开始往中间扫描，扫描过程中忽略所有不是元音的字母，然后交换两个指针指向的字符。
        扫描过程一直持续到两个指针相遇为止。

        时间复杂度分析：字符串中每个元素只被扫描一遍，所以时间复杂度是 O(n)。    
    */
    string reverseVowels(string s) {
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        unordered_set<char> S;
        for (char c : vowels)
        {
            S.insert(c);
            S.insert(c - 32);
        }
        for (int i = 0, j = s.size() - 1; i < j;)
        {
            while (i < j && !S.count(s[i])) i ++ ;
            while (i < j && !S.count(s[j])) j -- ;
            if (i < j) swap(s[i], s[j]);
            i ++, j -- ;
        }
        return s;
    }
};


class Solution99 {
public:
    // 2023.2.22, from https://walkccc.me/LeetCode/problems/0345/
    // Time: O(n)
    // Space: O(1)
    string reverseVowels(string s) {
        const unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                        'A', 'E', 'I', 'O', 'U'};
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !vowels.count(s[l]))
                ++l;
            while (l < r && !vowels.count(s[r]))
                --r;
            swap(s[l++], s[r--]);
        }

        return s;
    }
};


class Solution98 {
public:
    // 2023.2.22, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/reverse-vowels-of-a-string.cpp
    // Time:  O(n)
    // Space: O(1)
    string reverseVowels(string s) {
        for (int i = 0, j = s.length() - 1; i < j;) {
            if (!is_vowel(tolower(s[i]))) {
                ++i;
            } else if (!is_vowel(tolower(s[j]))) {
                --j;
            } else {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }

private:
    const string vowels_ = "aeiou";
    bool is_vowel(char a){
        return vowels_.find(a) != string::npos;
    }
};


class Solution97 {
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    // 2023.2.22, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/345.%20Reverse%20Vowels%20of%20a%20String
    // OJ: https://leetcode.com/problems/reverse-vowels-of-a-string/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) ++i;
            while (i < j && !isVowel(s[j])) --j;
            if (i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};


class Solution96 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/345
    /*
        这道题让我们翻转字符串中的元音字母，元音字母有五个a,e,i,o,u，需要注意的是大写的也算，所以总共有十个字母。我们写一个
        isVowel的函数来判断当前字符是否为元音字母，如果两边都是元音字母，那么我们交换，如果左边的不是，向右移动一位，如果右边
        的不是，则向左移动一位，参见代码如下：

        解法一：    
    */
    string reverseVowels(string s) {
        int left = 0, right= s.size() - 1;
        while (left < right) {
            if (isVowel(s[left]) && isVowel(s[right])) {
                swap(s[left++], s[right--]);
            } else if (isVowel(s[left])) {
                --right;
            } else {
                ++left;
            }
        }
        return s;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};


class Solution95 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/345
    /*
        或者我们也可以用自带函数find_first_of和find_last_of来找出包含给定字符串中任意一个字符的下一个位置进行交换即可：

        解法二：    
    */
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            left = s.find_first_of("aeiouAEIOU", left);
            right = s.find_last_of("aeiouAEIOU", right);
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};


class Solution94 {
public:
    // 2023.2.22, from https://github.com/grandyang/leetcode/issues/345
    /*
        我们也可以把元音字母都存在一个字符串里，然后每遇到一个字符，就到元音字符串里去找，如果存在就说明当前字符是元音字符，
        参见代码如下：

        解法三：    
    */
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        string t = "aeiouAEIOU";
        while (left < right) {
            if (t.find(s[left]) == string::npos) ++left;
            else if (t.find(s[right]) == string::npos) --right;
            else swap(s[left++], s[right--]);
        }
        return s;
    }
};


class Solution93 {
public:
    // 2023.2.22, from https://zxi.mytechroad.com/blog/?s=LeetCode+345.
    // Author: Huahua
    // Running time: 8 ms
    string reverseVowels(string s) {
      int i = 0;
      int j = s.size() - 1;
      while (i < j) {
        while (!isVowel(s[i]) && i < j) ++i;
        while (!isVowel(s[j]) && i < j) --j;                
        swap(s[i++], s[j--]);
      }
      return s;
    }
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/ody2dv/?discussion=8ELDAR
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    string reverseVowels(string s) {
        int n = s.length();
        int left = 0 , right = n - 1;
        while(left < right){
            while(left < n && !isVowel(s[left])) left++;
            while(right > 0 && !isVowel(s[right])) right--;
            if(left < right){
                swap(s[left++] , s[right--]);
            }
        }
        return s;
    }

    bool isVowel(char c){
        if((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) return true;
        return false;
    }
};


// @lc code=end

