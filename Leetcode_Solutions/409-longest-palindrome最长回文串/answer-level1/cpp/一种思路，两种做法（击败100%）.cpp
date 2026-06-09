### 解题思路
这个题目的解决办法和上次的每日一题有点类似，都是从备选的数字或者字符里面挑选然后组合成新的序列，看是否满足题目条件。

上次那题是从备选中挑选字符，看是否能组成给定字符：
  难点：顺序不同，暴力TLE。
  方法：
    1.既然顺序不同，那咱就给两个字符串都排序，然后双指针遍历。
    2.储存备选字符出现次数，看是否能够覆盖给定字符串的字符。


这题是从被选中挑选字符，求组成的回文字符串中最长的串的长度。
首先要明确，并不需要输出那个串，所以不用傻乎乎地去真的把串给凑出来，我们只需要统计长度就行。

  思路：究竟怎么样才能回文呢？很明显，以中间那个轴对称的串就是回文，且对称的相同字符（在对称轴左右两边的）相加起来必定是偶数（不然不满足对称）。
   
   所以方法：
   统计备选字符中52个字符出现的次数（小写+大写）：
      1.偶数个出现次数的直接符合条件，加入到长度里。
      2.奇数个的减一不就是偶数个了吗？BUT,回文串长度可以是奇数，也就是说中间对称轴可以是个字符，所以第一个奇数次数出现的字符次数可以全部加入到length里。

   实现：
    1.很明显，统计次数多半用字典，cpp用map（红黑树）或者hash实现
    2.因为只有52个字符，且有递增1的关系，所有直接用数组也很方便。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty()) return 0;
        map<char,int> cnt;
        int len = 0;
        for(int i = 0;i < s.size();++i) 
          cnt[s[i]]++;

        bool hasUnevenNum = false;
        for(map<char,int>::iterator pos = cnt.begin();pos != cnt.end();++pos){
           int num = pos->second;
           if(num % 2 == 0) len += num;
           else{
               len = len + num - 1;
               if(!hasUnevenNum){
                   ++len;
                   hasUnevenNum = true;
               }
           }
        }
        return len;
    }
    /*
        vector<int> lowerLetters(27,0);
        vector<int> upperLetters(27,0);
        for(int i = 0;i < s.size();++i){
            if(s[i] >= 'a' && s[i] <= 'z')
              lowerLetters[s[i] - 'a']++;
            else if(s[i] >= 'A' && s[i] <= 'Z')
              upperLetters[s[i] - 'A']++;
        }
        int len = 0;
        bool hasUnevenNum = false;
        for(int i = 0;i < 26;++i){
            if(lowerLetters[i] % 2 == 0) len += lowerLetters[i];
            else if(lowerLetters[i] % 2 != 0){
               len = len + lowerLetters[i] - 1;
                if(!hasUnevenNum){
                len++;
                hasUnevenNum = true;
              }
            } 
            if(upperLetters[i] % 2 == 0) len += upperLetters[i];
            else if(upperLetters[i] % 2 != 0){
              len = len + upperLetters[i] - 1;
              if(!hasUnevenNum){
                len++;
                hasUnevenNum = true;
            } 
        }
        }
        return len;*/
};
```