### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  public String reverseWords(String s) {
        String[] words = s.split(" ");
        List<String> list = new ArrayList<>();
        //添加空格
        for (int i = 0; i < words.length -1; i ++){
            list.add(getReverse(words[i]) + " ");
        }
        list.add(getReverse(words[words.length - 1]));
        StringBuilder sb = new StringBuilder();
        for (int k = 0; k < list.size(); k ++){
            sb.append(list.get(k));
        }
        return sb.toString();
    }

    //对每个分离的字符串单独翻转
    public String getReverse(String s1){
        char[] ch = new char[s1.length()];
        int j = 0;
        for (int i = s1.length()-1; i >=0; i --){
            ch[j++] = s1.charAt(i);
        }
        return String.valueOf(ch);
    }
}
```