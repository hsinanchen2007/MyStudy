### 解题思路
此处撰写解题思路

### 代码
```java
class Solution {
    /**
      判断是否出现重复元素其实就是查找,某个元素是否存在于该集合中,
      使用散列表思想查找某个元素时间复杂度O(1)
      由于不是计算某个元素出现的次数,可以使用Set替代HashMap,节省存储空间
    */
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> map=new HashSet<>();
        for(int num:nums){
           if(map.contains(num)){
               return true;
           }
           map.add(num);
        }
        return false;
    }
    打家不要被提交的时间所误解,其实在数据量不大的时候,使用嵌套的for循环可能也比散列表快,
    测试的数据量稍微大了一点,效果会更加明显
}
```