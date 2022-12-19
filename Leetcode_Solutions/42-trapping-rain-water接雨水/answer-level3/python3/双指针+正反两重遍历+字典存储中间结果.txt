思路：双指针+正反两重遍历
步骤：
1.首先讨论如何得到一小个凹槽中的水量，设i为起始边，从j=i+1开始往右寻找，直到height[j]>=height[i]，此时的i，j即为凹槽的两边，然后令i=j,j=i+1开始新一轮的查找。记住将每个凹槽以（起始边，终结边，容量）记录在字典中。
2.从左往右寻找凹槽可能会出现遗漏，譬如示例中，中间有一条最高的边，那么该边右边的凹槽便无法得到统计，听此还需要从右往左再遍历一次。
3.将字典中所有的凹槽容量相加，即得到结果。
```
    def trap(self, height: List[int]) -> int:
        d={}
        result=0
        i=0
        j=i+1
        while i<=len(height)-1:
            temp=0
            while j<=len(height)-1 and height[j]<height[i]:
                temp=temp+(height[i]-height[j])
                j+=1
            if j>len(height)-1:
                i=len(height)
                break
           # print(i,j,temp)
            if height[j]>=height[i]:
                d[(i,j)]=temp
            i=j
            j=i+1
        i=len(height)-1
        j=i-1
        while i>=0:
            temp=0
            while j>=0 and height[j]<height[i]:
                temp=temp+(height[i]-height[j])
                j-=1
            if j<0:
                i=-1
                break
            #print(i,j,temp)
            if height[j]>=height[i]:
                d[(j,i)]=temp
            i=j
            j=i-1
        for key in d.keys():
            result+=d[key]
        return result
```
