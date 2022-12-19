### 解题思路
菜鸡第一次内存消耗打败100%，激动的来写题解。

在S字符串里采取一个滑动窗口来获得重复字符的长度。
end是窗口结束的下标，beg是窗口开始的下标。
以S="aaab"为例，一开始beg指在S[0]处，为了知道a字符一直重复到哪里结束，我们任由end指针++直到end所指的S[3]与S[0]不相等，此时我们做统计a字符串的长度（end-beg），并录入res字符串。
注意：
end为什么可以取S.length()？
方便边界操作。如果不可以取S.length()，那么最后一组重复字符串没有办法进行记录了，因为直到end取完整个S字符串都没有对最后一组重复字符串做相应判断。

res+=to_string(end-beg)这一步我是看了别人的代码才知道可以写这个库函数。一开始我采取的是res+=end-beg+'0'，但是当end-beg>=10时，这样的写法就会变成其他的字符，不再是数字形式。ps，看来我的基本功还需要加强。


### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int a = S.length();
        string res;
        int beg = 0; 
        int end;
        for(end=1;end<=a;end++)
        {
            if(S[end]!=S[beg]||end==a)
            {
                res+=S[beg];
                res+=to_string(end-beg);
                beg=end;
            }
        }
        return res.length()>=a?S:res;
    }
};
```