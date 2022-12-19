此题解法：在归并排序算法中增加一个计数方法。

计什么数？
计算区间和在[lower,upper]之间的区间个数

怎么计数？
归并排序的特点，数组被分为两半，左右两半分别有序
对于左边数组的每一个元素在右边数组中找到两个边界:low_bound和up_bound
low_bound是第一个使得区间和>=lower的位置
up_bound是第一个使得区间和>uper的位置

up_bound-low_bound就是区间和在[lower,uper]的区间个数


```
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int count=0;
        long []pre_sum=new long[nums.length];
        long sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            pre_sum[i]=sum;  // pre_sum[i]: nums[0:i]的和
        }
        count=merge_sort(pre_sum,0,nums.length-1,lower,upper);
        return count;
    }

    public int merge_sort(long []pre_sum,int left,int right,int lower,int upper){
        if(left>right)
            return 0;
        if(left==right){
            if(pre_sum[left]>=lower&&pre_sum[right]<=upper)
                return 1;
            else
                return 0;
        }
        int count=0;
        int mid=left+(right-left)/2;
        //System.out.println(left+"   "+right);
        count=merge_sort(pre_sum,left,mid,lower,upper)+merge_sort(pre_sum,mid+1,right,lower,upper);

        int low_bound=mid+1;
        int up_bound=mid+1;
       
        for(int i=left;i<=mid;i++){ // 计数
            while(low_bound<=right&&pre_sum[low_bound]-pre_sum[i]<lower) // 退出while后 low_bound是在右边数组中第一个使得pre_sum[low_bound] - pre_sum[i] >= lower的位置
                low_bound++;
            while(up_bound<=right&&pre_sum[up_bound]-pre_sum[i]<=upper) // up_bound是在右边数组中第一个使得pre_sum[up_bound] - pre_sum[i] >upper的位置
                up_bound++;
            
            count+=(up_bound-low_bound);
        }

        
        long []merged=new long[right-left+1];
        int l=left,r=mid+1;
        int index=0;
        while(l<=mid&&r<=right){   // 归并
            if(pre_sum[l]<=pre_sum[r])
                merged[index++]=pre_sum[l++];
            else
                merged[index++]=pre_sum[r++];
        }
        while(l<=mid)
            merged[index++]=pre_sum[l++];
        while(r<=right)
            merged[index++]=pre_sum[r++];
        
        System.arraycopy(merged,0,pre_sum,left,merged.length); // 辅助空间的数据复制到原数组中

        return count;
    }
}
```
