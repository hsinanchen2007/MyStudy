![QQ图片20200205232757.png](https://pic.leetcode-cn.com/b3f1bc5a40f6aa795bd9a91c0545d92ceca70cb25605860ab06074886ec60dcb-QQ%E5%9B%BE%E7%89%8720200205232757.png)
思路：
对字符串遍历，遍历至第i个字符时，通过变量num存储当前无重复子串的长度，通过变量t存储当前无重复子串的起始位置;通过变量S存储当前得到的无重复子串的最大长度;通过数组k[128]记录前i-1个字符中不重复字符最后一次出现的下标位置,则对当前遍历的第i个字符，k[s[i]]记录了该字符s[i]上一次出现的下标，有两种情况：
若k[s[i]]<t:上一次重复位置小于当前无重复子串的初始位置，对当前记录无影响。
若k[s[i]]>=t:与当前无重复子串中字符有重复。需重置新无重复子串的初始位置t为k[s[i]]+1,重置新无重复子串的长度num为i-t+1;

每次出现情况2时，即判断num与S大小，并将大值存入S，一趟遍历后即得到结果。
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int num=0,S=0,t=0;
        int *k=new int[128]();
        for(int i=0;i<s.size();i++){
            if(k[s[i]]!=0||(i!=0&&s[i]==s[0])) t=k[s[i]]>=t?k[s[i]]+1:t;
            num=i-t+1;
            k[s[i]]=i;
            S=num>S?num:S;
        }
        return S;
    }
};
 
```


