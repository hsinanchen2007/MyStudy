总思路：找到每个单词的头和尾，反转
（我会说其实看到题目第一反应是s.split(' ')？？？人生苦短，请用python）
# Solution1 临时变量反转法
```C++
class Solution {
public:
    string reverseWords(string s) {
        string answer;
        string tem;
        for(char c:s)
            if(c==' '){
                answer += (tem + ' ');
                tem.clear();
            }
            else
                tem = c + tem;
        answer += tem;
        return answer;
    }
};
```
# Solution2 swap法
引入哨兵，使得字符串末端与正常情况一致，减少判断次数；
```
class Solution {
public:
    void exchange(string &s,int &left, int right){
        while(left<right)
            swap(s[left++], s[right--]);
    }
    string reverseWords(string& s) {
        int left = 0;
        int right = 1;
        int end = s.size();
        s[end] = ' ';
        while(right<end){
            while(s[right++]!=' ');
            exchange(s, left, right - 2);
            left = right;
        }
        s[end] = '\0';
        return s;
    }
};
```
# Solution3 迭代器法
采用迭代器可以用reverse方法，交换[begin,end-1]区间内元素
```C++
class Solution {
public:
    string reverseWords(string s) {
        if(s.size()<=1)
            return s;
        auto begin = s.begin();
        auto end = s.begin();
        auto s_end = s.end();
        *s_end = ' ';
        while(1){
            while(*(++end)!=' ');
            reverse(begin, end);
            if(end==s_end)
                break;
            begin = ++end;
        }
        *s_end = '\0';
        return s;
    }
};
```