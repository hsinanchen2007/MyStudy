```
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream iss(text);
        string temp;
        int flag = 0 ;
        vector<string> vec;
        while(iss>>temp){
            if(flag==2)vec.emplace_back(temp);
            if(temp==first){
                flag=1;
            }
            else if(flag==1&&second==temp){
                flag=2;
            }
            else flag=0;
        }
        return vec;
    }
};
```