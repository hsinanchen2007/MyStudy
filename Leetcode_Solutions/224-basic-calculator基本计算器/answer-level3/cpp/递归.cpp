随表写了一个，主要是遇到左括号进行递归。
```
class Solution {
public:
    string skipSpae(string s){
        string ans;
        
        for(auto c : s){
            if(c != ' '){
                ans.push_back(c);
            }
        }
        return ans;
    }
    
    int helper(string & s,int l,int r){
        long long num = 0;
        long long ans = 0;
        char ops = ' ';
        int idx = l;
                        
        while(idx <= r){
           if(idx <= r && s[idx] == '+' || s[idx] == '-'){
               ops = s[idx];
               ++idx;
           }
            
           num = 0;
           if(idx <= r && s[idx] >= '0' && s[idx] <= '9'){
               while(idx <= r && s[idx] >= '0' && s[idx] <= '9'){
                   num = num*10 + s[idx] - '0';
                   ++idx;
               }
           }else if(idx <= r && s[idx] == '('){
               int count = 1;
               int next = 0;
               for(int i = idx+1;i <= r; ++i){
                   if(s[i] == '('){
                       count++;
                   }else if(s[i] == ')'){
                       count--;
                   }
                   if(count == 0){
                       next = i;
                       break;
                   }
               }
               num = helper(s,idx+1,next-1);
               idx = next + 1;
           }
            
           /*calculate*/
           if(ops == ' '){
               ans = num;
           }else if(ops == '+'){
               ans += num;
           }else if(ops == '-'){
               ans -= num;
           }
        }
        return ans;
    }
    
    int calculate(string s) {
        /*skip space*/
        s = skipSpae(s);
        int n = s.size();
        return helper(s,0,n-1);
    }
};
```