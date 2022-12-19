```
    // 1.首先确定最低效率x是多少
    // 2.在所有效率>=x的人中挑出k个速度最大的,记他们的和为sum
    // 3.对于每种最低效率的情况下，计算表现值的最大值res,则 res = max(res,sum*x)
    
    // 对于第1,2步 可以将所有人按照效率从大到小排序,然后以每个人的效率作为最低效率,进行计算
    // 对于第3步,可以用优先队列,在里面保证最多装k个最大的速度
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        typedef long long LL;
        pair<int,int> a[n];
        for(int i = 0; i < n; i++) a[i] = {e[i], s[i]};
        sort(a,a+n,[&](pair<int,int> t1, pair<int,int> t2)-> bool{//按照效率从大到小
            return t1.first > t2.first;
        });
        priority_queue<int,vector<int>,greater<int> > q;//速度的优先队列 小根堆 最多保留k个
        LL res = 0,sum=0;//sum为当前效率下 最大的k个人的速度之和
        for(int i = 0; i < n; i++){//从大到小枚举效率 
            int &x = a[i].first, &y = a[i].second;//x-当前效率的最小值 y-新加入的人的速度
            sum += y;
            q.push(y);
            if(q.size()>k) sum-=q.top(),q.pop();//超出k个时则弹出一个速度最小的
            res = max(res,sum*x);//当前的表现值
        }
        return res % 1000000007; 
    }
```
