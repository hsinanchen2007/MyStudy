### 解题思路
基本思路是使用两分查找。
但是会有空值出现，这时可以结合分治的思想。当遇到空值时，在空值左右两边继续两分查找。

### 代码

```java
class Solution {
    public int findString(String[] words, String s) {
        return findString_sub(words,s,0,words.length-1);       
    }

    public static int findString_sub(String[] words, String s, int left, int right) {
        while(left<right){
            int middle=(left+right)/2;

            if(words[middle].equals("")){
                int leftIndex=findString_sub(words, s, left, middle - 1);
                return leftIndex!=-1?leftIndex:findString_sub(words, s, middle+1, right);
            }

            if(words[middle].equals(s)){
                return middle;
            }else if(words[middle].compareTo(s)>0){
                right=middle-1;
            }else{
                left=middle+1;
            }
        }
            return words[left].equals(s)?left:-1;

    }
}
```