### 解题思路
因为Set中，相同值的元素只会存储一个，所以创建一个set存储nums1中的元素(此时set中以去重)，遍历数组二的元素，如果有与集合中相同的元素，将此元素存入ArrayList中，**并且删除集合中的该元素**，防止数组二中有重复匹配的元素。

### 代码

```java
import java.util.ArrayList;
import java.util.TreeSet;
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        
        TreeSet<Integer> set = new TreeSet<>();
        for(int num:nums1){
            set.add(num);
        }

        ArrayList<Integer> list = new ArrayList<>();
        for(int num:nums2){
            if(set.contains(num))
                list.add(num);
                set.remove(num);  //将集合中该元素删去，即使再遍历到nums2中同样的元素，也将忽略！
        }
        int[] res = new int[list.size()];
        for(int i = 0; i < list.size(); i ++)
            res[i] = list.get(i);
        return res;

        
    }
}
```