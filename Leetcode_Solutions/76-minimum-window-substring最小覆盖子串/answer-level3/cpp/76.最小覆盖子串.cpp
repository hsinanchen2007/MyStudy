### 解题思路
代码参考了[labuladong](https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/)的工作，不过我用数组代替map以加快速度。

这道题一开始我理解有问题，我以为只要t中出现过的字母被s的子序列包含就行了，没有考虑t中字母出现的数量，导致当s="a"和t="aa"时程序报错。

其实这道题很简单，与求和[209.长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)的思路很想，都是当满足条件时左指针持续进1后判断是否满足条件。

问题的关键就在于判断window中是否已经包含了所有需要的字母。最开始我的解法是写一个函数，函数输入是window和need的哈希表，然后比较两个哈希表是否完全相同，结果超时了，改进一下后不超时但是很慢。。。

后来看了别人的解法，其实加速的思路也是一样的，就是不要每次更新都从头到尾比较一次哈希表，而是 ***只计算变动的那一部分是否会导致条件满足***。


### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int sHash[128]={0};
        int tHash[128]={0};
        int ans_i(0),ans_j(0),len(INT_MAX),match(0),tHashSize(0);
        for(auto c:t){
            if(tHash[int(c)]==0)
                tHashSize++;
            tHash[int(c)]++;
        }
        for(int i=0,j=0;j<s.size();j++){
            sHash[int(s[j])]++;
            if(sHash[int(s[j])] == tHash[int(s[j])])//这一步是最难想到的，最开始我想的判断条件是前者大于等于后者，后来仔细想想，不行，必须得恰好等于。因为但新添加一个字母时我们要检查的是是否因为新加的这个字母使得匹配的变多了，那么如果是大于关系的话，确实该新字母匹配了，但是匹配的数量并没有增加。只有当原来不匹配，新加字母后正好匹配了，才会使匹配数增加
                match++;
            while(match == tHashSize){
                if(j-i+1<len){
                    len = j-i+1;
                    ans_i = i;
                    ans_j = j;
                }
                sHash[int(s[i])]--;
                if(sHash[int(s[i])]<tHash[int(s[i])])
                    match -- ;
                i++;
            }
        }
        return len==INT_MAX?"":s.substr(ans_i,len);
    }

};
```