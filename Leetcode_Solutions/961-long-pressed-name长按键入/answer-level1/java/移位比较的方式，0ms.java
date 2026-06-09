### 解题思路
- 没有思路，凑出来的

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
         char[] names = name.toCharArray();
        char[] types = typed.toCharArray();
        int indexName = 0, indexType = 0;
        while (indexName <names.length && indexType < types.length && names[indexName] == types[indexType]) {
            indexType++;
            // 真正名字内没有重复字符串
            if(indexName <names.length-1 && names[indexName] != names[indexName+1]) {
                while (indexType < types.length && names[indexName] == types[indexType]) {
                    indexType++;
                }
            }

            indexName++;
        }

        return indexName == name.length();
    }
}
```