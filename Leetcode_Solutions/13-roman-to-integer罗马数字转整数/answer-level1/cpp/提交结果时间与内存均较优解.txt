### 解题思路
此处撰写解题思路
从string的右边往左累加，只有两种情况，当下的字符对应值比右边大或等于，当下的字符对应值比右边小；
用tmp来记录当下右边的字符对应值所在的的表中位置，大于等于时直接加并更新此时查表对应的下标入tmp，小于
时减去即可，不用更新tmp值。
### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        char tab[]={'M','D','C','L','X','V','I'};
        int num[]={1000,500,100,50,10,5,1};
        int size=s.length();
        int res=0;
        int tmp=6;
        for(int i=size-1;i>=0;i--)
        {
            int j=0;
            while(s[i]!=tab[j]) 
            {j++;}               
            if(j<=tmp)
            {
             res+=num[j];
             tmp=j;
            }
            else{ res-=num[j];}
        }
        return res;
    }
};
```