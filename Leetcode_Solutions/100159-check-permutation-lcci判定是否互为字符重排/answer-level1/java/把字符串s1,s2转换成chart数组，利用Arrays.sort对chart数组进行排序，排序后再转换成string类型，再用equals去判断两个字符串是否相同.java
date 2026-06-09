### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public  boolean CheckPermutation(String s1, String s2) {
        if (s1.length()!=s2.length()){
            //长度不同，直接返回false
            return false;
        }else {
            //把字符串s1,s2转换成char数组
            char[] c1 = s1.toCharArray();
            char[] c2 = s2.toCharArray();
            //利用Arrays.sort()对chart数组的排序特点，对数组进行排序
            Arrays.sort(c1);
            Arrays.sort(c2);
            //把char类型转换成string类型才能用equals方法进行比对
            return new String(c1).equals(new String(c2));
        }
    }
}
```