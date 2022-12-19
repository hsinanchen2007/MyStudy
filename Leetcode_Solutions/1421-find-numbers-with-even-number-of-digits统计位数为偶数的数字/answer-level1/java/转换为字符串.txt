### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
     String []num=new String[nums.length];
     int count=0;
     for(int i=0;i<nums.length;i++){
         num[i]=""+nums[i];
     }
     for(int i=0;i<num.length;i++){
         if(num[i].length()%2==0)
         count++;
     }
     return count;
    }
}
```