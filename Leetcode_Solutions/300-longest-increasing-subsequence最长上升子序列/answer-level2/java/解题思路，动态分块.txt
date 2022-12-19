### 解题思路
此处撰写解题思路
1.首先判断数组大小，如果小于2，直接返回相关值
2.开辟一个和原数组一样大小的新数组，用来存储当前位置对应的最长递增长度
3.从第1位开始，依次循环
    依次取当前位置前面的比当前值小的位置对应的最长递增长度+1
    给新数组对应的位置赋值（存储当前位置对应的最大值）
    比较最大值与当前位置对应的最大值，取二者最大值，赋值给maxLen
### 代码

```java
class Solution {
    public static int lengthOfLIS(int[] nums) {
        if (nums.length < 2){
            return nums.length== 0 ? 0 : 1;
        }
        int[] len = new int[nums.length];
        len[0] = 1;
        int maxLen = 1;
        for(int i = 1;i < nums.length; i++){
            int base = nums[i];
            int tmpIndex = i;
            int vm = 1;
            while(tmpIndex>0){
                if(nums[tmpIndex-1]<base){
                    vm = Math.max(len[tmpIndex-1]+1,vm);
                }
                tmpIndex--;
            }
            len[i] = vm;
            if (len[i]>maxLen){
                maxLen = len[i];
            }
        }
        return maxLen;
    }
}
```