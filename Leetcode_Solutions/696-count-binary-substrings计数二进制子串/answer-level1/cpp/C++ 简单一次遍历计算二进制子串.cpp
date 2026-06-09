```
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=0,zero=0,one=0;
        if(s[0]=='0') zero++;
        else one++;
        for(int i=1;i<s.size();++i){
            if(s[i]=='0'){
                if(s[i-1]=='1'){//每当遇到前一位与目前位不一致时，计算前一位的子串数目
                    //计算方法：前面有zero个连续0和one个连续1相连，取小值即为子串数目
                    n+=min(zero,one);
                    zero=1;//计算完成后就将0的数目zero设为1，开始下一回合
                }else zero++;
            }else{
                if(s[i-1]=='0'){
                    n+=min(zero,one);
                    one=1;
                }else one++;
            }
        }
        n+=min(zero,one);
        return n;        
    }
};
```
每当遇到前一位与目前位不一致时，计算前一位的子串数目
计算方法：前面有zero个连续0和one个连续1相连，取小值即为子串数目
计算完成后就将0的数目zero设为1，开始下一回合