![question.png](https://pic.leetcode-cn.com/c2fce92b1feb3d9f85bac001da019da9ad0960b2335c99397ad9786ab7752e3b-question.png)

解题思想：这个题我们可以利用局部性最佳原理，将整个数组从最左边和最右边同时比较开始，

在左半区内，水量为左边局部最大-当前深度，比如在题目给出的测试用例中
1-0 = 1,2-1=1，2-0=2,2-1=1
在右半区内，水量为右边局部最大-当前深度，比如在题目给出的测试用例中
2-1=1
所以测试用例总共可以接的雨水就是1 + 1 + 2 + 1 + 1 = 6
```java
class Solution {
    public int trap(int[] height) {
        if(height.length<=1)return 0;
        int res=0;
        int left=0;
        int right=height.length-1;
        int lmax=height[left];
        int rmax=height[right];
        //假设成山状态，中间最大值，
        while(left<right){
            if(height[left]<height[right]){
                //左半区，水量=左边局部最大-当前深度
                if(height[left]>=lmax)
                    lmax=height[left];
                else
                    res+=lmax-height[left];
                left++;
            }else{
                //右半区同理
                if(height[right]>=rmax)
                    rmax=height[right];
                else    
                    res+=rmax-height[right];
                right--;
            }
            
           
        }
        
        return res;

    }
}

```
这个代码不是本人想出来的，是我借鉴的，但是现在找不到原出处了，不过这个还是挺浅显易懂的