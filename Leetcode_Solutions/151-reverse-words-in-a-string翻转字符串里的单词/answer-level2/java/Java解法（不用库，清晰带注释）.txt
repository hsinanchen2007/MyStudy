**分为三部分**

**1. 翻转字符数组**
**2. 翻转每个单词**
**3. 去除前后空格**


```
class Solution {
    public String reverseWords(String s) {
        if(s == null) return null;
        char[] arr_s = s.toCharArray();
        int n = arr_s.length;

        // 翻转整个数组
        reverse(arr_s,0,n-1);
        // 翻转每个单词
        word_reverse(arr_s,n);
        // 去除多余空格
        return clean_space(arr_s,n);
    }

    private void reverse(char[] arr_s,int i,int j){
        while (i < j){
            // 交换前后单词顺序
            char t = arr_s[i];
            arr_s[i++] = arr_s[j];
            arr_s[j--] = t;
        }
    }

    private void word_reverse(char[] arr_s, int n) {
        int i = 0;
        int j = 0;
        while (j < n) {
            // 找到第一个首字母
            while (i < n && arr_s[i] == ' ') {
                i++;
            }
            j = i;
            // 末位置
            while (j < n && arr_s[j] != ' ') {
                j++;
            }
            reverse(arr_s, i, j - 1);
            i = j;
        }
    }

    // 双指针去掉空格
    private String clean_space(char[] arr_s,int n){
        int i = 0;
        int j = 0;
        while(j < n){
            while (j < n && arr_s[j] == ' ') j++;
            while (j < n && arr_s[j] != ' ') arr_s[i++] = arr_s[j++];
            // 单词结束还需要去除后面空格
            while (j < n && arr_s[j] == ' ') j++;
            if (j < n) arr_s[i++] = ' ';      
        }
        return new String(arr_s).substring(0,i);
    }
}
```

时间复杂度：若数组长度为k,单词长度为N --> O(Nk) -->O(n)
空间复杂度：需要一个长度为n的字符数组 --> O(n)