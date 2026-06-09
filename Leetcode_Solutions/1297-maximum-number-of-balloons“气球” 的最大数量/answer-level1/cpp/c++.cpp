1. 题目本身很简单，主要是求字符串中字符'b','a','l','o','n'的次数.
```c++ []
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(26,0);
        int ans = INT_MAX;
        
        for(auto c : text){
            cnt[c-'a']++;
        }
        cnt['l'-'a'] = cnt['l'-'a']/2;
        cnt['o'-'a'] = cnt['o'-'a']/2;
        ans = min(ans,cnt['b'-'a']);
        ans = min(ans,cnt['a'-'a']);
        ans = min(ans,cnt['l'-'a']);
        ans = min(ans,cnt['o'-'a']);
        ans = min(ans,cnt['n'-'a']);
        
        return ans;
    }
};
```
```java []
class Solution {
    public int maxNumberOfBalloons(String text) {
        int[] cnt = new int[26];
        int ans = 10001;
        
        /*initial*/
        for(int i = 0; i < 26; ++i){
            cnt[i] = 0;
        }
        for(int i = 0;i < text.length(); ++i){
            cnt[text.charAt(i)-'a']++;
        }
        
        ans = Math.min(ans,cnt['b'-'a']);
        ans = Math.min(ans,cnt['a'-'a']);
        ans = Math.min(ans,cnt['l'-'a']/2);
        ans = Math.min(ans,cnt['o'-'a']/2);
        ans = Math.min(ans,cnt['n'-'a']);
        
        return ans;
    }
}
```
```python []
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        cnt = [0 for _ in range(26)]
        ans = len(text)
        
        for i in range(len(text)):
            cnt[ord(text[i])-ord('a')] += 1
        
        ans = min(ans,cnt[ord('a')-ord('a')])
        ans = min(ans,cnt[ord('b')-ord('a')])
        ans = min(ans,int(cnt[ord('l')-ord('a')]/2))
        ans = min(ans,int(cnt[ord('o')-ord('a')]/2))
        ans = min(ans,cnt[ord('n')-ord('a')])
        
        return ans
```