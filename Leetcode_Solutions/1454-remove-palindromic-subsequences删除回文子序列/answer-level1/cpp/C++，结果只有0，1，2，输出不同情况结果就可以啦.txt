```
//删除回文子序列，注意是子序列不是子串，不要求连续，答案不是1就是2或者是0，所以只要对这三种情况进行判断就可以啦。。。
class Solution {
public:
    int removePalindromeSub(string s) {
        int ans=0;
        int n=s.size();
        if(n==0)return 0;
        bool flag=false;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-i-1]){
                continue;
            }
            else{
                flag=true;
            }
        }
        if(!flag)return 1;
        return 2;
    }
};
```
