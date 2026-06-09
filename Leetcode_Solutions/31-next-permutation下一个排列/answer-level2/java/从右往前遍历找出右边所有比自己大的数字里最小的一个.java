### 解题思路
从右往左遍历，每次都是比较当前索引位置curIndex和它右边所有的索引，选择其中值比当前大同时是所有右边索引里最小的一个，然后跟当前位置交换；然后把当前索引curIndex后面的数字进行升序排序即可。 如果遍历到第一位也没有发现比当前大的，说明数组本身就是降序排列，直接改成升序即可。

### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {

        boolean hasSwap = false;
        
        for(int i=nums.length-1;i>=0;i--) {
             int last = nums.length-1;
             int temp=nums[i],tempIndex=i;
             while (last>i) {
                 if(nums[last]>nums[i]) {
                     hasSwap = true;
                     if( temp==nums[i]) { //第一次遇到比i自己大的
                         temp = nums[last];
                         tempIndex=last;
                     } else { //否则选择小的来交换
                         if(nums[last]<temp) {
                             temp = nums[last];
                             tempIndex = last;
                         }
                     }
                    
                 }
                 last--;
             }
            if(hasSwap) {
                 //todo 
                swapNums(i,tempIndex,nums);
                Arrays.sort(nums,i+1,nums.length);
                break;
            }
        }
        if(!hasSwap) {//如果没交换，说明是纯降序列，把数组改为升序
            Arrays.sort(nums);
        }
    }
    
    public void swapNums(int i,int j,int nums[]) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
```