```
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int J_length = J.length(), S_length = S.length();
        int num = 0;
        for (int i=0; i<J_length; i++){
            for (int j=0; j<S_length; j++){
                if (S[j] == J[i]) 
                    num++;                
            }
        }
        return num;
    }
};
```
