### 解题思路
此处撰写解题思路
滑动窗口，在每一个窗口中找出max值。
注意点：
1.返回数组的长度是可以确定的:nums.length-k+1 
2.JDK中整型范围-2147483648～2147483647  （ -2^31 --- 2^31-1）Integer.MIN_VALUE为-2147483648，Integer.MAX_VALUE即2147483647
3.先单独返回数组为空，k=0，因为后续的方法不囊括此种情况。
### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length==0||k==0) return new int[0];
        int[] res=new int[nums.length-k+1];
        int i=0,j=k-1,n=0;
        while(j<=nums.length-1){
            int max=Integer.MIN_VALUE;
            for(int count=i;count<=j;count++){
                max=Math.max(nums[count],max);
            }
            res[n++]=max;
            i++;
            j++;

        }
        return res;


    }
}
```