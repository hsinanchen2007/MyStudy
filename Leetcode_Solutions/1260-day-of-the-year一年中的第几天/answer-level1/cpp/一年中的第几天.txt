### 解题思路
原来1900不是闰年，整百年要400年一闰，长知识了。
### 代码

```cpp
class Solution {
public:
    int dayOfYear(string date) {
        int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        int year=(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        int month=(date[5]-'0')*10+(date[6]-'0');
        if(year!=900 && year%4==0) day[1]++;
        int re=0;
        for(int i=0;i<month-1;i++)
        {
            re+=day[i];
        }
        return re+(date[8]-'0')*10+(date[9]-'0');

    }
};
```