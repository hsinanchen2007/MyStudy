### 解题思路
此处撰写解题思路
按照ascll字符，有256，创建一个new int[256]数组，遍历字符串，在数组中，数组的下标对应的就是字符对应的ascll码，在对应位置进行++操作，最后再遍历一次字符串，将字符转为下标到数组查询若果为1索命第一次出现，饭后，如果没有则返回空格
### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        int[] arr = new int[256];
        int count = 1;
        for(int i = 0; i < s.length(); i++){
            int c = (int)s.charAt(i);
            arr[c] += 1;
        }
        for (int i = 0; i < s.length(); i++){
            if (arr[(int)s.charAt(i)] == 1)
               return s.charAt(i);

        }
        return ' ';
    }
}
```