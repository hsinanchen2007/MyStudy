### 解题思路
一开始想复杂了，后来看了讨论 才明白，首先可以根据这俩字符串的长度，计算出一个最大公约数，最为最终答案的长度，当然有可能出现，abcd ab 这种情况。所以 一开始先利用str1 + str2和str2 + str1 这两个进行比较来判断是否相同。
### 代码

```cpp
class Solution {
public:

    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()){
            swap(str1, str2);
        }
        int lenstr1 = str1.size();
        int lenstr2 = str2.size();
        int k = min(lenstr1, lenstr2);
        while(k > 1){
            if(lenstr1 % k == 0 && lenstr2 % k == 0){
                break;
            } else {
                k--;
            }
        }
        if(lenstr1 == 0 || lenstr2 == 0){
            k = max(lenstr1, lenstr2);
        }
        if(str1 + str2 != str2 + str1){
            k = 0;
        }
        string ans(str1.begin(),str1.begin() + k);
        return ans;
    }
};
```