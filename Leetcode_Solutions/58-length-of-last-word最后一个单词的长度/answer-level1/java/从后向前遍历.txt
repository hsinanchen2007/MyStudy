### 解题思路
首先将字符串转换成数组，然后去除最后一个单词后的空格。然后再次遍历计算对最后一个单词的长度

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        char [] array=s.toCharArray();
        if (array.length==0) return 0;
        int i,count=0;
        int length=array.length;//表示删除最后一个单词后面空格之后的长度
        for(i=array.length-1;i>=0;i--){//去除空格
            if(array[i]!=' ')break;
            length--;
        }
        for(i=length-1;i>=0;i--){//计算最后一个单词长度
            if(array[i]==' ') break;
            count++;
        }
        return count;
    }
}
```