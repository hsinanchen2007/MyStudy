![image.png](https://pic.leetcode-cn.com/13634d5cec6cf63da2caaade485cb8b2c266825f2c474d78f41c65e15fff4e5e-image.png)

```
class Solution {
    public String reverseWords(String s) {
        if(s == null || s.length() == 0) return "";
        char[] arrays = s.toCharArray();
        int start = 0;//单词开始
        int end = 0;//单词结束
        int index = 0;
        while (index < arrays.length) {
            while(index<arrays.length &&  arrays[index] != ' ') index++;
            end = index - 1;
             while (end > 0 && start < end){
                    char temp = arrays[end];
                    arrays[end--] = arrays[start];
                    arrays[start++] = temp;
                }
            start = index+1;
            index++;   
        }
        return new String(arrays);
    }
}
```
