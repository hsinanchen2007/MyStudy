### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
         int l=0,r=height.length-1;
        int maxl=0,maxr=0;
        int rain=0;
        while(l<=r){
            //例如： {0,7,1,4,6}; maxl=7,maxr=6
            //这种情况下，就回走else，把maxl右边都便利一遍，把水池都算出来
            //万一出血maxr比maxl大，比如： 0,7,1,1,8,1,4,6
            //因为是右边一直往左边遍历，所以是右边走到8到，所以maxr=8，这样会把刚才maxl，从左往右便利，计算水池。这方法debug之后觉得太牛逼了
            if(maxl<maxr){
                if(maxl>height[l]) rain += maxl - height[l];
                else maxl = height[l];
                l++;
            }else{
                if(maxr>height[r]) rain += maxr-height[r];
                else maxr = height[r];
                r--;
            }
        }
        return rain;
    }


     
}
```
思路全写在注解上，真的理解了一下这个双指针，感觉太牛逼了。世界复杂度上O(n)