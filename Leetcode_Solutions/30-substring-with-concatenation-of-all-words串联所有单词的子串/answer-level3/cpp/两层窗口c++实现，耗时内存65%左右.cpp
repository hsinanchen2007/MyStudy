这道题做完，我就直奔题解区，想看看90的代码是怎么样的，结果发现一堆人把五十不到的都发出来了。。


这里抛砖引玉一下，提供一个思路。
首先，substring的题目，基本上肯定就是滑动窗口，把模版往上套就行了。
这里用了俩窗口，第一个窗口O(n)时间，快速缩小范围，第二个最终进行判断。

第一个窗口
先不考虑concat，就通过窗口快速判断，那些位置开始的字符串的char的总计和words vector中的char的总计相同。

这一步耗时很短，遍历一遍字符串就搞定了，用一个char的map就可以了。
用来快速缩小第二个窗口的范围。

第二个窗口
这个窗口就是把words中的word存入map中，然后用窗口的思路走下去就可以了。

最后内存耗时，都是在65左右，暂时是想不到什么好的idea了，大家有什么好的思路也欢迎贡献一下。

![image.png](https://pic.leetcode-cn.com/a7fad9e4c508d7d57ed8af3d71e8e53b71e08e9c408d617602625b05463ddef2-image.png)


代码如下
```
vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0) {
            return result;
        }

        unordered_map<char, int> char_count_map;
        unordered_map<string, int> string_count_map;
        for (int i = 0; i < words.size(); ++i) {
            ++string_count_map[words[i]];
            for (int j = 0; j < words[i].size(); ++j) {
                ++char_count_map[words[i][j]];
            }
        }        

        int windows_len = words.size() * words[0].size();
        int left = 0;
        int count = 0;
        //第一个窗口，快速缩小寻找范围
        for (int i = 0; i < s.size(); ++i) {
            --char_count_map[s[i]];
            if (char_count_map[s[i]] >= 0) {
                ++count;
            } 
            if (i - left == windows_len - 1) {
                if (count == windows_len) {
                    //在这里调用第二个窗口
                    if (is_concatenation(s, left, string_count_map, words[0].size(),
                        words.size())) { 
                        result.push_back(left);
                    } 
                }
                ++char_count_map[s[left]];
                if (char_count_map[s[left]] > 0) {
                    --count;
                }
                ++left;
            }
        }

        return result;
    }
    //第二个窗口，用来最终判断字符串是否匹配
    int is_concatenation(string &s, int begin, unordered_map<string, int> string_count_map,
        int word_len, int word_count) {
        if (begin + word_len * word_count > s.size()) {
            return false;
        } 
        int count = 0;
        for (int i = 0; i < word_count; ++i) {
            string temp_string = s.substr(begin + i * word_len, word_len);
            --string_count_map[temp_string];
            if (string_count_map[temp_string] >= 0) {
                ++count;
            }
            else {
                return false;
            }
        }
        return true;
    }
```
