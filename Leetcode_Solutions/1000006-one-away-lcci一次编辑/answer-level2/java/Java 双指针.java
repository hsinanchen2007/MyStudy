### 解题思路
由于只有三种更改方式，并且没有对换方式。因此，我们用长度作为判据。
不等长时，最多差1；
进入循环，若指针对应位置不相等，若等长，则都进入下一位判断；若不等长，则将较长的指针后移（不可能是较短的！）

PS：这题标签好像是dp，哪位大佬提供一下dp的方法？

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        int length1 = first.length();
        int length2 = second.length();
        if(Math.abs(length1 - length2) > 1)
            return false;
        
        int errCount = 0;
        int p1 = 0;
        int p2 = 0;
        
        while(p1<length1 || p2<length2){
            if(errCount > 1)
                return false;
            
            if(p1<length1 && p2<length2){
                if(first.charAt(p1) == second.charAt(p2)){
                    p1++;
                    p2++;
                }else{
                    if(length1==length2){
                        p1++;
                        p2++;
                    }
                    else if(length1<length2){
                        p2++;
                    }else{
                        p1++;
                    }
                    errCount++;
                }
            }else{
                if(errCount == 1)   return false;
                p1++;
                p2++;
            }
        }
        
        if(errCount > 1)    return false;
        return true;
        
        

    }
}
```