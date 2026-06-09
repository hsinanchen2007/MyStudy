### 解题思路
首先对L,R开方，缩小范围，然后再开方，进行构造，因为8位的回文数只需要4位数复制加上它的反转就行了
其实代码还可以优化，但懒得搞了

### 代码

```cpp
class Solution {
public:
    bool huiwen(long long x){
        string s=to_string(x);
        int i,n=s.size();
        for(i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1])return false;
        }
        return true;
    }//判断回文函数
    int superpalindromesInRange(string L, string R) {
        long long i,j,ans=0,l=ceil(sqrt(stoll(L,0,10))),r=(long long)(sqrt(stoll(R,0,10)));
        for(i=1;i<=9;i++){
            if(i>=l&&i<=r&&huiwen(i*i))ans++;
        }//1~9特判
        for(i=sqrt(l)/10;i<sqrt(r)*10;i++){
            string s=to_string(i);//转化为字符串
            int k=s.size();
            string s2=s;//取得s的反转
            reverse(s2.begin(),s2.end());
            j=stoll(s+s2,0,10);//拼接
            if(j>=l&&j<=r&&huiwen(j*j))ans++;//满足条件++
            if(k>1){
                s.pop_back();//回文串长度是奇数的情况
                j=stoll(s+s2,0,10);
                if(j>=l&&j<=r&&huiwen(j*j))ans++;
            }    
        }
        return ans;
    }
};
```