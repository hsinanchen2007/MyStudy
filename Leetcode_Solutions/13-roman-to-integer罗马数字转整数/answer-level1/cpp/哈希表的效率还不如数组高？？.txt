执行用时 :24 ms, 在所有 C++ 提交中击败了72.39%的用户
内存消耗 :10.5 MB, 在所有 C++ 提交中击败了80.53%的用户


排名第一的用的是两个数组...

```
class Solution {
public:
    int romanToInt(string s) {
        
        //定义map建立基本的字符和值的对应关系
        map<char, int> val = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int sum = val[s[0]];
        
        for(int i=1; i<s.length(); i++){
            
            int temp = 0;
            
            //如果当前指向的字符比前一位字符对应的数字要大，则要对二者作差
            if(val[s[i]] > val[s[i-1]]){
                
                temp = val[s[i]] - 2 * val[s[i-1]];
            }
            //如果当前指向的字符比前一位字符所对应的数字要小，则将当前字符对应的数加入sum
            else if(val[s[i]] <= val[s[i-1]]){
                
                temp = val[s[i]];
            }
            
            sum += temp;
   
        }
        
        
        return sum;
        
        
    }
};
```
