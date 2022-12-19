![snipaste_2020-03-12_18-14-43.jpg](https://pic.leetcode-cn.com/6df0576954facd9b31ad63536ba1457f0120f377a4b6c66003682c6216ea63b0-snipaste_2020-03-12_18-14-43.jpg)


解题思路为暴力枚举基础上进行优化。

对于两个字符串的最大公因子，其最大长度一定小于原有两个字符串长度的最大公因数，因此可以在这一范围内检查对应长度的子串是否满足条件。具体思路：

1. 计算两个字符串长度的最大公因数maxLen
2. 遍历两个字符串的前maxLen个元素，找到最大的公共头部长度curLen
3. 从curLen开始检查对应长度的字串能否构成两个原有的字符串，如果能构成返回对应长度的字符串，不能则返回空。

其中检查部分使用了自己定义的函数。


```cpp
class Solution {
public:
    int helper(int a, int b){
        if(b > a)
            swap(a, b);
        int tmp = a % b;
        while(tmp){
            a = b;
            b = tmp;
            tmp = a % b;
        }
        return b;
    }

    bool check(string str, int len){
        if(!len || len == str.size())   //长度与字符串本身相同返回true
            return true;
        int loop = str.size() / len;
        for(int i = 1; i < loop; i++){
            int base = i * len;
            for(int j = 0; j < len; j++){
                if(str[j] != str[base++])
                    return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int maxLen = helper(str1.size(), str2.size());
        int len1 = str1.size(), len2 = str2.size();
        int curLen;
        for(curLen = 0; curLen < maxLen; curLen++){
            if(str1[curLen] != str2[curLen])
                break;
        }
        curLen++;
        
        
        //获取最大长度
        while(curLen){
            if(len1%curLen || len2%curLen){
                curLen--;
                continue;
            }
            if(check(str1,curLen) && check(str2, curLen))
                break;
            curLen--;
        }
        return str1.substr(0, curLen);
    }
};
```