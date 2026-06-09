### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>counts(26,0);//记录当前窗口字母出现的次数
        int left=0,maxCnt=0,res=0;
        for(int i=0;i<s.size();i++){
            counts[s[i]-'A']++;//记录到第i个字母为止，每个字母出现的次数
            maxCnt=max(maxCnt,counts[s[i]-'A']);//获取出现次数最多的字母次数
            //(i-left+1)为窗口长度，减去maxCnt后得到需改变的字母数量
            while(i-left+1-maxCnt>k){//若需改变的字母数量大于k时，窗口滑动
                //最左侧窗口滑动，同时丢掉最左侧的一个字母，即该字母数量减1
                counts[s[left]-'A']--;//在后续max比较中，丢掉的这个字母的数量就回减一
                left++;
            }
            res=max(res,i-left+1);//满足条件时，比较更新最长长度
        }
        return res;
    }
};
```