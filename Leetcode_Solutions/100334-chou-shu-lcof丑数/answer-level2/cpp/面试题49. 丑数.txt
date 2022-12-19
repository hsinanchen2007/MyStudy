### 暴力解法
由于丑数只有2，3，5三个因子，因此一个数如果为丑数，那么它不断除以2，3，5，最终得到的数会是1。因此，暴力的解法就是从1到无穷一直寻找，直到找到第n个丑数
### 时间/空间复杂度
时间复杂度：O（n3）
空间复杂度：O（1）
### 代码
```
class Solution {
public:
    bool isUgly(int n){
        while(n%2==0) n/=2;
        while(n%3==0) n/=3;
        while(n%5==0) n/=5;
        return n==1;
    }
    int nthUglyNumber(int n) {
        int number=0;
        for(int i=0;i<n;++i){
            number++;
            while(!isUgly(number)) number++;
        }
        return number;
    }
};
```
### 优先队列
设置一个优先队列来使得丑数有序，使用一个set来进行去重。每一次从优先队列取出第一个值num，然后分别乘以2，3，5，当没有重复的时候，插入优先队列，直到第n个。
### 时间/空间复杂度
时间复杂度：O（n）
空间复杂度：O（n2）
### 代码
```
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,std::greater<long>> Q;
        set<int> S;
        Q.push(1);
        long num=1;
        for(int i=0;i<n;++i){
            num=Q.top();Q.pop();
            if(S.find(num*2)==S.end()){
                 Q.push(num*2);
                 S.insert(num*2);
            }
            if(S.find(num*3)==S.end()){
                 Q.push(num*3);
                 S.insert(num*3);
            }
            if(S.find(num*5)==S.end()){
                 Q.push(num*5);
                 S.insert(num*5);
            }
        }
        return (int)num;
    }
};
```
### 动态规划
我们设置三个指针p2，p3，p5，每次这三个指针都对应乘以2，3，5，然后取这三个对应乘积中较小的那一个作为当前值，并且对应指针往后走。
dp[i]=min(dp[p2]*2,dp[p3]*3,dp[p5]*5)
### 时间/空间复杂度
时间复杂度：O（n）
空间复杂度：O（n）
### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        int p2=0,p3=0,p5=0;
        dp[0]=1;
        for(int i=1;i<n;++i){
            dp[i]=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
            if(dp[i]==dp[p2]*2) p2++;
            if(dp[i]==dp[p3]*3) p3++;
            if(dp[i]==dp[p5]*5) p5++;
        }
        return (int)dp[n-1];
    }
};
```