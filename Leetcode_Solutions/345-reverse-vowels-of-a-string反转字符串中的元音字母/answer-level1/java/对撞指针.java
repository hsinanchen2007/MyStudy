### 解题思路
对撞指针，遇到元音交换，非元音跳过

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        
        char[] chars = s.toCharArray();
        int l = 0;
        int r = chars.length - 1;
        while (l < r) {
            boolean bl = chars[l] == 'a' || chars[l] == 'o' || chars[l] == 'e'
                    || chars[l] == 'i' || chars[l] == 'u' || chars[l] == 'A'
                    || chars[l] == 'O' || chars[l] == 'E' || chars[l] == 'I'
                    || chars[l] == 'U';
            boolean br = chars[r] == 'a' || chars[r] == 'o' || chars[r] == 'e'
                    || chars[r] == 'i' || chars[r] == 'u' || chars[r] == 'A'
                    || chars[r] == 'O' || chars[r] == 'E' || chars[r] == 'I'
                    || chars[r] == 'U';
            if (bl && br) {
                swap(chars, l, r);
                l++;
                r--;
            }
            if (!bl) l++;
            if (!br) r--;
        }
        return new String(chars);

    }

    private void swap(char[] nums, int index1, int index2) {
        char temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
    
}
```