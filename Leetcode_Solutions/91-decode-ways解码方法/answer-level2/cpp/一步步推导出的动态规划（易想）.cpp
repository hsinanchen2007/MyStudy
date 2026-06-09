# 91 解码方法
> 一条包含字母 A-Z 的消息通过以下方式进行了编码：
'A' -> 1
'B' -> 2
...
'Z' -> 26
> 给定一个只包含数字的非空字符串，请计算解码方法的总数。

```
输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
```

## 思路1：回溯（超时）
将string s分割，有多少种可能，很明显可以使用回溯算法做。每次有2个选择，即分割1位数还是2位数，做完选择撤销回溯即可。使用void作为函数返回值，全局变量记录。

```
class Solution {
public:
    int count = 0;
    int numDecodings(string s) {
        // 1~26
        // 判断该字符串有几种分割方式
        backtrack("", s, 0);
        return count;
    }
    void backtrack(string path, string s, int start){
        if(path.size() == s.size()){// 全部分割完毕
            count++;
            return;
        }

        string sub_1 = s.substr(start,1);
        string sub_2 = s.substr(start,2);
        // 1位数的选择
        for(int i=1;i<=9;i++){
            if(sub_1 == to_string(i)){
                backtrack(path+sub_1, s, start+1);// 下一层
                break;
            }
        }
        // 2位数的选择
        for(int i=10;i<=26;i++){
            if(sub_2 == to_string(i)){
                backtrack(path+sub_2, s, start+2);// 下一层
                break;
            }
        }
        return;
    }
    
};
```

## 思路2：记忆表优化
发现方法1中，会重复计算不同start的情况，我们可以采用记忆表优化，将以start开头的字符串分割可能数，记录下来。
不同点：
1. 函数返回值改为int
2. 不使用全局int计数

```
class Solution {
public:
    int numDecodings(string s) {
        // 1~26
        // 判断该字符串有几种分割方式
        return backtrack("", s, 0);
    }
    unordered_map<int,int> memo;// 以start开头分割字符串有几种可能

    // 以start开头分割字符串有几种可能
    int backtrack(string path, string s, int start){

        if(memo.find(start) != memo.end()){
            return memo[start];
        }

        int res = 0;
        if(path.size() == s.size()){// 全部分割完毕,返回1种可能
            return 1;
        }
        string sub_1 = s.substr(start,1);
        string sub_2 = s.substr(start,2);
        // 1位数的选择
        for(int i=1;i<=9;i++){
            if(sub_1 == to_string(i)){
                res += backtrack(path+sub_1, s, start+1);// 下一层
                break;
            }
        }
        // 2位数的选择
        for(int i=10;i<=26;i++){
            if(sub_2 == to_string(i)){
                res += backtrack(path+sub_2, s, start+2);// 下一层
                break;
            }
        }
        memo[start] = res;
        return res;
    }
    
};
```

## 思路3：迭代
自底向上，初始化`dp[n-1]和dp[n-2]`，如果`s.substr(i,1)` 在1~9之间，`s.substr(i,2)`在10~26之间的话` dp[i] = dp[i+1] + dp[i+2] `

```
class Solution {
public:
    int numDecodings(string s) {
        // 1~26
        // 判断该字符串有几种分割方式
        int n = s.size();
        if(n == 0){
            return 0;
        }

        vector<int> dp(n, 0);// 以i开头的字符串有几种分割可能
        
        // 初始化dp[n-1]和dp[n-2]
        dp[n-1] = (s[n-1] == '0' ? 0 : 1);//最后一位如果不是0，只有一种可能
        if(n >= 2){
            string sub_1 = s.substr(n-2,1);
            string sub_2 = s.substr(n-2,2);
            // s="10"  只有1种可能
            dp[n-2] += (sub_1>="1" && sub_1 <="9"? dp[n-1]:0);
            dp[n-2] += (sub_2>="10" && sub_2 <="26"? 1:0);
        }

        // 如果i+1在1~9之间，i+2在10~26之间的话 dp[i] = dp[i+1] + dp[i+2] 
        for(int i=n-3;i>=0;i--){
            string sub_1 = s.substr(i,1);
            string sub_2 = s.substr(i,2);
            // 是否1位数的选择
            dp[i] += (sub_1>="1" && sub_1 <="9"? dp[i+1]:0);
            // 是否有2位数的选择
            dp[i] += (sub_2>="10" && sub_2 <="26"? dp[i+2]:0);
        }
        return dp[0];
    }
    
};
```


