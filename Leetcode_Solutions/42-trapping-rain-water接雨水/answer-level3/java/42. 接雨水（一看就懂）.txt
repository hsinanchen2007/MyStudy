### 解题思路
对于此高度数组，忽略最左和最右两个高度，因为不能存水。分别求第i个高度最左最右的最大值，根据木桶原理求出最小值和第i高的差值，这个差值就是第i高能存水的数量。

### 暴力法
O(n*n)，对于每个i都遍历左右所有高度

```java
class Solution {
    public int trap(int[] height) {
        int sum=0;
        int l=height.length;
        for(int i=1;i<l-1;i++){
            int left=0,right=0;
            for(int j=i;j>=0;j--){
                left=Math.max(left,height[j]);
            }
            for(int j=i;j<l;j++){
                right=Math.max(right,height[j]);
            }
            sum+=Math.min(left,right)-height[i];
        }
        return sum;
    }
}
```
### 动态规划
O(n)，先遍历一次每个高度左右的最高值且存在数组中，后续直接使用即可，牺牲了空间复杂度
```
class Solution {
    public int trap(int[] height) {
        int sum=0;
        int l=height.length;
        if(l==0)return 0;
        int[] left=new int[l];
        int[] right=new int[l];
        left[0]=height[0];
        for(int i=1;i<l;i++){
            left[i]=Math.max(left[i-1],height[i]);
        }
        right[l-1]=height[l-1];
        for(int i=l-2;i>=0;i--){
            right[i]=Math.max(right[i+1],height[i]);
        }
        for(int i=1;i<l-1;i++){
            sum+=Math.min(left[i],right[i])-height[i];
        }
        return sum;
    }
}
```
