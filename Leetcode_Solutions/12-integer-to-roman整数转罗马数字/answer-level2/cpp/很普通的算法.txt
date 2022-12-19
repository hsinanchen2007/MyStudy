![1582627427(1).png](https://pic.leetcode-cn.com/c3763b624de7a696ddc1e357006e40aabca5cd2d9f60d1bcaa6bba3d442f2028-1582627427\(1\).png)
```
class Solution {
public:
    string intToRoman(int num) {
        
        int all = num;
        int n = 0;
        string ans;
        while(all!=0)
        {
            if(n == 0)
            {
                int m = all%10;
                all = all - m;
                if(m == 9)
                {
                    ans = "IX"+ans;n++;continue;
                }
                if(m == 4)
                {
                    ans = "IV"+ans;n++;continue;
                }
                if(m >= 5)
                {
                    while(m!=5){ans = "I"+ans;m--;}
                    ans = "V"+ans;n++;
                }
                else
                {
                    while(m!=0){ans = "I"+ans;m--;}
                    n++;
                }
            }
            if(n== 1)
            {
                int m = all%100;
                all = all - m;
                if(m == 90)
                {
                    ans = "XC"+ans;n++;continue;
                }
                if(m == 40)
                {
                    ans = "XL"+ans;n++;continue;
                }
                if(m >= 50)
                {
                    while(m!=50){ans = "X"+ans;m-=10;}
                    ans = "L"+ans;n++;
                }
                else
                {
                    while(m!=0){ans = "X"+ans;m-=10;}
                    n++;
                }

            }
            if(n== 2)
            {
                int m = all%1000;
                all = all - m;
                if(m == 900)
                {
                    ans = "CM"+ans;n++;continue;
                }
                if(m == 400)
                {
                    ans = "CD"+ans;n++;continue;
                }
                if(m >= 500)
                {
                    while(m!=500){ans = "C"+ans;m-=100;}
                    ans = "D"+ans;n++;
                }
                else
                {
                    while(m!=0){ans = "C"+ans;m-=100;}
                    n++;
                }

            }
            if(n>=3)
            {
                while(all!=0)
                {
                    ans = "M"+ans;
                    all -= 1000;
                }
            }

        }
        return ans;


    }
};
```
