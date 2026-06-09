其实可以维持两个哈希表，分别保存着s1的字母频率和s2子序列的字母频率，然后每次出窗入窗操作偶读更新s2的哈希表，并且比较两个哈希表是否相同，相同则立刻返回true。

但是我觉得这样每次入窗出窗操作都要比较一次，假设s1、s2长度分别是m，n，那么最坏情况的时间复杂度是$O((m-n)\times 26)$。嗯？似乎也可以接受哈。

为了不每次都比较两个哈希表，我决定只维护一个哈希表，记录着两个序列字母频率的差值。当该哈希表中所有元素都为0时，就说明两序列匹配了。所以需要定义一个变量zeroCount，表明该哈希表中0的个数。当哈希表中0的个数为26时返回true就好了。但是我觉得我这种思路在实现的时候可能有很多小细节需要注意，不如上面那种粗暴的做法。

我觉得这里还可以有一个通用的思路，就是当你需要遍历某个数组/表/向量中的所有元素以获得某个值时，如何能避免这种遍历呢？一个思路就是，***在更新该数组的同时，也同步更新你想要得到的那个值。***

```
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int table[26]={0};//s1和s2字母出现次数差值的哈希表
        int zeroCount = 26;//哈希表中0的个数，当26个字母出现次数的差值都为0（即s2子序列和s1的字母完全相同）时，说明满足条件，此时哈希表中0的个数为26
        for (auto c:s1) {
            if(table[c-'a']==0) zeroCount--;
            table[c-'a']++;
        }
        int w = s1.size();

        for(int j=0;j<s2.size();j++){
            if(table[s2[j]-'a'] == 0) zeroCount--;//右指针移动，如果原来字母s2[j]对应的出现次数差值为0时，s2[j]入窗则zeroCount减一
            table[s2[j]-'a']--;//入窗，s2[j]对应哈希表减一
            if(table[s2[j]-'a'] == 0) zeroCount++;//入窗后如果s2[j]对应哈希表为0，则zeroCount加一
            if(zeroCount == 26) return true;//0的个数为26时返回true

            if(j<w)continue;//什么时候开始出窗
            if(table[s2[j-w]-'a'] == 0) zeroCount --;
            table[s2[j-w]-'a']++;
            if(table[s2[j-w]-'a'] == 0) zeroCount ++;
            if(zeroCount == 26) return true;
        }
        return false;
    }
};
```
打败93%，100%