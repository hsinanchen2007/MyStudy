### 解题思路
如果只有一个字母，那一定为真。
超过一个字母时，从第二个字母开始比较，当第二个字母及后面的字母大小写不同时返回false，采用将第二个字母的判大写情况与其他字母判大写情况做异或，结果为1时即为情况不同。
注意isupper返回为int型，需要强制类型转换。
单独判断第一个字母，当第一个字母为小写且第二个字母为大写时为false
其余情况为true

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2) return true;
        bool first=isupper(word[0]);
        bool upper=isupper(word[1]);
        if(first==false&&upper==true) return false;
       for(int i=1;i<word.size();++i){
           if((bool)isupper(word[i])^upper) return false;
       }
    return true;
    }
};
```