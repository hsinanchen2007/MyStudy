新人刚入坑第一天~写个笔记
```
class Solution {
public:
    int romanToInt(string s) {
        //存入罗马字符对应的数字
      unordered_map<char,int> map = {{'I',1},{'V',5},{'X',10},
                    {'L',50},{'C',100},{'D',500},{'M',1000}};
                    int res = 0;//表示该字符串转换的结果
                    int len = s.length();//字符串长度
                    //遍历一遍字符串
                    for (int i = 0 ; i < len ; i++){
                        if(map[s[i]] >= map[s[i+1]] ){
                            //如果左边的字符数值大于等于右边的字符数值
                            //则只需要加入当前字符对应的数值就行 
                            //eg : II = 2 = 1 + 1  ，XI = 11 = 10 + 1
                                res += map[s[i]];
                        }
                        else {
                            //如果左边字符数值小于右边字符数值
                            //则只需要减掉当前字符数值即可
                            //eg : IX = 9 = 0 - 1 + 10 , CD = 400 = 0 - 100 + 500 
                                res -= map[s[i]];
                        }
                    }
                    return res;

    }
};
```
