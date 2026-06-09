### 解题思路
该题类似爬楼梯，可以从末端向最前遍历，便能自底向上解决问题。dp[i]=dp[i+1]+dp[i+2]*flag 若第i位和第i+1位拼接数在10~25范围内，flag为1，否则为0。

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
       if(num<0){
           return 0;
       }
       string numstring=to_string(num);
        return getcount(numstring);
    }
    int getcount(const string&numstring){
        int len=numstring.size();
        int count=0;
        vector<int>vec(len);
        for(int i=len-1;i>=0;i--){
            count=0;
            if(i<len-1){
                count=vec[i+1];
            }
            else{
                count=1;
            }
            if(i<len-1){
                int num=numstring[i]-'0';
                int num1=numstring[i+1]-'0';
                int result=num*10+num1;
                if(result>=10&&result<=25){
                    if(i<len-2){
                        count+=vec[i+2];
                    }
                    else{
                        count+=1;
                    }
                }
            }
            vec[i]=count;
        }
        return vec[0];
    }
};
```