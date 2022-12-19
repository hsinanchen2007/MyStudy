### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();

        Arrays.sort(sc);
        Arrays.sort(tc);
        int index =  tc.length - 1;

        for(int i = 0; i < sc.length; i++){
            if(sc[i] == tc[i])
                continue;
            else{
                index = i;
                break;
            }
        }
        return tc[index];
    }
}
```