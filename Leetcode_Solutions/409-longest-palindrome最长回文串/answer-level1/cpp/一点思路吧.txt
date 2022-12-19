### 解题思路
首先观察回文数的特点，只要字母的个数是2的倍数，就可以成为回文数的元素，如果余下单个字母，个数就再加一，
哎，难点就是计算各个字母的个数的时候想着用map，结果不太会，然后发现普通的就可以计数

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int a[52]={0};//注意初始化的时候数组是用大括号
        for(int i=0;i<s.size();i++){
            if('a'<=s[i]&&'z'>=s[i]){
                a[s[i]-'a']++;
            }
            else{
                a[s[i]-'A'+26]++;
            }
        }
        int sum=0,b=0;
        for(int j=0;j<52;j++){
            sum+=a[j]/2*2;//这里注意首先判断这个字母能成为回文数的对数，然后乘二就是元素的个数
            b=b||(a[j]%2);
        }
        return sum+b;
        
    }
};
```