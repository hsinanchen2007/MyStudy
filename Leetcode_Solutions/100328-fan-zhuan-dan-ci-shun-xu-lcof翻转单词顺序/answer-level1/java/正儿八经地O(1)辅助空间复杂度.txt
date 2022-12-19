从String得到的原数组，不计算为占用空间。

```
class Solution {
    public String reverseWords(String s) {
        if (s == null) return s;
        
        int len = 0;
        char[] arr = new char[s.length()];
        int i = 0, j = s.length() - 1;
        while (i < s.length() && s.charAt(i) == ' ') i++; // 去掉前面多余的空格
        while (j > i && s.charAt(j) == ' ') j--; // 去掉后面多余的空格
        
        int start = 0;
        for (; i <= j; ++i) {
            if (i > 0 && s.charAt(i-1) == ' ' && s.charAt(i) == ' ') continue; //去掉中间多余的空格
            arr[start++] = s.charAt(i);
            len++; // calculate the real length.
        }
        
        // 将整个字符数组倒序
        reverse(arr, 0, len - 1);
        
        // 再倒序数组中的单个单词
        start = 0;
        for (int k = start + 1; k < len; ++k) {
            if (arr[k] == ' ') {
                reverse(arr, start, k - 1);
                start = k + 1;
            } else if (k == len - 1) {
                reverse(arr, start, k);
            }
        }
        
        return new String(arr, 0, len);
    }
    
    private void reverse(char[] arr, int l, int r) {
        while (l < r) {
            char tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            
            l++;
            r--;
        }
    }
}
```

这题从难度上来说，我觉得应该也是中等！！！！！