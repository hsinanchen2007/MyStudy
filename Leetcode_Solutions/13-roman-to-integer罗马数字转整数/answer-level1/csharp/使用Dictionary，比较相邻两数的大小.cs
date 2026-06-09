```
public class Solution {
    public int RomanToInt(string s) {
        Dictionary<char,int> dic = new Dictionary<char,int>(){
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int total = 0;
        //如果只有一个字符
        if(s.Length == 1){
            return dic[s[0]];
        }
        for(int i = 0; i < s.Length - 1; i++){
            if(dic[s[i]] < dic[s[i+1]]){
                total += dic[s[i+1]] - dic[s[i]];
                i++;
            }else{
                total += dic[s[i]];
            }
            //判断最后一个数
           if(i+1 == s.Length - 1){
                total += dic[s[i+1]];
            }
        }
        return total;
    }
}
```