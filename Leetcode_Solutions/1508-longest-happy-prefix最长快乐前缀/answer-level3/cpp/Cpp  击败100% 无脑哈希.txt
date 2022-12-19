### 解题思路
![QQ浏览器截图20200322125143.png](https://pic.leetcode-cn.com/57f0436008bc888d115c8ae6fe848fcb1ee5db942963a8377431381667e0ad40-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200322125143.png)

偷懒不写KMP,就直接无脑哈希，毕竟这种数据范围发生哈希冲突概率应该不高。
就是直接把前缀和后缀处理成26进制的数，然后把字符串比较直接变成数的比较。


### 代码

```cpp
class Solution {
    long long Q[100100],H[100100],P[100100];
    const long long M=1000000007;
    int n;

void power(int n){//预处理一个26的幂次表
    P[0]=1;
    for(int i=1;i<=n;i++)
    P[i]=(P[i-1]*26)%M;
}
public:
    string longestPrefix(string s) {
        n=s.length();
        power(n);

        Q[0]=s[0]-'a';//制作前缀数组
        for(int i=1;i<n;i++)
        Q[i]=(Q[i-1]*26+s[i]-'a')%M;

        H[0]=s[n-1]-'a';//制作后缀数组
        for(int i=n-2;i>=0;i--)
        H[n-1-i]=(H[n-i-2]+(s[i]-'a')*P[n-1-i])%M;

        int ans=-1;
        for(int i=n-2;i>=0;i--)
        if(Q[i]==H[i]){
            ans=i;
            break;
        }

        if(ans<0)
        return "";
        else return s.substr(0,ans+1);
    }
};
```