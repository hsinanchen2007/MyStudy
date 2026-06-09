```
class Solution(object):
    def sampleStats(self, count):
        """
        :type count: List[int]
        :rtype: List[float]
        """
        mi = 300
        mx = -1
        sm = 0.0
        ct = 0.0
        zws = -1
        nums = []
        zs = count.index(max(count))
        for i in range(len(count)):
            if count[i] > 0:
                if i<mi:
                    mi = i
                if i>mx:
                    mx = i
                nums.append(i)
                sm += float(count[i])*i
                ct += float(count[i])
        l = len(nums)
        idx = ct//2
        isevent = ct%2 == 0
        l1 = 0.0
        l2 = 0.0
        sumidx = 0
        for i in range(len(count)):
            if count[i] > 0:
                if idx > sumidx and idx<=sumidx+count[i]:
                    l1 = i
                if idx+1 > sumidx and idx+1<=sumidx+count[i]:
                    l2 = i
                sumidx += count[i]
        if isevent:
            zws = (l1+l2)/2.0
        else:
            zws = float(l2)
        print(l1,l2,ct)
        
        print(nums)
        return [float(mi), float(mx), float(sm)/ct, float(zws), zs]

        
```
优化代码
```
class Solution(object):
    def sampleStats(self, count):
        """
        :type count: List[int]
        :rtype: List[float]
        """
        mi = 300
        mx = -1
        sm = 0.0
        ct = sum(count)
        zs = count.index(max(count))
        halfct = ct//2
        isevent = ct%2 == 0
        l1 = 0.0
        l2 = 0.0
        sumidx = 0
        for i in range(len(count)):
            if count[i] > 0:
                if i<mi:
                    mi = i
                if i>mx:
                    mx = i
                sm += float(count[i])*i
                if halfct > sumidx and halfct<=sumidx+count[i]:
                    l1 = i
                if halfct+1 > sumidx and halfct+1<=sumidx+count[i]:
                    l2 = i
                sumidx += count[i]
        if isevent:
            zws = (l1+l2)/2.0
        else:
            zws = float(l2)
        return [float(mi), float(mx), float(sm)/ct, float(zws), zs]

```
