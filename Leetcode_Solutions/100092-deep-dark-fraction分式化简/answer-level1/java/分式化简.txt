
```java

class Solution {
    public int[] fraction(int[] cont) {
        if(cont.length == 1 ){
             return new int[]{cont[0],1};
        }
        int[] tmp = new int[2];
        for (int i = cont.length - 1; i >= 1; i--) {
            if (i == cont.length - 1) {
                tmp = fun(cont[i - 1], 1, cont[i]);
            }else {
                tmp = fun(cont[i - 1], tmp[1], tmp[0]);
            }
        }
        return tmp;
    }

    public int[] fun(int a, int b, int c) {
        int x = a * c + b;
        int y = c;
        return new int[]{x, y};
    }
}
```
