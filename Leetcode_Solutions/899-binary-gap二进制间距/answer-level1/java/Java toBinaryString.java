```
import static java.lang.Integer.toBinaryString;

class Solution {
    public int binaryGap(int N) {
        String nStr = toBinaryString(N);
        int len = nStr.length();
        int[] data= new int[len];
        int last = -1,gap =0;
        for(int i = 0;i < len; i++){
            if(nStr.charAt(i) == '1'){
                if(last == -1){
                    last = i;
                }else{
                    gap = Math.max(gap,i - last);
                    last = i;
                }
            }
        }
        return gap;
    }
}
```

