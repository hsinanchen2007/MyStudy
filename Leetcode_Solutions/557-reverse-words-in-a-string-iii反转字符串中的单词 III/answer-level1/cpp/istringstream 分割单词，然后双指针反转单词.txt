```
class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string res,temp;
        while(iss>>temp){
            for(int i=0,j=temp.size()-1;i<j;i++,j--) swap(temp[i],temp[j]);
            if(res.size()) res.append(" ");
            res.append(temp);
        }
        return res;
    }
};
```
