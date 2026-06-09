### 解题思路
此处撰写解题思路
如果x是负数直接返回false,大于0则利用取余和整除算出它的回文数。要注意a值可能的范围大小确定它的类型。
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        long a=0;
        int b=x;
        if(b<0) return false;
        while(b>0){
            a=a*10+b%10;
            b=b/10;
        }
        if(a==x){
            return true;
        }else
        {
            return false;
        }
        
    }
};
```