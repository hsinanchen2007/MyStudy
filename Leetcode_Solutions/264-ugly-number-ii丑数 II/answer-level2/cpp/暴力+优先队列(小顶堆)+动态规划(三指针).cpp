**1.暴力(brute force)**

```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a=1;a<=INT_MAX;a=a*2)
            for (long long b=a;b<=INT_MAX;b=b*3)
                for (long long c=b;c<=INT_MAX;c=c*5)
                    v.push_back(c);
        sort(v.begin(),v.end());
        return v.at(n-1);
    }
};
```

**2.优先队列(小顶堆)**
[优先队列/小顶堆/大顶堆](https://blog.csdn.net/weixin_36888577/article/details/79937886)
利用优先队列有自动排序的功能  
每次取出队头元素，存入```队头元素*2、队头元素*3、队头元素*5```
但注意，像12这个元素，可由4乘3得到，也可由6乘2得到，所以要注意去重
```
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q;
        double answer=1;
        for (int i=1;i<n;++i)
        {
            q.push(answer*2);
            q.push(answer*3);
            q.push(answer*5);
            answer=q.top();
            q.pop();
            while (!q.empty() && answer==q.top())
                q.pop();
        }
        return answer;
    }
};
```

还可以更进一步采用[set](https://www.cnblogs.com/ChinaHook/p/6985444.html)来识别有无重复
```
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q;
        set<int> s;
        s.insert(1);
        vector<int> mask({2,3,5});
        double answer=1;
        for (int i=1;i<n;++i)
        {
            for (int &j:mask)
                if (s.count(answer*j)==0)
                {
                    q.push(answer*j);
                    s.insert(answer*j);
                }
            answer=q.top();
            q.pop();
        }
        return answer;
    }
};
```

**3.动态规划(三指针)**
我们先模拟手写丑数的过程  
1打头，1乘2 1乘3 1乘5，现在是{1,2,3,5}  
轮到2，2乘2 2乘3 2乘5，现在是{1,2,3,4,5,6,10}
手写的过程和采用小顶堆的方法很像，但是怎么做到提前排序呢

小顶堆的方法是先存再排，dp的方法则是先排再存
我们设3个指针p_2,p_3,p_5
```代表的是第几个数的2倍、第几个数3倍、第几个数5倍```
动态方程dp[i]=min(dp[p_2]*2,dp[p_3]*3,dp[p_5]*5)
小顶堆是一个元素出来然后存3个元素
动态规划则是标识3个元素，通过比较他们的2倍、3倍、5倍的大小，来一个一个存
```
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp.at(0)=1;
        int p_2,p_3,p_5;
        p_2=p_3=p_5=0;
        for (int i=1;i<n;++i)
        {
            dp.at(i)=min(min(2*dp.at(p_2),3*dp.at(p_3)),5*dp.at(p_5));
            if (dp.at(i)==2*dp.at(p_2))
                ++p_2;
            if (dp.at(i)==3*dp.at(p_3))
                ++p_3;
            if (dp.at(i)==5*dp.at(p_5))
                ++p_5;
        }
        return dp.at(n-1);
    }
};
```









