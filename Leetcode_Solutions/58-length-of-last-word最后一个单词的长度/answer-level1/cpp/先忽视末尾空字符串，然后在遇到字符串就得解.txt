````
class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size(),flag=0;
        int sum = 0;
        for(int i = size-1;i>=0;i--){
            if(s[i]!=' '){
                sum++;
                flag=1;
            }
            if(flag==1 && s[i]==' '){
                return sum;
            }           
        }
        return sum;
    }
};
```
