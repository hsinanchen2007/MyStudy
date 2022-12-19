### 解题思路
此处撰写解题思路
1.找到最大公约数
2.判断每个字符串是否以最大公约数重复
3.判断两个字符串头部是否互相重复

### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1= str2.length();
        int len2 = str1.length();
        while(len1%len2!=0){
            int temp = len2;
            len2 = len1%len2;
            len1 = temp;
        }
        for(int i=len2;i<str1.length();i++){
            if(str1[i]!=str1[i%len2]){
                return "";
            }
        }
        for(int i=len2;i<str2.length();i++){
            if(str2[i]!=str2[i%len2]){
                return "";
            }
        }
        for(int i=0;i<len2;i++){
            if(str1[i]!=str2[i]){
                return "";
            }
        }
        return str1.substr(0,len2);
    }
};
```