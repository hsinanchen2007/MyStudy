### 重复元素，请考虑set！！！
### set作用：1.是否包含某个元素。2.去重！

### 代码

```java
class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> res=new HashSet<>();
        for(int num:nums) res.add(num);
        return res.size()==nums.length?false:true;

    }
}
```