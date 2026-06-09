执行用时 :12 ms, 在所有 C++ 提交中击败了99.23%的用户
内存消耗 :11.6 MB, 在所有 C++ 提交中击败了92.92%的用户
```
/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
/*
思路：双指针思想，时间复杂度O(n),空间复杂度O(1)。
使用front跟back指向单词的首尾，然后反转并更新两个指针的值
 */
class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.size() == 0){//如果s是空字符串，直接返回
            return s;
        }
        int front = 0, back = 0;//front为要反转的单词的首字母，back为要反转的单词的末字母的下一位
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] != ' '){
                back++;
            }
            else{
                reverse(s.begin() + front, s.begin() + back);
                front = back + 1; //当前back指向空格，所以front要从空格的下一个即下一个单词的首字母开始
                back = front;//front跟back同一线
            }
        } //此时最后一部分还没有反转，因为s的末尾不是空格，所以此时back应等于最后一个单词的末字母
        back++;
        reverse(s.begin() + front, s.begin() + back); //reverse的最后一个参数是要反转的结尾的下一位，back指向s的最后一位，所以要+1
        return s;
    }
};

```
