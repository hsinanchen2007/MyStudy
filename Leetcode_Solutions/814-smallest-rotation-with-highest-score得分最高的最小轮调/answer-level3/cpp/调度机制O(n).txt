首先先上全部的代码，再分段看看：
```
int bestRotation(vector<int>& A) 
    {
        int n = A.size();
        vector<int> score(n+1, 0);

        for(int i=0; i<n; i++)
        {
            if(A[i]>=n) continue;
            else if(A[i]>i) //[i+1, n+i-A[i]]
            {
                score[i+1]++;
                score[n+i-A[i]+1]--;
            }
            else if(A[i]<=i) //[0, i-A[i]], [i+1, n-1]
            {
                score[0]++;
                score[i-A[i]+1]--;
                score[i+1]++;
                score[n]--;
            }
        }  
        int res = 0;
        int val = score[0];
        for(int i=1; i<n; i++)
        {
            score[i] += score[i-1];
            if(val<score[i]) val = score[i], res = i;
        }
        return res;
    }
```

score[i] 表示经过i次调度后，在i调度时的答案变化
```
for(int i=0; i<n; i++)
{
    if(A[i]>=n) continue;
    else if(A[i]>i) //[i+1, n+i-A[i]]
    {
        score[i+1]++;
        score[n+i-A[i]+1]--;
    }
    else if(A[i]<=i) //[0, i-A[i]], [i+1, n-1]
    {
        score[0]++;
        score[i-A[i]+1]--;
        score[i+1]++;
        score[n]--;
    }
}  
```
比如[2,3,1,4,0] 这个例子：
下标为0，A[0] = 2, A[0]>0;
K=0 [2,3,1,4,0]
K=1 [3,1,4,0,2]
K=2 [1,4,0,2,3]
K=3 [4,0,2,3,1]
K=4 [0,2,3,1,4]
只有k=1，k=2，k=3时这个index=0，A[index]=2是可以得分的;
用笔算算 可以知道 k>=i+1 && k<=n+i-A[i] 是可以得分的

下标为2，A[2] = 1, A[2]<2;
K=0 [2,3,1,4,0]
K=1 [3,1,4,0,2]
K=2 [1,4,0,2,3]
K=3 [4,0,2,3,1]
K=4 [0,2,3,1,4]
有k=0, k=1, k=3, k=4 可以得分
用笔算 k>=0 k<=i-A[i] || k>=i+1 k<=n-1

得到score

后面计算最大值，其实有点像之前的一道任务调度题，具体哪题忘了，因为只记录了开头和结尾的数据变化，所以要叠加起来才能得到i次调度后的结果。

