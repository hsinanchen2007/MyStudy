双指针是跟前面的老哥学的
**但是双指针较短的一边往中间移动时,因为 面积是 指针距离*高度,
所以往中间移动的话指针距离在减小,只有高度增加才有可能面积更大。**
所以高度比指针所指的高度 要低的话就可以直接忽略。增加了四行代码,但是耗时最短。
```
i = 0
        j = len(height)-1
        maxium = 0
        while 1:
            maxium = max(maxium,min(height[i],height[j])*(j-i))
            if height[i] < height[j]:
                i += 1
                while height[i]<height[i-1]:   # 忽略比移动指针更短的边
                    i += 1
            else:
                j -= 1
                while height[j]<height[j+1]:
                    j -= 1
            if i == j:
                break
        return maxium
```
