![微信图片_20200407141954.png](https://pic.leetcode-cn.com/e4f4e718d1b689188f228372d7e7fda619831bbccec014b8b716bb0374e36b1c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200407141954.png)

# 解题思路
双指针，参照344题和541题官方题解
字符串转数组，遍历数组，每碰到1次空格反转空格前的单词，因为最后一个单词后面没有空格，遍历结束后再反转1次最后一个单词

# 代码
```
class Solution {
    public String reverseWords(String s) {
        char[] a = s.toCharArray();
        int n = a.length;
        int left = 0;
        int right = 0;
        char temp;
        for (int i = 0; i < n; i++) {
            if (a[i] == ' ') {
                right = i - 1;
                while (left < right) {
                    temp = a[left];
                    a[left++] = a[right];
                    a[right--] = temp;  
                }
                left = i + 1;
            }
        }
        right = n - 1;
        while (left < right) {
            temp= a[left];
            a[left++] = a[right];
            a[right--] = temp;
        }
        return new String(a);
    }
}
```
