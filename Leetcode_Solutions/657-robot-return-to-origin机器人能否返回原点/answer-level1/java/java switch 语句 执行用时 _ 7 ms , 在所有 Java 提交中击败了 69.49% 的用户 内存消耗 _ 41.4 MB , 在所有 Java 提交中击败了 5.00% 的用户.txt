### 解题思路
计算UDLR的个数，判断ucount==dcount 和 lcount==rcount 是否相等，只要有一个不相等就返回false

### 代码

```java
class Solution {
    public boolean judgeCircle(String moves) {
        int ucount = 0,dcount = 0,lcount = 0,rcount =0;
        for(int i =0;i<moves.length();i++){
            switch(moves.charAt(i)){
                case 'U':ucount++;break;
                case 'D':dcount++;break;
                case 'L':lcount++;break;
                case 'R':rcount++;break;
            }
        }
        if(ucount != dcount || lcount != rcount){
            return false;
        }
        return true;
    }
}
```