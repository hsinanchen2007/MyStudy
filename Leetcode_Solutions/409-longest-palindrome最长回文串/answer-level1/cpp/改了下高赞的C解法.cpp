### 解题思路
数组的索引用ASCII码（类似hash）
开始把所有偶数个的存进去 奇数个的按偶数个存
最后判断sum和原长度大小

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int  length=s.length();
        int dict[58]={0};
        int sum=0;
        for(int i=0;i<length;++i)
        {
            dict[s[i]-65]++;
        }
        for(int i=0;i<=25;++i)
        {
            if(dict[i]%2==0)
            {
                sum+=dict[i];
            }
            else
            {
       
                sum+=dict[i]-1;
            }
        }
        for(int i=32;i<=57;++i)
        {
            if(dict[i]%2==0)
            {
                sum+=dict[i];
            }
            else
            {
   
                sum+=dict[i]-1;
            }

        }
        if(sum<length)
        {
            ++sum;
        }
       
        
        return sum;

    }
};
```