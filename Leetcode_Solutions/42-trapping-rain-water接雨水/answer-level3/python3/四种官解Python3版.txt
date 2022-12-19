方法一：暴力法
```
class Solution:
    def trap(self, height: List[int]) -> int:
        all_rain = 0
        for i in range(1,len(height)-1):
            all_rain+=max((min(max(height[0:i]),max(height[i:]))-height[i]),0)
        return all_rain
```

方法二：动态编程
```
class Solution:
    def trap(self, height: List[int]) -> int:
        left_max = []
        right_max = []
        temp_num = 0
        for i in height:
            if i >temp_num:
                temp_num=i
            left_max.append(temp_num)
        temp_num = 0
        height.reverse()
        for i in height:
            if i>temp_num:
                temp_num=i
            right_max.append(temp_num)
        right_max.reverse()
        height.reverse()
        temp_num = 0
        for i in range(1,len(height)-1):
            temp_num+=max(0,(min(left_max[i-1],right_max[i+1])-height[i]))
        return temp_num
```

方法三：栈的应用
```
class Solution:
    def trap(self, height) -> int:
        ans = 0
        current = 0
        stack_list = []
        while(current<len(height)):
            print(stack_list)
            while stack_list and height[current]>height[stack_list[-1]]:
                print(stack_list)
                top = stack_list.pop()
                if not stack_list:
                    break
                distance = current-stack_list[-1]-1
                bounded_height = min(height[current],height[stack_list[-1]])-height[top]
                ans+=distance*bounded_height
            stack_list.append(current)
            current+=1
        return ans        
```

方法四：双指针
```
class Solution:
    def trap(self, height) -> int:
        left = 0
        right = len(height)-1
        ans = 0
        left_max = 0
        right_max = 0
        while left<right:
            if height[left]<height[right]:
                if height[left]>=left_max:
                    left_max = height[left]
                else:
                    ans+=(left_max-height[left])
                left+=1
            else:
                if height[right]>=right_max:
                    right_max=height[right]
                else:
                    ans+=(right_max-height[right])
                right-=1
        return ans
```


