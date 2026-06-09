c++ 双指针。
is_double函数判断是否重复。
```
class Solution {
private:
    bool is_double(string s,char c){
        for(int i=0;i<s.size();i++){
            if(c==s[i]) return true;
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0) return 0;
        int head,tail;
        head=tail=0;
        int res = 1;
        while(tail!=n-1){
            tail++;
            if(is_double(s.substr(head,tail-head),s[tail])){
                while(is_double(s.substr(head,tail-head),s[tail])&&tail>=head){
                    head++;
                }
            }
            res = max(tail-head+1,res);
        }
        return res;
    }
};
```
