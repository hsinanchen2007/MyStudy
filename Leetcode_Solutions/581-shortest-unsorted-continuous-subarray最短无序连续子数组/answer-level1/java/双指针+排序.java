```java []
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] a=nums.clone();
        Arrays.sort(a);
        int i=0,j=nums.length-1;
        while(a[i]==nums[i]&&i<j){
            i++;
        }
        while(a[j]==nums[j]&&j>i){
            j--;
        }
        return j-i==0?0:j-i+1;

    }
}
```
