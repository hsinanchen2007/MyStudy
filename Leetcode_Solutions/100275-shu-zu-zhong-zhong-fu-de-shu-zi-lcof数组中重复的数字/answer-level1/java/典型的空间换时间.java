### 解题思路
此处撰写解题思路
典型的空间换时间
### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] arr = new int[nums.length];

        for(int i = 0; i < arr.length; i++){
            arr[i] = 0;
        }

       for(int i = 0; i < nums.length; i++){
            arr[nums[i]]++;
        }

        for(int i = 0; i < arr.length ; i++){
            if(arr[i] > 1){
                return i;
            }
        }

        return -1;


    }
}
```