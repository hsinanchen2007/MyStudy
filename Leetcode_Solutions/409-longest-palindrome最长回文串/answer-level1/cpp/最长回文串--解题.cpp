### 解题思路
此处撰写解题思路
（1）建立一个字典，为了来存放字符串中各个字符出现的次数。大概形如{'a':1,'b':2,'c':3}
（2）首先对字符串循环，统计字符出现次数
    i:若该字符还未出现在词典中，我们需要将其添加到词典，并赋计数值为0；
    ii:若该字符已经在词典中，计数值+1；
（3）词典已建好，我们要看每个字符出现的次数：
    i:偶数的话，所有字符都有效。举例'b'出现4次，那么可组成两对，4个字符'b'在最终所需的词中都要用到。
    ii:奇数的话，实际有效的字符需要-1；
    iii:将i ii两种情况相加，得到的必然为偶数，此时：
        1):若此数值不等于字符串长度，那么成双成对的配完了，我们可以向其中添加任意一个被遗留下的元素。此时返回的数值需要+1。
        2)：此数值若等于字符串长度，返回字符串长度。
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mymap;
        int length_s = s.length();
        for (int i = 0; i < length_s; i++)
        {	
            char char_i = char(s[i]);
            //printf("char i is :%c\n", char_i);
            if (&mymap[char_i]==NULL) { mymap[char_i] = 0; }
            else { mymap[char_i] += 1; }
        }

        int length_map = mymap.size();
        int count = 0;
        for (auto& x : mymap) {
            count += 2*(x.second / 2);

        }
        return count < length_s ? (count + 1) : count;
    }
};
```