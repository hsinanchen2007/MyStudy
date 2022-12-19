### 解题思路
此处撰写解题思路
估计是最笨的了
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for (int i = 0; i < astr.length(); i++) {
            for (int i1 = i+1; i1 < astr.length(); i1++) {
                if(astr.codePointAt(i)==astr.codePointAt(i1))
                {
                    return false;
                }
            }
        }
        return true;
    } 
}

```