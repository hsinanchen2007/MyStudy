第一种， DP动态规划
```
class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        #dp[i] is the min clips number can cover the time 0-i
        dp =[float('inf')]*(T+1)
        dp[0] = 0
        for i in range(1,T+1):
            for clip in clips:
                # 找到包含结束端点的视频片段
                if (clip[0] < i <= clip[1]):
                    # 缩小问题范围，求覆盖 (0 - clip[0]) 区间的视频的最小片段数量 
                    dp[i] = min(dp[i], dp[ clip[0] ] + 1)
        return -1 if (dp[T] == float('inf')) else dp[T]
```
第二种， 贪心
```
class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        n = len(clips)
        clips = sorted(clips,key = lambda x:x[0])     # reverse=True降序， 默认升序
        res = last_end = j = 0
        for i in range(n):
            if last_end >= T: break
            maxLength = last_end 
            while (j < n and clips[j][0] <= last_end):  #  贪心地寻找能够overlap的区间中找最长的
                maxLength = max(maxLength, clips[j][1])
                j+=1
            if (j == i): return -1  # 找不到可选区间
            last_end = maxLength
            i = j - 1
            res += 1 
        return -1 if last_end < T else res
```

