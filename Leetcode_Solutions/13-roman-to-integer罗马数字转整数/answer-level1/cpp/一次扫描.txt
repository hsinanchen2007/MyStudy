### 解题思路


### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int num[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int cnt=1,i=0,j=0,l=s.length(),res=0;
        string str;
        while(i<l)
        {
            if(s.substr(i,cnt)==roman[j])
            {
                if(cnt==1)
                    i++;
                else 
                    i+=2;
                res+=num[j];
            }
            else
            {
                j++;
                if(cnt==2||l-i==1)
                    cnt=1;
                else
                    cnt=2;
            }
        }
    return res;


    }
};
```