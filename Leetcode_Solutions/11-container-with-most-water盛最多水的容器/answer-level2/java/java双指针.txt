```
public int maxArea(int[] height) {
        int max = 0;
        for(int i =0, j = height.length-1; i < j;){
            int x = j-i;
            int y = height[i] > height[j] ? height[j--] : height[i++];
            if(x*y > max){
                max = x*y;
            } 
        }
        return max;
    }
```
     
    
    
![TIM截图20191218151928.png](https://pic.leetcode-cn.com/e7fef94ca9bb6ff17f84e641ef559a73481551ff8309dd726f21b100f94035b1-TIM%E6%88%AA%E5%9B%BE20191218151928.png)

