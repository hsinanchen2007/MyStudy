### 解题思路
此处撰写解题思路  先排序后又转化回来判断字符串就行

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        boolean flag = false;
        if (s1.length()!=s2.length()){
            return false;
        }else {

            char[] str = s1.toCharArray();
            char[] str2 = s2.toCharArray();
            Arrays.sort(str);
            Arrays.sort(str2);
            s1 = new String(str);
            s2= new String(str2);
            if (s1.equals(s2)){
                flag = true;
            }
        }
        return flag;
    }
}
```