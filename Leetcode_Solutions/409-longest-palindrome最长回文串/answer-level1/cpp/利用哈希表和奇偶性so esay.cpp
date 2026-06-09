哈希表记录每个字母的个数，偶数个肯定可以形成回文，直接加上个数是偶数个的。如果是奇数个则可以有一个中心，剩余的都在两边就行了，只要保证center始终为1.

```
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char,int> m;
        for (char c :s){
            m[c]++;
        }
        int ans = 0;
        int center = 0;
        for (auto item : m){
            if(item.second%2==0){
                 ans +=item.second;
            }
            else{
                 ans+=item.second-1;
                 center = 1;
            }
        }
        return ans+center;


    }
};
```
