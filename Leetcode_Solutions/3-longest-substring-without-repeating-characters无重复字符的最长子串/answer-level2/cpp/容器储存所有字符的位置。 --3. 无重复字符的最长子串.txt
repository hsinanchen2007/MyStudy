### 解题思路
看到这道题的时候原以为和剑指offer中48题一样，结果编译一直不通过，才发现剑指offer限制了字符为'a'~'z'。坑死了，。。。但基本思路是一样的。
1.先定义一个容器，用来存放每个字符的位置信息，并初始化为-1。vector<int> position(128,-1);
2.用start表示子串的起始字符，end表示子串的结尾字符。并用end下标来控制循环。
3.使用curLength和maxLength分别定义当前子串和目前最长子串的大小。
4.需要注意的是s[end]字符有三种可能
   第一次出现。 
   不是第一次出现，且上一次出现的位置在当前子串中。
   不是第一次出现，且上一次出现的位置在当前子串之前。
5.容器大小：
   只有字母大小为26，ASC11码为128， 扩展ASC11码用256.

结果：
执行用时 :8 ms, 在所有 C++ 提交中击败了92.65% 的用户
内存消耗 :9 MB, 在所有 C++ 提交中击败了93.14%的用户

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1) return s.length();
        int start=0;
        int end=0;
        int curLength=0;
        int maxLength=0;
        vector<int> position(128,-1);
        while(end<s.length())
        {
            char temp = s[end];
            if(position[int(temp)]>=start) //不是第一次出现，且上一次出现的位置在当前子串中。
            {
                start = position[int(temp)]+1;
                curLength = end-start;
            }
            position[int(temp)]=end; //记住，一定要把当前的位置再保存起来。
            curLength++;
            end++;
            maxLength = max(curLength,maxLength);
        }
        return maxLength;
    }
};
```