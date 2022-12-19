### 解题思路
1.两个数组，对应写好每个数字对应的罗马数字，从大到小写。
2.遍历字符串字符，根据对应数组字符压入result字符串中即为正确答案。

### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<int> store = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> strs = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int storeSize = (int)(store.size());
        
        for(int i = 0;i < storeSize;i++){
            while(num >= store[i]){
                result.append(strs[i]);
                num -= store[i];
            }
        }
        return result;
    }
};
```