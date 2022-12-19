### 解题思路
总思路：
能够接到的雨水面积 = 输入数组所构成的凸多边形面积（S1） - 输入数组面积（S2）

S2:
显然，S2 = sum(height[i])

S1:

在这里，我们使用两个指针（i，j)分别从左右两端遍历，每次移动之后增加斜线标识的面积到S1,示意图如下：
![1.jpg](https://pic.leetcode-cn.com/2d024d2659675c83168ff8d0a673b9188665c5705b7666b163564ae78cfbd37a-1.jpg)
![2.jpg](https://pic.leetcode-cn.com/bdbe6a66fdfbe6742bea957f792262b7cb6628c4cd05c8ca0bd400761c792b84-2.jpg)

要注意：
1. 若当前左最高值高于右最高值，则左指针保持不动；右指针同理；
2. 用一个变量pre记录前一次增加的斜线标识部分面积的高度，下一次增加的面积应是(min(height[i], height[j]) - pre) * (j - i + 1)
3. 更新左右最大高度
4. （最后返回时要注意无法接雨水的情况）



### 代码


```java []
class Solution {
    public int trap(int[] height) {
        int area = 0;
        int i = 0, j = height.length - 1;
        int l_highest = 0, r_highest = 0;
        int pre = 0;//记录前一次的高度
        while(i<j){
            if(l_highest <= r_highest){
                while(i < j && height[i] <= l_highest) //将指针右移到高于目前左最高值的位置
                    i++;
            }
            if(r_highest <= l_highest){
                while(j > i && height[j] <= r_highest) //将指针左移到高于目前右最高值的位置
                    j--;
            }
            area += (Math.min(height[i], height[j]) - pre) * (j - i + 1);
            pre = Math.min(height[i], height[j]);
            l_highest = height[i];
            r_highest = height[j];
        }
        int area_black = 0;
        for(int h : height) area_black += h;
        int area_blue = area - area_black;
        return area_blue > 0 ? area_blue : 0;
    }
}
```
```python []
class Solution:
    def trap(self, height: List[int]) -> int:
        area = 0
        i = 0
        j = len(height) - 1
        l_highest = 0
        r_highest = 0
        pre = 0
        while i < j:
            if l_highest <= r_highest:
                while i < j and height[i] <= l_highest:
                    i += 1
            if r_highest <= l_highest:
                while j > i and height[j] <= r_highest:
                    j -= 1
            area += (min(height[i], height[j]) - pre) * (j - i + 1)
            pre = min(height[i], height[j])
            l_highest = height[i]
            r_highest = height[j]
        area_black = 0
        for h in height:
            area_black += h
        area_blue = area - area_black
        return area_blue if area_blue > 0 else 0
```


