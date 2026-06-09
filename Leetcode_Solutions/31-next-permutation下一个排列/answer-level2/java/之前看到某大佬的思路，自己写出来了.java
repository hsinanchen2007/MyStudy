### 解题思路
从后往前，找到第一个升序点，那么这个升序点之后的点都是降序的，只需要把降序的部分中比升序点大的较小数和升序点交换即可，然后再把交换点后面的部分全变成升序就可以了。

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        int end=nums.length;
        if(end==1){
            return;
        }
        int i=end-2,j=end-1,k=end-1;
        while(i>=0){
            int first=nums[i];
            int second=nums[j];
            if(first>=second){
                i--;j--;
            }else{
                break;
            }
        }
       
        while(k>=j&&i>-1){
            if(nums[k]>nums[i]){
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=temp;
                break;
            }else{
                k--;
            }
        }
        Arrays.sort(nums,j,end);
    }
}
```