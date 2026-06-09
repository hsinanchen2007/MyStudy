回文串是面试以及笔试中非常常见的一类问题，下面讲解下回文串的求法。
首先，理清这么一个概念：子串和子序列。
对于子串来说：必须是原字符串中连续的一部分
对于子序列来说：是原字符串中的随机取出的一些，只需要保存相对位置即可。

对于此题，我们要求出最长的连续回文子串。
首先最暴力的方法是什么呢？

### 暴力法
最暴力的方法听起来很简单：
枚举所有的子串，然后判断是否是回文串，如果是回文串则记录。从记录中找到最大的回文串即可。
```
string longestPalindrome(string s) {
        string res=s[0];
        int maxLen=1;
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();i++){
                string tmp=s.substr(i,j-i+1);
                if(isPalindrome(tmp)&&tmp.size()>maxLen){
                    maxLen=tmp;
                    res=tmp;
                }
            }
        }
        return res;
    }
```

这么做肯定会超时的，因为复杂度为O(n^3)，虽然只有两层循环，但是判断是否是回文串需要浪费大量的时间。

### 中心扩展法
下面这种方法就比较巧妙了，回文串的主要特点是正着数和反着数一样。所以从中间往两边是对称的。
对于长度为奇数的回文串，我们找到中间的数，然后两边扩展可以得到回文串。比如abacaba
对于长度为偶数的回文串，我们分为两半，找左侧最后一个和右侧第一个，往两边扩展可以得到回文串，比如abaaba。

基于以上，我们可以使用中心扩展法求解回文子串。
1.以当前字母为中心进行奇数扩展
2.如果当前字母和左侧字母一致，两侧扩展。
3.如果当前字母和右侧字母一致，两侧扩展。

根据中心扩展法可以求得最优解：
代码：
```
class Solution {
public:
    string expendOdd(int idx,string s){
        int left=idx,right=idx;
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        left+=1;
        right-=1;
        return s.substr(left,right-left+1);
    }
    string expendEven(int left,int right,string s){
        if(s[left]!=s[right]){
            return "";
        }
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;
            right++;
        }
        left+=1;
        right-=1;
        return s.substr(left,right-left+1);
    }
    bool Palindrome(string s){
        if(s.size()<=1){
            return true;
        }
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(Palindrome(s)){
            return s;
        }
        string res;
        res+=s[0];
        for(int i=1;i<s.size()-1;i++){
            string odd=expendOdd(i,s);
            string leven=expendEven(i-1,i,s);
            string reven=expendEven(i,i+1,s);
            if(odd.size()>res.size())   res=odd;
            if(leven.size()>res.size()) res=leven;
            if(reven.size()>res.size()) res=reven;
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/da80ddf536fdf41af7ee9ed06c726ed58f5bf14b905b2c0b304c79ad54482376-image.png)

#### 动态规划法
对于动态规划求解字符串类的问题，一般都已经套路化了。
首先定义状态
dp[i][j] :s[i:j)是不是回文串
状态转移方程为：
dp[i][j]=dp[i][j]||(s[i]==s[j-1]&&dp[i+1][j-1]) (j>i)

对于很多人来说，找到了状态转移方程，不会写方向，我们看一下这个转移方程。
i与i+1有关，j与j-1有关。则i从大往小滚动，j从小往大滚动。同时保证j>i即可。
因此代码如下：
```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1){
            return s;
        }
        int n=s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            dp[i][i+1]=true;
        }
        dp[n][n]=true;
        int res=0,left=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<=n;j++){
                dp[i][j]=(s[i]==s[j-1])&&dp[i+1][j-1]||dp[i][j];
                if(dp[i][j]&&j-i>res){
                    res=j-i;
                    left=i;
                }
            }
        }
        return s.substr(left,res);
    }
};
```
