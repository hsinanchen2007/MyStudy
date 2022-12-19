### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    int[] nums;
    public int[] exchange(int[] nums) {
        this.nums = nums;
       quickSort(nums,0,nums.length-1);
       return nums;
    }
    void quickSort(int[] nums,int left,int right){
        //如果left等于right，即数组只有一个元素，直接返回
        if(left>=right) {
            return;
        }
        //设置最左边的元素为基准值
        // int key=num[left];
        //数组中比key小的放在左边，比key大的放在右边，key值下标为i
        int i=left;
        int j=right;
        while(i!=j){
            //j向左移，直到遇到奇数
            while(nums[j]%2==0 && i<j){
                j--;
            }
            //i向右移，直到遇到偶数
            while(nums[i]%2==1 && i<j){
                i++;
            }
            //i和j指向的元素交换
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
        }
        // num[left]=num[i];
        // num[i]=key;
        quickSort(nums,++i,--j);
        
    }

}
```