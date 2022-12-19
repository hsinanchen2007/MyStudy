依旧菜鸡，败在了考虑各种情况

出现偶数次的字母肯定放心加上

出现奇数次的就相对复杂

最长的奇数频次不用-1，其他的奇数频次需要去掉一个字母让他变成偶数然后加上这个频次，所以循环里统计出现奇数频次的次数odd，循环出来，result加上这个次数odd-1就好了。

上代码

```perl
int longestPalindrome(string s) {
        if(!s.length()) return 0;
        int freq[256] = {0};

        int odd = 0;

        int res = 0;

        for(int i = 0; i<s.length(); i++){
            freq[s[i]] ++;
        }

        for(int j = 0; j < 256; j++){
                if(freq[j] % 2 == 0){//0或者正偶数
                    res += freq[j];
                }
                else{//奇数的情况,最长的奇数+其他奇数-1的和，"其他奇数-1的和"怎么求？
                    odd += 1;
                    res += freq[j];
                }
            
        }
        //在这里卡住了，首先odd-1想了好久，其次，这个if没加，提交了两次错误答案/(ㄒoㄒ)/~~
        //这个if坑死我了
        if(odd>0){
            res -= (odd - 1);

        }
        return res;
    }
```
