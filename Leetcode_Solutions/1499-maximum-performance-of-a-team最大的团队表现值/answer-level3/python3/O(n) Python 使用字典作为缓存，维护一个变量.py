使用字典存储每个元素出现的次数
将speed与efficiency绑定为一个元组
元组按照effi进行排序
从最低效率开始，取右侧最大K个值，与当前效率相乘。
因为开始为0，故原始speed升序排列后K个即为答案。
下一个为1，先看1对应的speed对应出现次数是否为0，为0，说明在sum的cache里头，减去该值。同时，从排序后的speed队末添加新计数不为0的元素。
不为0，字典计数减一，跳过
重复上述步骤，遍历得到最大结果。
```
class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        zips=[(i,j) for i,j in zip(speed,efficiency)]
        zips.sort(key=lambda x:x[1])
        speed.sort()
        count=collections.Counter(speed)
        cache=0
        for i in speed[::-1][:k].copy():
            count[i]-=1
            cache+=speed.pop()
        max_=cache*zips[0][1]
        for i in range(1,len(zips)):
            sp=zips[i-1][0]
            if not count[sp]:
                cache-=sp
                while len(speed) and not count[speed[-1]]:
                    speed.pop()
                if len(speed):
                    num=speed.pop()
                    cache+=num
                    count[num]-=1
            else:
                count[sp]-=1
            max_=max(zips[i][1]*cache,max_)
        return max_%(10**9+7)
```
