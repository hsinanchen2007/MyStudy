### 解题思路
* 排序
* 学习一个数组是否相等的API：Arrays.equals(ary1,ary2);
### 踩坑加学习
* 一开始想到了排序，排序之后生成字符串进行了比较，但是因为没考虑边界条件以为出错了，所以各种思考
* 最后不用String.valueOf生成排序后的字符串，直接Arrays.equals完成任务，绝妙，学习了。
### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length() != t.length()) {
            return false;
        };
        if(s.equals(t)) {
            return true;
        }
        char[] chs = s.toCharArray();
        char[] cht = t.toCharArray();
        Arrays.sort(chs);
        Arrays.sort(cht);
       return Arrays.equals(chs,cht);
    }
}
```