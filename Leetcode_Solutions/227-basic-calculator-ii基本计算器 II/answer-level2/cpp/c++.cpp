```
class Solution {
public:
    int calculate(string s) {
        int num=0;
        char sign='+';
        vector<int> nums;
        for(int i=0;i<s.size();++i){
            char c=s[i];
            bool isDigit=(c>='0'&&c<='9');
            if(isDigit){
                num=num*10+(c-'0');
            }
            if((!isDigit&&s[i]!=' ')||i==s.size()-1){
                switch(sign){
                    case '+':
                        nums.push_back(num);
                        break;
                    case '-':
                        nums.push_back(-num);
                        break;
                    case '*':
                        nums[nums.size()-1]*=num;
                        break;
                    case '/':
                        nums[nums.size()-1]/=num;
                        break;
                }
                num=0;
                sign=c;
            }
        }
        int res=0;
        for(auto num:nums)res+=num;
        return res;
    }
};
```
