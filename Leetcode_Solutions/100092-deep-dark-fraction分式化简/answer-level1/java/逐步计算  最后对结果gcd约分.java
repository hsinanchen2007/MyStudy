```
class Solution {
      public static int gcd(int m, int n) {
        while (true) {
            if ((m = m % n) == 0)
                return n;
            if ((n = n % m) == 0)
                return m;
        }
    }
    
    public int[] fraction(int[] cont) {
       int[] result=new int[2];
        if(cont.length==1)
        {
            result[0]=cont[0];
            result[1]=1;
        }
        else
        {
            int oldDenominator=cont[cont.length-2]*cont[cont.length-1]+1;
            int oldmolecule = cont[cont.length-1];
            for(int i=cont.length-3;i>=0;i--)
            {
                int Denominator=cont[i]*oldDenominator+oldmolecule;   //分母
                oldmolecule=oldDenominator;      //分子
                oldDenominator=Denominator;
            }

            int gcd=gcd(oldDenominator,oldmolecule);
            result[0]=oldDenominator/gcd;
            result[1]=oldmolecule/gcd;
        }


        return result;
    }
}
```