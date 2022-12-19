### 解题思路
我今年九月校招要是面试有这种题目怕是做梦都会笑醒，然后人家只会盯着数据结构和算法问，哎。。。

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int[] arr = new int[26];
        char[] brr = astr.toCharArray();
        for(int i = 0;i<brr.length;i++) {
            arr[brr[i]-'a']++;
        }
        for(int i = 0;i<arr.length;i++) {
            if(arr[i]>1) return false;
        }
        return true;
    }
}
```