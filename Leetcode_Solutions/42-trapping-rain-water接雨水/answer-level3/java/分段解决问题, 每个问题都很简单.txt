1. 将题目给的数组分为三段(或两段) , 方法是依次从左边到右边寻找最大值. 
2. 计算左边部分, 设置left指针, 如果height[left]==0, 则直接移动left.
  从left 到 左边最大值索引进行遍历, 如果height[i]>=height[left] , 从left到i再进行一次遍历, height[left]-height[j] 的值就是蓄水部分, 然后left=i;
3. 中间部分最简单, 直接两个最大值之间部分, 用最大值减去每个数组项, 都是蓄水部分.
4. 右边部分是左边部分镜像. 


```java []
public static void main(String[] args) {
        S42 s42 = new S42();
      int[] arr = new int[]{0,1,0,2,1,0,1,3,2,1,2,1};
        //    int[] arr = new int[]{2,0,2};
        int trap = s42.trap(arr);
        System.out.println(trap);
    }
    public int trap(int[] height) {
        if(height.length<2) return 0;
        int totalTrap = 0;
        int left = 0;
        int right=0;
        int maxIndexLeft = findMaxLeft(height);
        if(height[maxIndexLeft]==0) {
            return 0;
        }
        int maxIndexRight = findMaxRight(height);
        //1. 处理左边问题
        left = 0;
        //1.1 跳过0起点
        while(height[left]==0) {
            left++;
        }
        for (int i = left+1; i <= maxIndexLeft; i++) {
            if(height[i]<height[left]) {
                continue;
            }else {
                for(int j = left+1;j<i;j++) {
                    totalTrap+=height[left]-height[j];
                }
                left=i;
            }
        }
        //2. 处理中间问题
        for (int i = maxIndexLeft; i <= maxIndexRight; i++) {
            totalTrap+=height[maxIndexLeft]-height[i];
        }
        //3. 处理右边问题
        right =height.length-1;
        // 3.1 跳过0起点
        while(height[right]==0) {
            right--;
        }
        for (int i = right-1; i >= maxIndexRight; i--) {
            if(height[i]<height[right]) {
                continue;
            }else {
                for(int j = right-1;j>i;j--) {
                    totalTrap+=height[right]-height[j];
                }
                right=i;
            }
        }
        return totalTrap;
    }
    public int findMaxLeft(int[] height) {
        int max = Integer.MIN_VALUE;
        int maxIndex =0;
        for (int i = 0; i < height.length; i++) {
            if(height[i]>max) {
                max=height[i];
                maxIndex=i;
            }
        }
        return maxIndex;
    }
    public int findMaxRight(int[] height) {
        int max = Integer.MIN_VALUE;
        int maxIndex =height.length-1;
        for (int i = height.length-1; i >=0; i--) {
            if(height[i]>max) {
                max=height[i];
                maxIndex=i;
            }
        }
        return maxIndex;
    }
```
