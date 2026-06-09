### 解题思路
此处撰写解题思路
Set特点 不可重复 利用set去重 判断长度
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        Set set = new HashSet();
        int len = astr.length();
        for(int i=0;i<len;i++){
            set.add(astr.charAt(i));
        }
        return set.size() == len;
    }
}
```