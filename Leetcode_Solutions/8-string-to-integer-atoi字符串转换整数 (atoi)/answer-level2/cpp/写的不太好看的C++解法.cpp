```
class Solution {
public:
    int myAtoi(string str) {
        if (str.size() <= 0)    return 0;

        int index = 0;
        while(str[index] == ' ') index++;

        int flag = 1;
        if (str[index] == '-')  {
            flag = -1;
            index++;
        }else if (str[index] == '+'){
            flag = 1;
            index++;
        }
        
        int ans = 0;
        while(isdigit(str[index])){
            if (flag == -1)  {
                if (ans > INT_MAX/10 || (ans == INT_MAX/10 && (str[index]-'0') >= 8))  
                    return INT_MIN; 
            }else{
                if (ans > INT_MAX/10 || (ans == INT_MAX/10 && (str[index]-'0') >= 7))   
                    return INT_MAX;
            }
            ans = (str[index]-'0')+ans*10;
            index++;
        }

        if (flag == -1)   ans = -ans;

        return ans;
```
