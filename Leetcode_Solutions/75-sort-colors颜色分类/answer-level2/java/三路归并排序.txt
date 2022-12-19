### 解题思路
此处撰写解题思路

### 代码

```java

//方法一：三路归并排序
class Solution {
    public void sortColors(int[] nums) {
        //三路归并
        //数组只有三种元素：0 1 2，0总是放在最前，2总是放在最后
        //所以我们只要将0和2的位置放对，那么整个数组自然就有序了
        //left 表示最左端0的位置，right表示最右端2的位置，curr则表示循环移动的索引
        //每次循环遇到0，则放到left位置，且left++
        //每次循环遇到2，则放到right位置，且right--
        //直至curr=right则停止循环。
        int left = 0;
        int curr = 0;
        int right = nums.length-1;
        int temp = 0;
        while(curr<=right){
            if(nums[curr]==0){
                temp = nums[left];
                nums[left++] = nums[curr];
                nums[curr++] = temp;
            }else if(nums[curr]==2){
                temp = nums[right];
                nums[right--] = nums[curr];
                nums[curr] = temp;
            }else{
                curr++;
            }
        }
    }
}

//方法二：暴力破解法 第一次遍历记录0,1,2的个数，第二次遍历将对应的元素放在对应的位置上
class Solution {
    public void sortColors(int[] nums) {
        int num1=0;
        int num2=0;
        int num0=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                num1++;
            }else if(nums[i]==0){
                num0++;
            }else{
                num2++;
            }
        }
        num1 = num0+num1;
        for(int i=0;i<nums.length;i++){
            if(i<num0){
                nums[i]=0;
            }else if(i<num1){
                nums[i]=1;
            }else{
                nums[i]=2;
            }
        }
    }
}