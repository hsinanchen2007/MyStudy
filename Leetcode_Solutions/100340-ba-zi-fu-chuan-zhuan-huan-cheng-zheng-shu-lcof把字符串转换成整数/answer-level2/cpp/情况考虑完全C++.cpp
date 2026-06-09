### 解题思路
标志位:
1. flag:是否遇到过负号
2. first:是否遇到过非空格字符，包括数字，正负号

基本操作: 
1. 十进制加法：
long long nums (数字范围比int大会便于判断)
nums = nums*10 + str[i] - '0'
2. 判断范围：
if(nums >= INT_MAX && !flag) return INT_MAX;
if(nums > INT_MAX && flag) return INT_MIN;
 

情况：
1. 一旦遇到无关字符，直接break
2. 遇到+-号，设置flag, 并且令first = true
3. 遇到数字，进行基本操作，第一次遇到数字，就令first = true
4. 遇到空格，如果first=false，那么说明前面是连续空格，直接continue，否则此空格就是无关字符，直接break
5. 到结尾的时候，如果flag为true，返回相反数，否则直接返回。
总结：
不要小看这题，腾讯一面有考过，当时觉得特别简单，结果交了一个啥特殊情况都没考虑过的答案，
凉地欲哭无泪
### 代码

```cpp
class Solution {
public:
    int strToInt(string s) {
        int len = s.length();
        long long res = 0; 
        bool flag = false, first = false; 
        for(int i = 0;i<len;i++){ 
            if(s[i] == ' '&&!first) continue;
            if((s[i] < '0' || s[i] > '9')) {
                if(first) break; 
                if(s[i] != '-' && s[i] !='+') break;
                if(s[i] == '-') flag =true;
                first= true;
                continue;
            }
            first = true;
            res = res*10 + s[i] - '0';
            if(res >= INT_MAX && !flag) return INT_MAX; 
            if(res > INT_MAX && flag) return INT_MIN; 
        }
        if(flag) return -res;	
        return res;
    }
};
```