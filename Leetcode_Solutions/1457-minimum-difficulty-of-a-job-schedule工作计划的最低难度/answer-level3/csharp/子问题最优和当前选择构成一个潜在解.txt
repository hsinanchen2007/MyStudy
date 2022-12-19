### 解题思路
对问题分情况讨论
每种情况 都有最优递归结构存在


### 代码

```csharp

using VT = System.ValueTuple<int, int>;
class JobDiff{
    private int[] jobs;
    private int maxD;
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    private Dictionary<VT, int> maxDiff = new Dictionary<VT, int>();//一个区间最大的复杂度
    private int MaxInRange(int start, int end){
        var key = (start, end);
        if(maxDiff.ContainsKey(key)) return maxDiff[key];
        var mv = 0;
        for (var i = start; i <= end; i++){
            mv = Math.Max(jobs[i], mv);
        }
        maxDiff.Add(key, mv);
        return mv;
    }
    public int total = 0;
    private int MinDiff(int startJob, int startDay){
        total++;
        // if(startJob >= jobs.Length) return 0
        if(startJob >= jobs.Length && startDay < maxD){
            return -1;//工作剩余 没时间了
        }
        if(startJob < jobs.Length && startDay >= maxD) return -1;//没时间了
        var leftDay = maxD - startDay;
        if(leftDay == 1) {
            return MaxInRange(startJob, jobs.Length - 1);
        }

        var leftJob = jobs.Length - startJob;
        if(leftJob < leftDay) return -1; //工作不够填满每天了
        var key = (startJob, startDay);
        if(cache.ContainsKey(key)) return cache[key];

        var maxCanDo = leftJob - leftDay;

        //今天做几件的范围startJob 1件
        //startJob + 
        var minDiff = Int32.MaxValue;
        var mj = jobs[startJob];
        for (var i = 0; i < (maxCanDo+1); i++){
            var endJob = startJob + i;
            mj = Math.Max(mj, jobs[endJob]);
            var afterMinSum = MinDiff(endJob+1, startDay+1);
            if (afterMinSum != -1)
            {
                var sum = mj + afterMinSum;
                minDiff = Math.Min(minDiff, sum);
            }
        }
        if(minDiff == Int32.MaxValue) minDiff = -1;
        cache.Add(key, minDiff);
        return minDiff;
    }
    public int MinDifficulty(int[] jobDifficulty, int d) {
        //每天至少一个
        //Sum(Diff) 最小
        //Max(Diff) 每天 
        //综合最小 今天 + 后面几天最小    
        jobs = jobDifficulty;
        maxD = d;
        return MinDiff(0, 0);
    }
}

public class Solution {
    public int MinDifficulty(int[] jobDifficulty, int d) {
        var jd = new JobDiff();
        return jd.MinDifficulty(jobDifficulty, d);
    }
}
```