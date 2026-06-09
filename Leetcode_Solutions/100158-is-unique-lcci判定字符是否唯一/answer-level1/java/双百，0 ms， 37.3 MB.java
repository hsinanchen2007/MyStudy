### 解题思路
创建一个新串，查询新串中是否包含原串中的字符，如果包含则返回false。
满足限制加分项，不使用其他数据结构。
利用StringBuilder可以节约内存。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if(astr == null)
            return true;
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<astr.length(); i++){
            int index = sb.indexOf(String.valueOf(astr.charAt(i)));
            if(index != -1)
                return false;
            sb.append(astr.charAt(i));
        }
        return true;
    }
}
```