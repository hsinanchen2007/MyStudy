### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int length=0,trage=0;
        for(int i=0;i<nums.length;i=i+2){
length=length+nums[i];
        }
        int[] array=new int[length];
        for(int i=0;i<nums.length;i=i+2){
for(int j=nums[i];j!=0;j--){
    array[trage]=nums[i+1];
    trage++;
}
        }
        return array;
    }
}
```