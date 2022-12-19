### 解题思路
这题比较简单，首先知道负数不是回文数 0是回文数。

然后反转数字，用数组存储，依次判断num[j]!=num[length-j]
然后分情况返回结果

**这题也可以用字符串来处理，以后来补充。**

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)    return 0;
        if(x==0)   return 1;
        int num[32];
        int i=1;
        while(x>0)
        {
            num[i]=x%10;
            x/=10;
            i++;
        }
        int length=i--;
        int j=1;
        for(;j<=length/2;j++)
        {
            if(num[j]!=num[length-j])
            return 0;
        } 
        return 1;
    }
};
```