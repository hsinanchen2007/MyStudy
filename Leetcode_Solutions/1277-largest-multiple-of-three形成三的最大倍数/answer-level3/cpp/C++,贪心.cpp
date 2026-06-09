```
const int maxn=1e4+10;
int ans[maxn];
class Solution {
public:
//贪心解法，看了一下题解才写的。。。
//思路是：当sum%3==1时，可以删除一个1，4，7，这样就可以使得和为取3模为0，或者删除两个2，5，8也可以
//当sum%3==2时，可以删除一个2，5，8，或者删除两个1，4，7也是可以的。。。
    int del(int x){
        for(int i=x;i<=9;i+=3){
            if(ans[i]!=0){
                ans[i]--;
                return 1;
            }
        }
        return 0;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        int sum=0;
        memset(ans,0,sizeof(ans));
        for(int i=0;i<digits.size();i++){
            ans[digits[i]]++;
            sum+=digits[i];
        }
        if(sum%3==1){//优先删除一个数字。。。
            if(!del(1)){
                del(2);
                del(2);
            }
        }
        if(sum%3==2){
            if(!del(2)){
                del(1);
                del(1);
            }
        }
        string res="";
        for(int i=9;i>=0;i--){
            while(ans[i]!=0){
                res+=(i+'0');
                ans[i]--;
            }
        }
        if(res.length()&&res[0]=='0')return "0";
        //if(res.length()==0)return "";
        return res;
    }
};
```
