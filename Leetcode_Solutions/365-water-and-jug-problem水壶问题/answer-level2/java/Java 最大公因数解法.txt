```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        if(x==z||y==z||x+y==z) return true;
        if(x==0||y==0) return false;
        return z%gcd(x,y)==0;
    }

    public static int gcd(int x,int y){
        int i = 0;
        int j = 0;
        int temp = 0;
        i = x>y?x:y;
        j = x>y?y:x;
        while(j!=0){
            temp = j;
            j=i%j;
            i=temp;
        }
        return temp;
    }
}
```
