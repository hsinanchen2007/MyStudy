### 解题思路
在一个while循环里面将int转换成倒序和正序的str。
然后再比较。

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        string src ="";
        string des = "";
        if(x<0) return false;
        while(x!=0){
            src.push_back('0'+x%10);
            string tmp="";
            tmp.push_back('0'+x%10);
            tmp.append(des);
            des = tmp;
            x/=10;
        }
   
        return des==src;
    }
};
```