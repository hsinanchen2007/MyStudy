### 解题思路
其实这道题的解题思路可以参照示例2：s = "3[a2[c]]", 返回 "accaccacc". 这让我们很容易想到，我们需要用到递归的思想，因为存在了嵌套的现象。

1、首先，如果字符串的长度小于2，那么一定不存在"n[...]"这种情况，其中n是数字，"..."代表任意字符串（可以为空），所以我们直接返回结果就行了。
2、如果字符串不是以数字开头，那么照搬下来就可以了，如示例3：s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef". 它的尾部是"ef"，没有数字打头，那么结果直接加上ef就行了。也就是说如果给定的字符串编码是不包含数字的（如"abs"），那么结果就是其本身（"abs"）。
3、对于接下来的"n[...]"格式的部分，我们需要找到数字是多少，以便确定需要加多少次这个字符串。
4、接下来我们需要确定一对"[]"，也就是找到匹配的"["和"]"。很容易想到，如果我们找到一个"]"，使得之前"["和"]"的数量一样多，那么他们就是一对匹配的"[]"。
5、这一步是需要确定"n[...]"中"..."的内容，因为可能"..."是"xxxn[...]"的格式，也就是存在嵌套，所以我们需要递归的思路去确定"..."的内容。
6、将"..."的内容复制n份加在result的后面。
7、对s后面未处理的字符串，同样使用递归的思路确定其内容，然后加在result后面即可。

### 代码

```cpp
class Solution {
public:
    string decodeString(string s) {
        int length = s.length();
        // 长度小于等于2，直接返回结果
        if (length <= 2) return s;

        string result;
        // 如果不是以数字字符打头，那么将这一部分字符直接加在result后面。
        int cur = 0;
        while (cur < length && (s[cur] < '0' || s[cur] > '9')) {
            cur ++;
        }
        result += s.substr(0, cur);
        // 是否到达字符串尾部？如果是则返回result。
        if (cur >= (length - 1)) return result;
        // 由于上面已经处理掉了非数字字符，也就是下一个字符必然是数字，而数字之后必然是"["，
        // 由此可以确定n
        int cur_start = cur;
        while (s[++cur_start] != '[') {}
        int num = stoi(s.substr(cur, cur_start - cur));
        // 找到一对匹配的"[]"
        int count_pre = 1;
        int count_post = 0;
        int cur_end = cur_start;
        while (count_pre != count_post) {
            cur_end ++;
            if (s[cur_end] == '[') count_pre ++;
            else if (s[cur_end] == ']') count_post ++;
        }
        // 用递归的思想确定"n[...]"中"..."的内容，因为可能存在嵌套
        string temp = decodeString(s.substr(cur_start+1, cur_end - cur_start - 1));
        // 复制n份给result
        for (int i = 0; i < num; i ++)
            result += temp;
        // 处理s后未处理的字符串，直接递归一下就好了。
        result += decodeString(s.substr(cur_end + 1, length - cur_end - 1));
        return result;
    }
};
```