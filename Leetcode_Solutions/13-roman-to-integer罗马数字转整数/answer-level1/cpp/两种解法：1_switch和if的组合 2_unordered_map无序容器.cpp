
# 1， switch和if的组合
在解题的过程中，需要注意一下几个坑：
    1，switch和if的先后问题，因为i在两者中均有使用，由于在if中涉及到i幅值运算，所以应该将switch放于前边；
    2，在if判断中，i幅值过程是自增1还是2的问题；
    3，刚开始我尝试将六个特殊情况分别从string中删除然后在string的最后增加正常的顺序的罗马数字，但是后来由于设计的length of string的改变和i的边界范围的改变，情况会变得复杂，所以我放弃了这种想法。
```
class Solution {
public:
    int romanToInt(string s) {
        int s_length = s.length();
        int sum = 0;
        for(int i=0; i<s_length; i++){
            switch (s[i])
            {
            case 'I':
                sum += 1; 
                break;
            case 'V':
                sum += 5; 
                break;
            case 'X':
                sum += 10; 
                break;
            case 'L':
                sum += 50; 
                break;
            case 'C':
                sum += 100; 
                break;
            case 'D':
                sum += 500; 
                break;
            case 'M':
                sum += 1000; 
                break;
            default:
                break;
            }
            if (s[i] == 'I' && s[i+1]=='V')//IV
                i++, sum+=4-1;
            if (s[i] == 'I' && s[i+1]=='X')//IX
                i++, sum+=9-1;
            if (s[i] == 'X' && s[i+1]=='L')//XL
                i++, sum+=40-10;
            if (s[i] == 'X' && s[i+1]=='C')//XC
                i++, sum+=90-10;
            if (s[i] == 'C' && s[i+1]=='D')//CD
                i++, sum+=400-100;
            if (s[i] == 'C' && s[i+1]=='M')//CM
                i++, sum+=900-100;
        }
        return sum;
    }
};
```

# 2, unordered_map无序容器
```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> map =    { {"I", 1}, {"V",5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
                                            {"IV", -2}, {"IX", -2}, {"XL", -20}, {"XC", -20}, {"CD", -200}, {"CM", -200} };
        int num = 0;
        for (int i=0; i<s.size(); i++){
            num += map[s.substr(i,1)];
            if (map[s.substr(i,2)] && i!=s.size()-1)
                num += map[s.substr(i,2)];
        }
        return num;
    }
};
```
# 总结
两种方法中第一种方法时间复杂度更低，占用内存更低；第二种方法更简便，容易理解，代码量更少。