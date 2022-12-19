```c++ []
class Solution {
public:
    char minIdx(unordered_map<char,int> & hashmap){
        char ans;
        int idx = INT_MAX;
        
        for(auto &it : hashmap){
            if(it.second < idx){
                ans = it.first;
                idx = it.second;
            }
        }
        
        return ans;
    }
    
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char,int> hashmap;
        int left = 0;
        int right = 0;
        int ans = 0;
        
        if(s.size() < k+1){
            return s.size();
        }
        
        while(right < s.size()){
            if(hashmap.size() < k+1){
                char c = s[right];
                hashmap[c] = right++;
            }

            if(hashmap.size() == k+1){
                char del_key = minIdx(hashmap);
                left = hashmap[del_key]+1;
                hashmap.erase(del_key);
            }
            ans = max(ans,right-left);
        }
            
        return ans;
    }
};
```
```python []

```
```java []

```
