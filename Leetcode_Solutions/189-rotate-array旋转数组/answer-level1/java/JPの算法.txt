微博：@带带大师兄

nums = [1,2,3,4,5,6]   k = 2   只写两种思路吧

第一种思路：对于1来说，1->3,3->5,5->1，一定会回到起始点。每个元素都向后替换元素，直到回到起始点结束替换。同时记录替换次数，避免多次替换。
```
class Solution {
    public void rotate(int[] nums, int k) {
        k = k%nums.length;
        //记录是否每个元素被遍历完
        int count = 0;
        for(int i=0;count<nums.length;i++){
            //保存前一个数的值
            int pre = nums[i];
            //保存当前进行
            int current = i;
            do {
                int next = (current+k)%nums.length;
                int temp = nums[next];
                nums[next] = pre;
                pre = temp;
                current = next;
                count++;
            }
            //该点全部遍历完
            while (i!=current);
        }
    }
}
```

第二种思路：三次翻转嘛，第一次整体翻转，第二次0到k-1，第三次k到结尾
```
class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length-1;
        k = k%nums.length;
        //整体翻转
        rev(nums,0,len);
        //前半部分
        rev(nums,0,k-1);
        //后半部分
        rev(nums,k,len);
    }

    public void rev(int[] nums,int start,int end){
        while(start<end){
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
}
```

