### 解题思路
快速排序的演变:把1当做标准,遇到0就排前面,遇到2就排后面

### 代码

```java
class Solution {
    public void sortColors(int[] nums) {
        int one=0;//记录1的最后一个位置
        int zero=0;//记录0的最后一个位置
        int two=nums.length-1;//记录2的第一个位置
        while(one<=two){//注意结束条件 必须有"="
            if(nums[one]==0){
                swap(nums,one,zero);
                zero++;
                one++;
                continue;
            }
            if(nums[one]==1){
                one++;
                continue;
            }
            if(nums[one]==2){
                swap(nums,one,two);
                two--;
                continue;
            }
        }
    }
    public void swap(int[] nums,int i,int j){
        int tem=nums[i];
        nums[i]=nums[j];
        nums[j]=tem;
    }
}
```