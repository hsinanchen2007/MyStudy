### 解题思路
此处撰写解题思路

### 代码

```java

class Solution {
    public boolean isStraight(int[] nums) {
        int[] arr =new int[14];

        //把每个数放进桶里（桶排序思想）,以便找出最大最小值
        for(int i = 0 ; i <5; i++){
            arr[nums[i]]++;
            //如果有非零重复数则报错
            if(nums[i]!=0 &&arr[nums[i]] >1){
                return false;
            }
        }

        int min = -1; 
        int max = 14;
        //找出最小数，从1开始
        for(int i = 1 ; i < 14; i++){
            if(arr[i] == 1){
                min = i;
                break;
            }
        }

        //找出最大数
        for(int i = 13 ; i >0; i--){
            if(arr[i] == 1){
                max = i;
                break;
            }
        }
        
        return max - min <=4;
    }
}
```