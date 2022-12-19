### 解题思路
1,首先将字符串转成数组，然后进行排序
2，将排序之后的字符串逐次比较即可

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        char[] charArrS1 = s1.toCharArray();
        char[] charArrS2 = s2.toCharArray();
        Arrays.sort(charArrS1);
        Arrays.sort(charArrS2);
        if (Arrays.equals(charArrS1, charArrS2)){
            return true;
        }
        return false;
    }
}
```