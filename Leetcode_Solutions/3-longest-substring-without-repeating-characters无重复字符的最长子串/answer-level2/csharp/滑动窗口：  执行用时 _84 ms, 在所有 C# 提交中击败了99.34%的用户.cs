执行用时 :84 ms, 在所有 C# 提交中击败了99.34%的用户
内存消耗 :24.3 MB, 在所有 C# 提交中击败了5.46%的用户
假定窗口存储了最长子串，头尾指针分别记为head, end。下一个字符指针是( end + 1)，将该字符和[ head, end ]比较，如果在位置i 出现相同，则记录当前子串长度（end - head）,将窗口指针跟新为( i + 1, end + 1)，如此比较，直到走到末尾，返回最大长度
```c#
 public static int LengthOfLongestSubstring(string s){
            int head, end, cur, max = 0;
            head = end = 0;

            while (end != s.Length)
            {
                if (head != end)
                {
                    cur = head;
                    while (cur < end)
                    {
                        if (s[cur++] == s[end])
                        {
                            head = cur;
                            break;
                        }
                    }
                }
                max = max > (end - head + 1) ? max : (end - head + 1);
                end++;
            }

            return max;
}
```