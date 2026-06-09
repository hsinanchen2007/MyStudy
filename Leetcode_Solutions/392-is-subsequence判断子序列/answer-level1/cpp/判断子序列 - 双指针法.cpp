### 解题思路
1. 可以知道的是，当扫描s中的第k个字符时，假如它在t字符串中的第i位和第j位都出现过(i < j)，那么我们从左到右扫描到第i位时，就认为已经找到了s中第k个字符。因为i后面有更多的备选字符可以用来找s中的剩余字符。也就是说，我们在t中找字符时，是严格不回溯的。这个问题可以使用`双指针`解决。

2. 初始化指针i，j为0，分别指向s和j的第0个字符，在t中找到s[i]字符后，i++试图找下一个字符。
3. 若最后i到达s末尾，则说明找到了该字符串

### 代码

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int m = s.size(), n = t.size();
        while(i < m && j < n){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else j++;
        }
        return i == m;
    }
};
```