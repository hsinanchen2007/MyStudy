### 解题思路
依据题意，输出中的字母个数是奇数个且没有规定字母种类，所以我们可以输出任意字母
则n为偶数时，将n分为n-1,1二者显然都是奇数
输出n-1个a，1个b
当n为奇数时
直接输出n个a即可

### 代码

```cpp
class Solution {
public:
    string generateTheString(int n) {
        string s;
        if(n%2==0)
        {
            for(int i=0;i<n-1;i++)
            {
                s+='a';
            }
            for(int i=0;i<1;i++)
            {
                s+='b';
            }
        }
        else
        {
            for(int i=0;i<=n-1;i++)
            {
                s+='a';
            }
        }
        return s;
    }
};
```