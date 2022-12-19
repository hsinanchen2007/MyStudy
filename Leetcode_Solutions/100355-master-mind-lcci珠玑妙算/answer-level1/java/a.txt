### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] masterMind(String solution, String guess) {
        StringBuilder s=new StringBuilder(solution);
        StringBuilder g=new StringBuilder(guess);
        int res=0;
        for (int i3 = 0; i3 < 4; i3++) {
            if(s.length()>=1) {
                for (int i = 0; i <s.length(); i++) {
                    if (s.charAt(i) == g.charAt(i)) {
                        s.deleteCharAt(i);
                        g.deleteCharAt(i);
                        res++;
                        break;
                    }
                }
            }
        }

        int r=0;
        for (int i4 = 0; i4 < 4; i4++) {
            if(s.length()>=1){
                for (int i = 0; i < s.length(); i++) {
                    for (int i1 = 0; i1 <g.length(); i1++) {
                        if(s.charAt(i)==g.charAt(i1)) {
                            s.deleteCharAt(i);
                            g.deleteCharAt(i1);
                            r++;
                            break;
                        }
                    }
                }
            }
        }

    int[] result=new int[]{res,r};
    return result;  
    }
}
```