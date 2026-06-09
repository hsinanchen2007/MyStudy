### 解题思路
1.先排除Vector为空的情况，若Vector中的只有一个字符串则直接返回该字符串，若字符串为空则直接返回空字符串。
2.str_temp赋值为第一个字符串，使用find函数在Vector中所有的字符串查找是否存在str_temp子串，若存在则会返回该字符串起始下标即0，(查找的为最长公共前缀，所以找的子串下表一定为0)
3.while循环中表示未寻找到字串操作，若未找到子串str_temp，则不断截短子串str_temp，舍去str_temp尾字符。
4.当在Vector中的所有字符串中都找到了子串str_temp,则直接返回str_temp;

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str_temp;
        
        if(strs.empty()){
            str_temp = "";
            return str_temp;
        }
        str_temp = strs[0];
        if(str_temp == ""){
            str_temp = "";
            return str_temp;
        }
        if(strs.size() == 1){
            return str_temp;
        }
        
        str_temp = strs[0];
        for(int i = 1;i < strs.size();i++){
            while(strs[i].find(str_temp) != 0){
                str_temp = str_temp.substr(0,str_temp.length() - 1);
            }
        }
        return str_temp;
    }
};
```