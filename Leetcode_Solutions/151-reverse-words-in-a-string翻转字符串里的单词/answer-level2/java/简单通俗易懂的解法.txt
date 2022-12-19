**题目意思**
题目总体的意思就是翻转，但是不包括内部独立单词的翻转，所以首先的想法就是通过获取到每个单词的数组然后翻转就得到了答案，例如：
```
String example = "hello world!";
String[] Array = ["hello","world!"];
```
所以解法就很简单了
```
    public String reverseWords(String s) {
        String[] preResult = s.split(" "); //获取数组
        StringBuilder result = new StringBuilder();
        for (int i = preResult.length - 1; i >= 0; i--) {
            if (!preResult[i].trim().isEmpty()) { //排除多空格的情况
                result.append(preResult[i] + " ");
            }
        }
        return result.toString().trim();
    }
```
