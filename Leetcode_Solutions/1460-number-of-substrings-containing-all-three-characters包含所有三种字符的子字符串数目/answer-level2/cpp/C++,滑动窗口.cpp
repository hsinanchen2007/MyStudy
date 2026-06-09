```
//本题采用的是滑动窗口算法，个人觉得这种思想需要掌握：
//基本思想就是：如果当前的窗口包含abc，那么这个窗口之后一定是包含abc的
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int mp[3]={0,0,0};
        int left=0;//定义一个left为左边的位置，下一次需要将这个位置向后移动一格
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
            while(mp[0]&&mp[1]&&mp[2]){
                ans+=(s.length()-i);
                mp[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};
```
