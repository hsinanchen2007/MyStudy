```
class Solution {
public:
    string reverseWords(string s) {
      
        int n=0;
        string result;
        bool flag=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                n++;
                flag=true;
                if(i==0){
                    result+=s.substr(0,n);
                }
            }else if(s[i]==' '&&flag==true){
                    result+=s.substr(i+1,n);
                    result+=" ";
                    n=0;
                    flag=false;
            }

        }
        if(result[result.size()-1]==' ')
            return result.substr(0,result.size()-1);
        return result;
    }
};
```
