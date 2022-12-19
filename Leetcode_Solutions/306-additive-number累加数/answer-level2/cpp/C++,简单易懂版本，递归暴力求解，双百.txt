![image.png](https://pic.leetcode-cn.com/b1994e611cc043232b6ac0bb8dbb6154ddf2ba8ae981eef4b327bc818cfb56d0-image.png)


```
typedef long long ll;
class Solution {
public:
//这里需要注意一个前提条件就是，前两个数的长度一定是小于等于第三个数的。。。
    bool isValid(ll first,ll second,int start,string num){
        if(start==num.length())return true;//表示已经走到末尾了，是符合条件的。。。
        second=second+first;
        first=second-first;
        string sum=to_string(second);
        int len=sum.length();
        return sum==num.substr(start,len)&&isValid(first,second,start+len,num);
    }
    bool isAdditiveNumber(string num) {
        if(num.length()<3)return false;
        int n=num.length();
        for(int i=1;i<=n/2;i++){//i表示的是长度
            if(i>1&&num[0]=='0')return false;//当出现第一个是0的时候，后面不需要再比较了，一定是不符合要求的
            ll first=stoll(num.substr(0,i));
            for(int j=1;n-i-j>=max(i,j);j++){
                if(num[i]=='0'&&j>1)break;//这个时候，还是有可能有满足条件的字符串，所以不能直接返回false。
                ll second=stoll(num.substr(i,j));
                //cout<<first<<" "<<second<<endl;
                if(isValid(first,second,i+j,num)){
                    return true;
                }
            }
        }
        return false;
    }
};
```


