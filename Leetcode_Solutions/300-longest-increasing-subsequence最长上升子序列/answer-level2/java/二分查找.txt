```
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;

        if(n<=1) return n;
        int len = 0;
        //也可以不定义t数组，直接在nums上变动
        int[] t = new int[n];
        t[0]=nums[0];

        for (int i=1; i<n; i++){
            //如果nums[i]比t数组中的最大的数t[len]大(t数组中元素递增),直接添加入t数组
            if(nums[i]>t[len]){
                len++;
                t[len]=nums[i];
            }else {
                /*二分查找到t数组中比nums[i]大的最小数,nums[i]替换该数
                举一个例子来说明替换的目的：[1,3,6,9,4,5,6]
                如果不替换最终t数组为[1,3,6,9]->return 4
                替换后为：[1,3,4,5,6]->return 5
                虽然替换后的结果不一定是最终结果
                如[1,3,6,9,4,5,6,2]->[1,2,4,5,6],但是不影响原递增数组t的长度
                */
                int low = 0, high = len;
                while (low<high){
                    int mid = low + (high-low>>1);
                    if(t[mid]<nums[i]){
                        low = mid+1;
                    }else {
                        high=mid;
                    }
                }
                t[low]=nums[i];
            }
            /*for (int j=0; j<=len; j++){            
                System.out.print(t[j]+" ");        
            }
            System.out.println();
            */
            
        }
        return len+1;
    }
}
```
