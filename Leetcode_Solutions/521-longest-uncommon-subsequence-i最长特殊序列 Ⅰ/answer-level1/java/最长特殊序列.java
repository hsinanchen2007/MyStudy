### 解题思路
寻找最长，嘻嘻嘻嘻

### 代码

```c
int findLUSlength(char * a, char * b){
    if(!strcmp(a,b))
        return -1;
    return strlen(a)>strlen(b)? strlen(a):strlen(b);

}
Python:
return max(len(a), len(b)) if a!=b else -1```

Java:
public class Solution {
    public int findLUSlength(String a, String b) {
        if (a.equals(b))
            return -1;
        return Math.max(a.length(), b.length());
    }
}
