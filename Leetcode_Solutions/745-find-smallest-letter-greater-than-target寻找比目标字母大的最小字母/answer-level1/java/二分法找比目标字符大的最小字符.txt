### 解题思路
此处撰写解题思路
主体逻辑是用二分法，
注意点1、但是因为是数组，加入mid跑到了最后一位，返回的letters[l]就会越界
注意点2、还有就是因为循环数组，最后一位不匹配，就返回第一位letters[0]
### 代码

```java
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int l = 0;
        int r = letters.length - 1;
        while (l <= r){
            int mid = l + (r -l) / 2;
            if (letters[mid] <= target) {
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        //因为是循环数组
        return l < letters.length ? letters[l] : letters[0];
    }
}
```