### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1){
            return s;
        }
        //定义基础数据
        char[] cs = s.toCharArray();
        char[] newCs = new char[cs.length];

        for (int i=0, index=0, add=(--numRows)*2, one=add-2, two=2; i <= numRows; i++) {
            if(i == 0 || i == numRows){
                for (int x = i; x < cs.length; x+=add) {
                    newCs[index++]=cs[x];
                }
            } else {
                for (int x=i, addNum = two; x < cs.length; x+=addNum=addNum==two?one:two) {
                    newCs[index++]=cs[x];
                }
                two+=2;
                one-=2;
            }
        }
        return new String(newCs);
    }
}
```