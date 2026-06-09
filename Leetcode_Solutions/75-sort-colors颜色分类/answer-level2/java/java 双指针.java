### 解题思路
1、定义三个指针p0 cur p2
      分别代表指向0 指向当前元素  指向2
     保证nums[idx<p0] = 0 nums[idx>p2] = 2
 2、开始的时候p0 cur 都初始化为索引0  p2 指向nums.length-1
      while(cur<=p2){
        //如果nums[cur]=0 
       将cur与p0的值交换，并且cur+1 p0+1
       //如果nums[cur]=2
        将cur与p2的值交换，同时p2-1
      //注意这里cur不能+1，否则不能保证nums[idx>p2]=2,因为有可能从p2 交换过来的元素也是2.
      //如果nums[cur]=1  则cur+1
     }
      

### 代码

```java
class Solution {

    private void swap(int[] nums,int p0,int p1){
        int tmp = nums[p0];
        nums[p0] = nums[p1];
        nums[p1] = tmp;
    }

    public void sortColors(int[] nums) {
          int p0  =0 ,cur = 0, p2 = nums.length - 1;
        while(cur<=p2){
            if(nums[cur]==0){
                //将cur与p0进行交换
                swap(nums,p0,cur);
                p0++;
                cur++;
            }else if(nums[cur]==2){
                swap(nums,p2,cur);
                p2--;
            }else{
                cur++;
            }

        }
    }
}
```