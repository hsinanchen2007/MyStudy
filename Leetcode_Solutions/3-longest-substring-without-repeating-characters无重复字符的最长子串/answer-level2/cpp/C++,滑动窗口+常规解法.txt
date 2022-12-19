#### 基本原理就是从前向后遍历一遍，如果出现当前的字符与之前的字符相同。那么移动前一个指针到相同字符位置的后面一个位置。。。
```
常规解法：
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int res=0;
        int left=0;
        if(n==1)return 1;
        for(int i=0;i<n;i++){
            if(i>0){
                for(int j=left;j<i;j++){
                    if(s[i]==s[j]){
                        left=j;
                        left++;
                    }
                }
            }
            res=max(res,i-left+1);
        }
        return res;
    }
};
```
### 解法二：滑动窗口
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int left=0;
        int n=s.length();
        unordered_set<char>ans;
        for(int i=0;i<n;i++){
            while(ans.find(s[i])!=ans.end()){
                ans.erase(s[left]);
                left++;
            }
            res=max(res,i-left+1);
            ans.insert(s[i]);
        }
        return res;
    }
};
```