```
class Solution {
public:
    string intToRoman(int num) {
        int nums[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string romans[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0; i<sizeof(nums)/sizeof(int); ++i)
            for(int r=num/nums[i]; r--; num-=nums[i])
                res.append(romans[i]);
        return res;
    }
};
```
