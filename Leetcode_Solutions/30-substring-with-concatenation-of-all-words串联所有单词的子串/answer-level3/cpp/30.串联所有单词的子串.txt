其实这道题有点像[567.字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)，或者说567题可以算是这道题的一种特殊情况。

这道题简单就简单在，所有单词的长度w都是相同的，如果单词长度也不相同，那难度就大大增加了。

思路就是大窗口套小窗口，大窗口的固定尺寸为words中单词个数n乘单词长度w，大窗口每次滑动一个字母。小窗口在大窗口中嵌套，由于单词长度都相同，故可以认为大窗口中就是n个相邻的单词，而小窗口的尺寸是单词的长度w，且小窗口每次滑动一个单词的长度。

这道题的本质就是判断大窗口中的单词是否是words中单词的一个排列，一个直接的思路就是创建两个哈希表分别保存着words的单词和大窗口的单词，在构建好大窗口的单词哈希表后与words的哈希表做对比。

但是没必要这样，其实只需要在遍历大窗口的单词时，判断该单词是否在words哈希表中，不在的话那么这个大窗口直接pass；如果在的话，要再看看这个单词在大窗口中出现的次数是否超过了words中的次数，超过的话大窗口直接pass。如果直到最后一个单词都没有被pass，那么这个大窗口就是答案之一。

一直觉得这种 ***如果到达最后一个，则成功*** 的思想觉得很神奇，这种思想减少了冗余的比较，在构建哈希表的过程中就已经实现了边建表边比较，而非等到表建完后再逐个比较。



### 代码

```cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> result;
        if(!words.size())//第一次提交报错，说是vector错了，我以为是return的时候错了，没想到是因为没有判断words这个vector是否为空
            return result;

        int sSize = s.size();
        int wSize = words[0].size();
        int wNum = words.size();
        map<string, int> wordHash;
        map<string, int> subHash;
        
        for(auto it:words)
            wordHash[it]++;

        for(int i=0;i<=sSize - wSize*wNum;i++){//这里每次滑动一个字母
            string subStr = s.substr(i,wSize*wNum);
            for(int j=0;j<=wSize*wNum - wSize;j+=wSize){//这里每次滑动一个单词
                string tmpWord = subStr.substr(j,wSize);
                if(wordHash[tmpWord]==0)//如果tmpWord这个key不存在，则这种访问方式其实是在wordHash里直接创建了一个key为tmpword，value为int的默认值0的pair。在这道题中由于最初的wordHash中不会存在0这个值，所以就可以通过判断key的value是否为0来确定key是否存在于原来的wordHash中。
                    break;//如果该单词不存在则直接跳出循环
                subHash[tmpWord]++;
                if(subHash[tmpWord]>wordHash[tmpWord])
                    break;//如果该单词的出现次数多了，也调出循环。因为单词出现的次数必须完全等于words中的次数
                if(j == wSize*wNum - wSize)
                    result.push_back(i);//如果循环到末尾了，说明这个子序列满足要求（如果到达最后一个，则成功）
            }
            subHash.clear();
        }
        return result;
    }
};
```