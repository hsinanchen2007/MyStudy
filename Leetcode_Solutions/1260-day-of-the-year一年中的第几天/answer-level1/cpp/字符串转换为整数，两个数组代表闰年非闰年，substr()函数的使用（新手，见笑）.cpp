### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dayOfYear(string date) {
        string year1=date.substr(0,4);
        //这里使用了两个数组避免了，分情况讨论奇偶月（7.8月都为31天，闰年2月为29天）
        vector<int>nums1={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>nums2={31,29,31,30,31,30,31,31,30,31,30,31};
        bool intyear=true;
        int year;
        stringstream  ss;
        ss<<year1;
        ss>>year; //通过流将字符串转换为整数
        int  mooth,day;
        int ans=0;
        if((year%400==0)||(year%100!=0&&year%4==0))  intyear=true;//闰年含义：1.能被400整除   2.不能被100整除但能被4整除的为闰年
        else intyear=false;  
        mooth=10*(date[5]-'0')+date[6]-'0';//字符串转化为整数：如果字符串为"0001",当转换为整数时开头的0没关系的，int res;  res=res*10+s[i]-'0';  字符串的开头为0不影响转换为整数的值。
        day=10*(date[8]-'0')+date[9]-'0';
        for(int i=0;i<mooth-1;i++){
            if(intyear==true)ans+=nums2[i];
            else ans+=nums1[i];
        }
        return ans+day;
    }
};
```