我做这题的时候还没有太详细的题解，我这里就先做一下吧。
我这个的思想来自于美区@nraptis的评论

此题动态规划开了一个数组`list`，`list[i]`代表前`i`个字符需要划分几次，数组长度为`l+1`（`l`为字符串`s`的长度），
初始化为`[-1, 0, 1,..., l]`（规定前`0`个字符需要`-1`次）

然后从`i = range(l)`循环一次，每次以`s[i]`为中心寻找回文子串，当找到从`start`到`end`为回文串时，

设置`list[end+1]=min(list[start]+1, list[end+1])`
如果这是回文串，那么到这里为止的划分次数可以为这个回文串前面所需的次数+1）

比如"ggbobanabob"：
```
[Initial] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
[Loop 0] { 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10} //g
[Loop 1] { 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10} //g
[Loop 2] { 0, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10} //b
[Loop 3] { 0, 0, 1, 2, 1, 5, 6, 7, 8, 9, 10} //o
[Loop 4] { 0, 0, 1, 2, 1, 5, 6, 7, 8, 9, 10} //b
[Loop 5] { 0, 0, 1, 2, 1, 2, 6, 7, 8, 9, 10} //a
[Loop 6] { 0, 0, 1, 2, 1, 2, 3, 2, 3, 2, 1} //n
...
```

代码如下：
```c++
class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        vector<int> list(l+1); // list[i]代表前i个字符需要划几次，特别地，list[0]=-1
        for(int i = 0;i < l+1;++i){ // 初始化[-1, 0, 1, 2, 3...]
            list[i] = i - 1;
        }
        for(int i = 0;i < l;++i){ // 以每个字符为中心找最长回文子串
            list[i+1] = min(list[i+1], list[i] + 1); // 初始化，最坏情况下就比左边的多划一次
            if(i == l-1){ // 最后一个了没必要找了
                break;
            }
            // 先找偶数个的
            int start = i, end = i+1;
            while(s[start] == s[end]){
                list[end+1] = min(list[end+1], list[start]+1);
                if(end == l-1 || start == 0){
                    break;
                }
                --start, ++end;
            }
            // 再找奇数个的
            start = i-1, end = i+1;
            if(start < 0){
                continue;
            }
            while(s[start] == s[end]){
                list[end+1] = min(list[end+1], list[start]+1);
                if(end == l-1 || start == 0){
                    break;
                }
                --start, ++end;
            }
            // 如果整个串都是回文串，那么就中断
            if(list[l] == 0){
                return 0;
            }
        }
        return list[l];
    }
};
```
