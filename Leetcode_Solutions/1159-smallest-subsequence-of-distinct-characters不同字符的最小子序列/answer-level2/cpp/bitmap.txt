```
class Solution {
public:
    bool bitSet(int & mask,int bit){
        if(bit < 0|| bit >= 32){return false;}
        mask |= 1<<bit;
        return true;
    }
    
    bool bitTest(int mask,int bit){
        if(mask&(1<<bit)){
            return true;
        }else{
            return false;
        }
    }
    
    bool check(int v1,int v2,int mask){
        return (v1|v2) == mask;
    }
    
    string smallestSubsequence(string text) {
        int mask = 0;
        int n = text.size();
        vector<int> back(n+1,0);
        string ans;
        
        /*count*/
        for(auto c : text){
            bitSet(mask,c-'a');
        }
        for(int i = n-1;i >= 0; --i){
            back[i] = back[i+1];
            bitSet(back[i],text[i] - 'a');
        }
        
        /*check*/
        int idx = 0;
        int curr = 0;
        int last = 0;
        while(idx < n){
            while(last < n && bitTest(curr,text[last]-'a')){
                ++last;
            }
            idx = last;
            while(idx < n && check(curr,back[idx],mask)){
                if(text[idx] < text[last] && !bitTest(curr,text[idx]-'a')){
                    last = idx;
                }
                ++idx;
            }
            bitSet(curr,text[last]-'a');
            ans.push_back(text[last]);
            if(curr == mask){
                break;
            }
        }
        
        return ans;
    }
};
```