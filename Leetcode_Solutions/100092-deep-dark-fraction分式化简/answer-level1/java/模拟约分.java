```
class Solution {
    public int[] fraction(int[] cont) {
        int denominator=cont[cont.length-1], numerator=1;
        int addend=1;
        for(int i=cont.length-2;i>=0;i--){
            numerator = denominator;
            denominator = cont[i]*denominator+addend;
            addend = numerator;
        }
        return new int[]{denominator, numerator};
    }
}
```