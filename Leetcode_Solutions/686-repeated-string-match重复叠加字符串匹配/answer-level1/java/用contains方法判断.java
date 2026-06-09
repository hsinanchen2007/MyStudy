```
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int i = 0;
        int f = 0;
        StringBuilder sb = new StringBuilder(A);
        if(sb.toString().contains(B))
            return 1;
        while(!sb.toString().contains(B)){
            sb.append(A);
            i++;
            if(sb.toString().contains(B)){
                f = 1;
                break;
            }
            if(sb.toString().length() > 2 * A.length() + B.length()){
                f = 2;
                break;
            }
        }
        if(f == 1)
            return i + 1;
        else
            return -1;
    }
}

```
