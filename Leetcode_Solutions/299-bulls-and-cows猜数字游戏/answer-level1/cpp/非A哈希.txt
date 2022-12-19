两次循环：
第一次循环求出位置数字都猜对的数量，同时针对谜底，对没全猜对的位置上的数字哈希，并记录位置。
第二次循环只在没全猜对的位置上寻找猜对的数字。避免了混淆

```
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int b = 0;
        vector<int> diff;
        unordered_map<char,int> m;
        
        for(int i =0; i<secret.size(); i++){
            if(secret[i]==guess[i]){
                a++;
            }
            else{
                m[secret[i]]++;
                diff.push_back(i);
            }
        }

        for(auto d:diff){
            if((m.count(guess[d]))&&(m[guess[d]]>0)){
                b++;
                m[guess[d]]--;
            }
        }

        return to_string(a)+"A"+to_string(b)+"B";
    }
};
```

