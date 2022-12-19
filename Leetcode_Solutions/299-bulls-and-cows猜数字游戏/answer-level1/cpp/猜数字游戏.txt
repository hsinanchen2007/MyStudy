```
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>map;
        int a=0,b=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
                a++;
            map[secret[i]]++;
            map[guess[i]]--;
        }
        for(int j=0;j<10;j++)
        {    
            if(map[char(j+'0')]>0)
                b+=map[char(j+'0')];//此时b为不相同的数字个数
        }
        b=secret.size()-b-a;//总个数减去不相同的个数=A个数+B个数
        return to_string(a)+"A"+to_string(b)+"B";
    }
};
```
