### 解题思路
此处撰写解题思路
我的思想:
    用了一种很笨的方法，将数组里面的内容转换成字符串，然后再判断字符串的长度是否能够被2整出，如果可以说明这个是对的，统计起来，返回！；
### 代码

```java
class Solution {
    public int findNumbers(int[] nums) {
        int len=0;
        int k=0;
        for(int i=0;i<nums.length;i++){
           String str=String.valueOf(nums[i]);
           if(str.length()%2==0){
               len++;
           }
        }
        return len;
    }
}
```