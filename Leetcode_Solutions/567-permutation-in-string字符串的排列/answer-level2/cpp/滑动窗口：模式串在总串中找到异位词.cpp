**题解：**
本题属于[438.找到字符串中的所有字母异位词](https://blog.csdn.net/qq_43152052/article/details/102509079)的子题，前者是找到所有异位词并添加异位词出现的下标，而本题比前者简单多了，若在总串找到模式串的异位词，直接返回ture就行了；若遍历完整个总串也没找到模式串的异位词，返回false就行。

**代码如下：**
```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //s1不是s2的子串，直接排除
        if(s1.size()>s2.size())return false;
        
        int left=0,right=0;
        vector<int> needs(26,0),window(26,0);//needs表示s1的字符表，window表示窗口，用来匹配s1的字符表needs
        
        for(char c:s1)
        {
            needs[c-'a']++;
            window[s2[right++]-'a']++;
        }
        
        if(window==needs)return true;//s2的前s1.size()个字符刚好与s1为异位词
        
        while(right<s2.size())//开始滑动窗口
        {
            window[s2[right++]-'a']++;
            window[s2[left++]-'a']--;
            if(window==needs)return true;
        }
        return false;
    }
};
```
