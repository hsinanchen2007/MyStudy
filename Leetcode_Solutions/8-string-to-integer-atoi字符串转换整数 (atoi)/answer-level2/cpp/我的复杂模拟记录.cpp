本科时候喜欢做的题目类型。

首先分清楚大致的处理思路，写清楚函数。 接着进行特殊情况考虑，越界。

大致思路是找到合理字符串的左右边界， 接着另一个函数根据这个边界算出最后返回什么数。

偷懒采用long long 算当前的值，并用之来比较是否爆炸INT。

前缀0处理。

爆longlong处理。

写的还是比较麻烦吧。 

```
class Solution {
public:
    int getans(string& str,bool is_negtive,int l,int r){
        long long ans = 0;
        long long  base = 1;
        //cout<<str.substr(l,r-l+1)<<endl;
        while(l<r && str[l] == '0') l++; // 去除前缀0.
        if(r - l +1 > 10){
            return is_negtive? INT_MIN:INT_MAX;
        }
        for(int i=r;i>=l;i--){
            ans += (str[i] - '0')*base;
            base *=10;
            if(is_negtive && ans > -(long long )INT_MIN) return INT_MIN;
            if(!is_negtive && ans > (long long )INT_MAX) return INT_MAX;
        }
        return is_negtive? -ans:ans;
    }
    int myAtoi(string str) {
        int len = str.length();
        int l = -1,r = -1;
        bool is_negtive = false;
        for(int i=0;i<len;i++){
            if(l == -1){
                 if(str[i] == '-'){
                        l = i+1;
                        is_negtive = true;
                        continue;
                }else if(str[i] == '+'){
                        l = i+1; 
                        continue;
                }else if(str[i]>='0' && str[i]<='9'){
                    l = i;
                    r = i;
                    continue;
                }else if(str[i] == ' ') continue;
                else{
                    break;
                }
            }else{
                if(!(str[i]>='0' && str[i]<='9')){
                    r = i-1;break;
                }else{
                    if(i == len-1)
                        r = i;
                }
            }  
        }
        if(r == -1) return 0;
        
        return getans(str,is_negtive,l,r);

    }
};
```
