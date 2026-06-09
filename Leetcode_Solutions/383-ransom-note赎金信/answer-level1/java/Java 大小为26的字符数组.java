### 解题思路

![IMG_0457.PNG](https://pic.leetcode-cn.com/355ad08e8e00d89555954a6bc98ae347d4f5bf272a13d47b8b941d2731a92d6f-IMG_0457.PNG)


### 代码

```java
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int a[] = new int[26];
        char ran[] = ransomNote.toCharArray();
        char maga[] = magazine.toCharArray();
        for(char c:ran) {
        	a[c-'a']++;
        }
        for(char c:maga) {
        	a[c-'a']--;
        }
        for(int c:a) {
        	if(c>0) return false;
        }
        return true;
    }
}
```