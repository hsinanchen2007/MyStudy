### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long int y=0;
        int temp; //保存转换前的值
        temp=x;
        if (x<10&&x>=0)
        {
            return true;
        }
        if(x<0 || x%10==0)
        {
            return false;
        }
        while(x>=1)
        {
            y=y*10+x%10;
            x=x/10;
        }
        if(y==temp)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
```