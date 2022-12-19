### 解题思路
通过i,j分别指向第一个和最后一个元素

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if(s == null || s.length < 2){
            return;
        }
        // 第一个元素
        int i = 0;

        //最后一个元素
        int j = s.length -1;
        while (i < j){
            //分别交换前后元素
            char temp = s[i];
            s[i ++] = s[j];
            s[j --] = temp;
        }
    }
}
```