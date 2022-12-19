
```java
class Solution {//self：7ms 89%

    public void wiggleSort(int[] nums) {
        int len=nums.length;
        int copy[]=Arrays.copyOf(nums,len);
        Arrays.sort(copy);
        int mid=len/2;
        if((len&1)==0)mid--;
        for(int i=len-1;i>mid;i--){
            nums[2*(len-i-1)+1]=copy[i];
        }
        for(int i=mid;i>=0;i--){
            nums[2*(mid-i)]=copy[i];
        }
    }
}
/*
                  |
                | |
              | | |
            | | | |
          | | | | |
        | | | | | |
      | | | | | | |
    | | | | | | | |想象一下，往中间翻折，交叉插入，一定可以构成 摆动序列；
*/ 
```
