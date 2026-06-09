### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        if(num<26&&num>9) return 2;
        if(num<10) return 1;
        int temp=num;
        int len_num=0;
        while(temp)
        {
            len_num++;
            temp=temp/10;
        }
        int first2nums=num/pow(10,len_num-2);
        int subnum1=num%(int)pow(10,len_num-1);
        int subnum2=num%(int)pow(10,len_num-2);
        if(first2nums<26)
        {
            return translateNum(subnum1)+translateNum(subnum2);
        }
        else
        {
            return translateNum(subnum1);
        }
    }
};
```