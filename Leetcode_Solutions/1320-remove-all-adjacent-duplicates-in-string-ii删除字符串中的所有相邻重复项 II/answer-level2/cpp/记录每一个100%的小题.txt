简单粗暴
执行用时708 ms,击败了9.42%
内存消耗9.9 MB,击败了100.00%
```
class Solution {
public:
    string removeDuplicates(string s, int k) {
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]!=s[i+1]) continue;

            int j = i+1;
            while(s[i]==s[j] && j<s.size() && j<i+k)
                j++;
            if((j - i) < k) continue;
            s.erase(s.begin()+i, s.begin()+j);
            i = i >= k ? i-k : -1;
        }
        return s; 
    }
};
```
