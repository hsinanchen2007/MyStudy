直接使用indexOf函数，空间换时间。
class Solution {
    public int strStr(String haystack, String needle) {
        if(needle == ""){return 0;}
        return haystack.indexOf(needle);
    }
}
![image.png](https://pic.leetcode-cn.com/b81ac4cec725828e7bd74467c881318cb928622049d159ea469fc8fa9e987c63-image.png)
