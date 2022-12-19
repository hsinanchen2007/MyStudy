这道题的特点。
第一，国外面试的常考题。
第二，思路其实真的很好想，就是用窗口嘛。
第三，写出一个低耗时的方案，中间还是有一些弯弯绕绕的。

我这边是直接硬写，一直超时，然后就撇一眼答案，优化下，结果发现还是超时，迭代了整整三轮。
我这边把我的迭代思路记录一下。


原始string为S，目标string为T

**第一轮**
窗口初始长度为T的长度，然后从S的第一个字符一直遍历到最后，每一次都需要判断当前窗口的字符串跟T是否包含。
找到就返回结果，找不到就把窗口长度加长。
我这里还优化了一把，窗口长度加长的时候，是根据窗口的字符和T相差几个字符来相加的。
结果还是超时

**第二轮**
看了下答案，发现通过两个指针轮流增长的方式，保证一次遍历即可有结果。
想着这次耗时没问题了，结果还是超时。我当时就日了狗了，想了半天也没想到怎么来优化。。
超时原因在于，我这边的每次窗口变化，都会拿窗口的字符串判断是不是T的substring，为此还专门写了个函数快速调用。
```
    int anagram(string &s, int begin, int slide_window_len, string &t) {
        unordered_map<char, int> char_count_map;
        for (int j = 0; j < t.size(); ++j) {
            char_count_map[t[j]] += 1;
        }
        for (int i = 0; i < slide_window_len; ++i) {
            char_count_map[s[begin + i]] -= 1;
        }
        int lack_len = 0;
        for (auto &char_count_map_iter : char_count_map) {
            if (char_count_map_iter.second > 0) {
                lack_len += char_count_map_iter.second;
            }
        }
        return lack_len;
    }
```


**第三轮**
这次我是真的被逼无奈了，只能直接去看代码了。。
结果发现，超时的根源就在于我每次判断窗口字符串是不是T的substring。。
这一步可以通过一个int变量快速判断。
https://leetcode-cn.com/problems/minimum-window-substring/solution/c-unordered_map-8ms-9847-by-karlzhang/
看到这一步的时候，我就草了。

最后，这道题面试的时候如果之前没刷过就硬刚，真的是只能认倒霉，有些trick点没那么好想。。
最终版本的代码
```
 string minWindow(string s, string t) {
        unordered_map<char, int> char_count_map;
        int left = 0;
        int result_begin = 0;
        int result_len = INT_MAX;
        for (int i = 0; i < t.size(); ++i) {
            //intial the map
            ++char_count_map[t[i]];
        }
        //count的值用来判断是否当前窗口满足要求
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (char_count_map[s[i]] - 1 >= 0) {
                //说明s当前的char命中了t中的某个char
                ++count;
            }
            //无论怎么样，都要
            --char_count_map[s[i]];
            while (count == t.size()) {
                //存储最小的窗口值
                if (i - left + 1 < result_len) {
                    result_len = i - left + 1;
                    result_begin = left;
                }
                //count = t.size()说明当前窗口已经跟t匹配，那么就要把左边窗口移动
                //此时所char_count_map[s[i]]中的值要么为零，要么为负
                if(char_count_map[s[left]] + 1 > 0) {
                    //说明这个窗口已经不满足条件了
                    
                    --count;
                }
                ++char_count_map[s[left]];
                ++left;   
            }
        }
        if (result_len == INT_MAX) {
            return "";
        }
        return s.substr(result_begin, result_len); 
}
```
最后，感谢@labuladong提供的另外两例题，把最后的模版改一改，直接套上就能用。
题号是3和438
