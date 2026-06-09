```
class Solution {
public:
    bool isValid(string S) {
        stack<char> abc;
        for(int i = 0; i < S.size(); ++i) {
            
            if(S[i]  == 'b' && (abc.empty() || (!abc.empty() && abc.top() != 'a'))) {
                return false;
            }
            if(S[i]  == 'c' && (abc.empty() || (!abc.empty() && abc.top() != 'b'))) {
                return false;
            }
            abc.push(S[i]);
            if (S[i] == 'c'){
                abc.pop();
                abc.pop();
                abc.pop();
            }
        } 
        return abc.empty();
        
    }
};
```
![image.png](https://pic.leetcode-cn.com/46f6b9961c62128dea8cb7b1b2db9cd665f65aec07c4f50de4db478b46b33533-image.png)
