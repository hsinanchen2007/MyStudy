1）用滑动窗口，首先找到包含t的子串；

2）然后逐渐的缩小左侧求更小满足条件的值；

3）该子串全部找完后，右侧扩展子串，直到满足条件，后迭代进行上述操作；

即（找到右侧，缩小左侧，更新右侧直至找到右侧，迭代。。。）

```
class Solution {
public:
    string minWindow(string s, string t) {
        int left=0,right=0,match=0;
        int start=0,minLen=INT_MAX;
        unordered_map<char,int> needs;
        unordered_map<char,int> window;
        for(auto c:t) needs[c]++;
        while(right<s.size()){
            char c1=s[right];
            if(needs.count(c1)){
                window[c1]++;
                if(window[c1]==needs[c1]) match++;
            }
            right++;
            while(match==needs.size()){
                if(right-left<minLen){
                    minLen=right-left;
                    start=left;
                }
                char c2=s[left];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2]<needs[c2]) match--;
                }
                left++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};
```
