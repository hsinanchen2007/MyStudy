![WX20200323-021240@2x.png](https://pic.leetcode-cn.com/177178e476c2f787db39aee88569bf488a34e5e257f5bbd5c73fb794d89d91ef-WX20200323-021240@2x.png)

# 思路
简单来说就是把字符串转换成char数组，定位每一个单词，然后reverse每个单词。

时间复杂度O(n) 虽然有两层while，但只遍历了一遍。
空间复杂度O(n)

```
class Solution {
    public String reverseWords(String s) {
        char[] sentence = s.toCharArray();
        int i = 0, j = 0;
        while(j < sentence.length) {
            while(i < sentence.length && sentence[i] == ' ') ++i;
            while(j < sentence.length && sentence[j] != ' ') ++j;
            reverse(sentence, i, j - 1);
            i = j;
            ++j;
        }
        s = String.valueOf(sentence);
        return s;
    }
    
    private void reverse(char[] arr, int start, int end) {
        if (arr.length == 0) return;
        
        while (start < end) {
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            ++start;
            --end;
        }
    }
}
```
