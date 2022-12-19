```
class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string roms[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res = "";
        for(int i=12; i>=0; i--){
            while(num>=values[i]){
                num-=values[i];
                res+=roms[i];
            }
        }
        return res;
    }   
};
```
