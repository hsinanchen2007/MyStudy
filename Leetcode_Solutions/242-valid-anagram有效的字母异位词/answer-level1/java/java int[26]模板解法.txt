### 解题思路
凡是查找字符出现次数的都可以用 int[26]来解决。
1. 找到两个字符串，每个字符出现的次数，用两个数组储存值。
2. 遍历数组，如果出现的次数不一致，就位false。

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] nums1 = new int[26];
        int[] nums2 = new int[26];
        
        for (char a:s.toCharArray()){
            nums1[a-'a']++;
        }

        for (char a:t.toCharArray()){
            nums2[a-'a']++;
        }

        for (int i= 0 ; i < nums1.length; i++){
            if (nums1[i] != nums2[i]){
                return false;
            }
        }
        return true;
    }
}
```