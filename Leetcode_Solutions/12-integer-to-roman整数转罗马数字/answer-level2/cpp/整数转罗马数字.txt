```
class Solution {
public:
    string intToRoman(int num) {
        vector<string> mp={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> vec={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string res="";
        for(int i=vec.size()-1;i>=0;i--){
            while(num >= vec[i]){
                res += mp[i];
                num -= vec[i];
            }
        }
        return res;
    }
};
```
