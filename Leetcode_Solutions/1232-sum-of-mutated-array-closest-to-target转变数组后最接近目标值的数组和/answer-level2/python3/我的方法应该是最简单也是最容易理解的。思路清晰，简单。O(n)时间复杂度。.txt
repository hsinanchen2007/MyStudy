把数组分为两部分，一部分大于平均值，一部分小于平均值。target减去小于平均值的所有数之和。剩下再操作，很简单
target=target-sum(a)求出了更进一步的结果。剩下就是考虑target和b。要让b最接近target，当然应该是让b的每个数为target//len(b)或者+1了。因为b中的每一个数都大于target/len(b)。求出的target//len(b)和target//len(b)+1从下和上对target进行了包围，别的差值都会更大。
```
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        average=target/len(arr)
        a=[]
        b=[]
        for i in arr:
            if i<=average:
                a.append(i)
            else:
                b.append(i)
        target-=sum(a)
        l=len(b)
        a1=target//l
        a2=a1+1
        d1=abs(a1*l-target)
        d2=abs(a2*l-target)
        if d1<=d2:
            return a1
        else:
            return a2
```
评论反馈我做错了，改正之后现在完美了，不过我不知道复杂度是多少了。不过依然很直观，很好理解
```
class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        if sum(arr)<=target:
            return max(arr)
        part1=[]
        part2=[]
        for a in arr:
            if a<=target/len(arr):
                part1.append(a)
            else:
                part2.append(a)
        while part1:
            target-=sum(part1)
            tmp=part2
            part1=[]
            part2=[]
            for a in tmp:
                if a<=target/len(tmp):
                    part1.append(a)
                else:
                    part2.append(a)
        return target//len(part2) if target%len(part2)<=len(part2)/2 else target//len(part2)+1
```