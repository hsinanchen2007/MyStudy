### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        if (words == null|| words.length <= 0)
            return 0;//错误处理
        if(words.length == 1)
            return words[0].length() + 1;//只有一个单词，就直接在末尾添加‘#’
        //按长度递减排序，方便处理，例如“time”, "me", "e",只需从"me"开始判断是否在当前结果索引串的末尾子串(即存在子串"me#"),若是没有排序或者递增，假如当前索引串是"me#",而遍历的串是"time"，还得判断谁的长度长，谁是谁的子串
        Arrays.sort(words, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.length() - o1.length();
            }
        });
        StringBuilder sb = new StringBuilder("");
        for (int i = 0; i < words.length; i++) {
            if(i == 0){
                //第一个字符，直接拼接
                sb.append(words[0] + "#");
            }else{
                //判断当前字符串是否为结果串中的末尾串
                if(sb.lastIndexOf(words[i] + "#") == -1){
                    //存在。直接跳过
                    //不存在，则拼接
                    sb.append(words[i] + "#");
                }
            }
        }
        return sb.length();
    }
}
```