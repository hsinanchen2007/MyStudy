看到字符串，看到不重复。滑动窗口+hash套餐送上，然后加上一个begin变量维护窗口头位置。后续发现重复的字符不一定是在窗口头，那么map用上，因为需要判断重复的字符是不是在窗口内（>=begin），所以代码如下。
```
//滑动窗口+hashmap+其中加入了index以保存当前字符串头
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i,begin=0,max=0;
        unordered_map<char,int> map;
        for(i=0;i<s.length();i++){
            if(map.find(s[i])==map.end() || map[s[i]]<begin)  //没重复或重复的是当前字符串之前的字符
                map[s[i]]=i; 
            else{  //重复了
                max = i-begin>max?i-begin:max; //update
                begin=map[s[i]]+1;
                map[s[i]]=i;
            }
        }
        max = i-begin>max?i-begin:max;
        return max;
    }
};
```
