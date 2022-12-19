```
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string before = countAndSay(n-1);
        string tmp = "";
        char tmp_char = before[0];
        int char_cout = 0;
        for(int i=0; i<before.size(); i++){
            if(before[i] == tmp_char){
                char_cout++;
            }else{
                tmp += std::to_string(char_cout);
                tmp += tmp_char;
                tmp_char = before[i];
                char_cout = 1;
            }
        }
        tmp += std::to_string(char_cout);
        tmp += tmp_char;
        return tmp;
    }
};
```
