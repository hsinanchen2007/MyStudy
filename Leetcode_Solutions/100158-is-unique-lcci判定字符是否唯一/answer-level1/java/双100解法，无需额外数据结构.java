### 解题思路
不使用额外的数据结构，所以排除map、set等，所以还是遍历字符
结合lastIndexOf来判断是否存在多个相同字符

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for(int i = 0; i < astr.length() ; i++){
            if(i!=astr.lastIndexOf(astr.charAt(i))){
                return false;
            }
        }
        return true;
    }
}
```