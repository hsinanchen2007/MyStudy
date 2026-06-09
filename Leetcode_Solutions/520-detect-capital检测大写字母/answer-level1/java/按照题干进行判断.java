根据题目的定义，只要满足定义的3个条件即是正确的。所以我们可以从这3个条件入手，其中第一个条件和第二个条件其实是差不多的，一个全部是大写，一个全部是小写；从第一个条件看，我们可以先把给定的字符串使用toUpperCase()方法将其全部转换为大写字母，然后用原来的字符串与之比较即可；同理对于第二个条件，我们将给定的字符串使用toLowerCase()方法将其全部转换为小写字母，然后与之前的字符串对比即可。第三个条件是首字母大写，其余是小写，我们可以使用substring方法将首字母与后面的分离，然后这样也就和第一个与第二个条件一致了。具体如下：

```
class Solution {
    public boolean detectCapitalUse(String word) {
        if(word.equals(word.toUpperCase())){
            return true;
        }
        if(word.equals(word.toLowerCase())){
            return true;
        }
        String str = word.substring(0,1);
        String str1 = word.substring(1);
        if(str.equals(str.toUpperCase()) && str1.equals(str1.toLowerCase())){
            return true;
        }
        return false;
    }
}
```