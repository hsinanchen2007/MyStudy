### 解题思路
这题可以用小顶堆来做，官方题解1已经说的很清楚了，这里我用自己思路实现了一下快速选择算法（注意**不是**快速排序算法！！）。
官方用的递归不太好理解，我这里就用很简单的思路。我用goodnotes画了一张图方便大家理解。
![IMG_0024.jpg](https://pic.leetcode-cn.com/6e4025bb0218a1451bafa184d590c32b2bc00bbda51bdaa70f178d790236f8e3-IMG_0024.jpg)


### 代码

```java
class Solution {

    public void swap(int[] nums,int i,int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;

    }

    public int quick_selection(int start,int end,int[] nums) {
        int i = start;
        int j = end;
        int pivot = i;
        boolean to_left = true;

        while(i<j) {
            // System.out.println(pivot);
            if(to_left) {
                if(nums[pivot]>nums[j]) {
                    swap(nums,pivot,j);
                    pivot = j;
                    ++i;
                    to_left = false;
                } else{
                    --j;
                }
            }else {
                if(nums[i]>nums[pivot]) {
                    swap(nums,pivot,i);
                    pivot = i;
                    --j;
                    to_left = true;
                } else{
                    ++i;
                }
            }
        }
        return pivot;
    }

    public int findKthLargest(int[] nums, int k) {
        int pivot = -1;
        int start = 0;
        int end = nums.length -1;
        k = nums.length -k;
        while(pivot != k){
            if(pivot <k) {
                pivot = quick_selection(pivot+1,end,nums);
            }else{
                pivot = quick_selection(start,pivot-1,nums);
            } 
        }
        // System.out.println("======k=");
        // System.out.println(k);
        // System.out.println("======");
        // // System.out.println(pivot);
        
        // // System.out.println(nums);
        // for(int num:nums) {
        //     System.out.println(num);
        // }
        return nums[pivot];
    }
}
```