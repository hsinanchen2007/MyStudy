```
class Solution {
    public String reverseWords(String s) {
        // 主要是为了去除字符串末尾的空格，然后按照一个或多个空白符分隔。
        String[] arrays = s.trim().split("\\s+");
        StringBuilder result = new StringBuilder();
        for(int i = arrays.length - 1;i >= 0;i--){
            // 如果要将单词翻转，用StringBuilder的reverse()方法，这道题不用  
            result.append(arrays[i]);
            if(i > 0)
                result.append(" ");
        }
        return result.toString();
    }
}
```
