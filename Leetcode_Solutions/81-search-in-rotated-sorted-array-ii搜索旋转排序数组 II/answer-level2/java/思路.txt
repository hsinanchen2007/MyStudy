### 解题思路
此处撰写解题思路
我的思路:
    返回的类型是布尔类型，那就创建一个布尔类型的变量，然后通过遍历数组的元素，
判断数组的元素是否等于target，如果是相等的话那就直接返回true，如果循环都遍历完了，那就是没有找到
没找的话就直接返回false;
### 代码

```java
class Solution {
    public boolean search(int[] nums, int target) {
        boolean flag=false;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
}
```