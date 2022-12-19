```
class Solution {
   public boolean canMeasureWater(int x, int y, int z) {
        if(z==0){
            return true;
        }
        if(x==0 && y!=0){
            return z%y==0;
        }
        if(y==0 && x!=0){
            return z%x==0;
        }
        if(x==0&&y==0){
            return false;
        }
        if (x + y >= z) {
            return z % gcd(x, y) == 0;
        }
        return false;
    }
    public static int gcd(int a,int b){
        if(a==1||b==1){
            return 1;
        }
        if(b==0){
            return 0;
        }
        if(a%b==0){
            return a>b?b:a;
        }
        return gcd(b,a%b);
    }

}
```
我感觉我的方法很脑残 ,不断判断判断,然后调用求最大公约数来比较