```java []
import java.util.Arrays;

class Solution {
    private int[] calculate(int i, int j, int k){
        k = i * j + k;
        return new int[]{k, j};
    }
    
    public int[] fraction(int[] cont) {
        if(cont.length == 1){
            return new int[]{cont[0], 1};
        }
        cont = Arrays.copyOf(cont, cont.length+1);
        cont[cont.length-1] = 1;
        for(int i = cont.length-3; i >= 0; --i){
            int[] temp = calculate(cont[i], cont[i+1], cont[i+2]);
            cont[i] = temp[0];
            cont[i+1] = temp[1];
        }
        return Arrays.copyOf(cont, 2);
    }
}
```
