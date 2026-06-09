### 解题思路
此题考查排序算法
lowB三人组 冒泡 插入和选择会超时
所以要用归并、堆排、快排

这里改造了计数排序，用一个数组存负数 一个数组存正数（含0）
执行用时 :2 ms, 在所有 Java 提交中击败了100.00%
的用户
### 代码

```java
class Solution {
    public int[] sortArray(int[] nums) {
        /**Arrays.sort(nums);
        return  nums;**/
        return doCntSort(nums);
    }
    
    /**
    **插入排序超时
    **/
    private int[] doInsertSort(int[] nums){
        if(null==nums||nums.length==0) return nums;
        for(int i=1;i<nums.length;i++){
            if(nums[i]<nums[i-1]){
                int temp=nums[i];
                int p=i;
                while(p>0&&temp<nums[p-1]){
                    nums[p]=nums[p-1];
                    --p;
                    
                }
                nums[p]=temp;
            }
        }
        return nums;
    }
    /**
    **计数排序
    **这里改造了计数排序，用一个数组存负数 一个数组存正数（含0）
    **/
    private int[] doCntSort(int[] nums){
        int max=nums[0];
        int min=0;
        for(int i:nums){
            max=Math.max(max,i);
            min=Math.min(min,i);
        }
        int[] arr=new int[max+1];
        int[] arrMinus=new int[Math.abs(min)+1];
        for(int i:nums){
            if(i>=0){
                arr[i]+=1;
            }else{
                arrMinus[Math.abs(i)]+=1;
            }
        }
        int pm=0;
        for(int i=arrMinus.length-1;i>=0;i--){
            
            while(arrMinus[i]>0){
                nums[pm++]=-i;
                arrMinus[i]--;
            }
        }
        int p=0;
        
        for(int i=0;i<arr.length;i++){
            
            while(arr[i]>0){
                nums[pm+p++]=i;
                arr[i]--;
            }
        }
        return nums;
    }
}
```