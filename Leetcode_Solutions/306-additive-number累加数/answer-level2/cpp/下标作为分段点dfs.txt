### 解题思路
首先要感谢[@da-li-wang](/u/da-li-wang/)，本身写的没有这么清晰，参考其代码进行了改进。
当前这版代码使用下标分段点，从计算角度逻辑会清晰一些。

1.为了处理大正数相加应该使用两字符串相加的程序，并且与和的字符串比较，避免转换为int消耗时间与溢出。

2.dfs时的i,j,k分别代表第一个、第二个和第三个数字的起始下标，这样好处在于计算各个字符串时都很方便。

3.第一个数字的起始下标一定是0，但是第二和第三个数字的起始下标不固定，需要通过两层循环枚举，在拿到起始数字之后，就可以dfs一直到最后验证是否整个字符串符合要求。

4.这道题dfs的递归结束条件和普通稍有不同，要仔细思考。这里递归成功的标志是一直到字符串最后一个字符都满足要求，即是累加序列，那么我们需要看是否能够递归到最后一个位置正好结束。

### 代码

```cpp
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int i=0;
        for(int j=i+1;j<=num.size()-1;j++){
            for(int k=j+1;k<=num.size()-1;k++){
                if(dfs(num,i,j,k)) return true;
            }
        }
        return false;
    }

    bool dfs(string& s,int i,int j,int k){
        if((s[i]=='0'&&j-i>1)||(s[j]=='0'&&k-j>1)) return false;
        string a=s.substr(i,j-i);
        string b=s.substr(j,k-j);
        string sum=add(a,b);
        int n=sum.size();
        if(k+n-1>s.size()-1||sum!=s.substr(k,n)) return false;
        if(k+n-1==s.size()-1) return true;
        return dfs(s,j,k,k+n);    
    }

    string add(string& a,string& b){
        int n1=a.size()-1;
        int n2=b.size()-1;
        int carry=0;
        string ans;
        while(n1>=0||n2>=0||carry>0){
            int t1=n1>=0?a[n1--]-'0':0;
            int t2=n2>=0?b[n2--]-'0':0;
            ans+=(t1+t2+carry)%10+'0';
            carry=(t1+t2+carry)>=10?1:0;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```