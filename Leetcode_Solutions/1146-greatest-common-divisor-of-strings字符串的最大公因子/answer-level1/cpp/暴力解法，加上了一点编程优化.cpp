### 解题思路
* 首先从两个字符串的头部开始，找到两个字符串最大相同部分
    1. 如果第一个字母就不相同直接返回空串
    2. 否则进入下一步判断
* 从最大相同部分开始，依次判断该子串是否为两字符串的公共部分
    1. 首先判断两个字符串的长度是否为该子串的整数倍，不为直接进入下一次循环
    2. 如果为整数倍，从头开始遍历两串，查看是否满足
        1. 如果满足直接返回当前公因串
    3. 否则当前字串从尾部裁去一个字符，重新进入循环，直到公因串长度为0
    4. 如果能到达程序尾部未返回，直接返回空串
### 代码

```cpp
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int currentLength;
        for(currentLength = 0;currentLength < str1.length()&& currentLength < str2.length();
            currentLength++){
                if(str1[currentLength] != str2[currentLength])break;
        }
        //如果不存在相同序列
        if(currentLength == 0)return "";

        //存在则进行遍历进行判断
        for(;currentLength >0;currentLength--){
            if(str1.length()%currentLength != 0 && str2.length()%currentLength != 0)continue;
            if(isDivisor(str1,str2,currentLength))return str1.substr(0,currentLength);
        }
        return "";
    }

    bool isDivisor(string str1, string str2, int currentLength){
        int i;
        for(i = currentLength;i < str1.length() && i < str2.length();i = i+currentLength){
            for(int j = 0;j < currentLength;j++)
                if(str1[i + j] != str1[j] || str2[i + j] != str2[j])return false;
        }
        if(i < str1.length()){
            cout<<"nb";
            for(;i<str1.length();i = i+currentLength){
                for(int j = 0;j < currentLength;j++){
                    if(str1[i + j] != str1[j])
                        return false;
                }
            }
        }
        if(i < str2.length()){
            for(;i<str2.length();i = i+currentLength){
                for(int j = 0;j < currentLength;j++)
                    if(str2[i + j] != str2[j])return false;
            }
        }
        return true;
    }
};
```