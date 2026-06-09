### 解题思路
直接用jdk8的lambda排序比较厚拼接 ，没什么好说的。。。

### 代码

```java
class Solution {

    /**
    * 直接用jdk8的lambda排序比较厚拼接 ，没什么好说的。。。
    **/
    public String minNumber(int[] nums) {
        List<String> list = new ArrayList<>(10);
        for (int i = 0, len = nums.length; i < len; i++) {
            list.add(String.valueOf(nums[i]));
        }
        
        StringBuilder result = new StringBuilder();
        list.stream().sorted((o1, o2) -> (o1 + o2).compareTo(o2 + o1)).forEach(result::append);
        return result.toString();
    }
}
```