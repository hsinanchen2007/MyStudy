假设区间$[a,b]$是满足题目要求的某子区间，其中$a,b$是字符串中的索引值（index）。设$E(x)$表示字符$x$最后（最右边）出现的位置，则其必要不充分条件为
$$\mathrm{max}_{a\leq i \leq b} E(S_i) = b$$
虽然这只是必要条件，但只要我们从左往右迭代，一满足如上条件，就可以判断为符合题意的子区间，然后继续判断下一个区间的右边界。

如果只遍历一次，那么过程中我们并不知道当前字符在后面是否还会出现，即不知道函数$E(x)$，也就不好判断当前步是否可以划分。所以考虑先遍历一次获取“先验知识”：将每个字符最后出现的位置存储在一个一元数组中。为什么选择记录最后出现的位置呢？因为区间内的元素的最后出现位置会决定每个子区间的右边界。

然后再遍历一遍字符串即可。子区间未确定时，每一步需要判断是否更新当前的可能右边界。

时间复杂度：$O(n)$；时间复杂度：$O(1)$（不考虑返回结果）。

```C++
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int end[26];
        memset(end, 0, 26);
        for(int i = 0; i < S.size(); ++i) 
            end[S[i] - 'a'] = i + 1;
        int left = 0, right = 1;
        int num = 0;
        while(left < S.size()) {
            for(; num + left < right; ++num) 
                right = max(right, end[S[num + left] - 'a']);
            ans.push_back(num);
            left = right;
            ++right; num = 0;
        }
        return ans;
    }
};
```