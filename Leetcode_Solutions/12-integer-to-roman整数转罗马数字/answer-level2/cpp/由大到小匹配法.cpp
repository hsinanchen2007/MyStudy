```C++ []
class Solution {
public:
    string intToRoman(int num) {
        string result;
        int n[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string m[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        for(int i=sizeof(n)/sizeof(n[0])-1;i>=0;--i){
            if(num>=n[i]){    
                for(int j=num/n[i];j>0;--j)
                    result+=m[i];
                num%=n[i];
            }
        }
        return result;
    }
};
```