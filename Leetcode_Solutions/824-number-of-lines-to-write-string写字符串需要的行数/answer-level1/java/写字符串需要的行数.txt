### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int count=0,flag=0;
    int i=0;
    while(i<S.length()){
        count+=widths[S.charAt(i)-'a'];
        if(count==100){
           count=0;
           flag++;
        }
        else if(count>100){
            count=0;
            flag++;
            i--;
        }
        i++;
    }
    if(count!=0)flag++;
    return new int[]{flag,count};
    }
}
```