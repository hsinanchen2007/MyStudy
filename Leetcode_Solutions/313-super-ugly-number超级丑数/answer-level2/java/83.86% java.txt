```
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int len=primes.length;
        int a;
        int[] uglyNumber=new int[n];
        int[] index=new int[len];
        uglyNumber[0]=1;
        for(int i=1;i<n;i++)
        {
            uglyNumber[i]=Integer.MAX_VALUE;
            for(int j=0;j<len;j++)
            {
                a=Math.min(uglyNumber[i], primes[j] * uglyNumber[index[j]]);
                if (a==uglyNumber[i-1]){
                    index[j]++;
                    a=Math.min(uglyNumber[i], primes[j] * uglyNumber[index[j]]);
                }
                uglyNumber[i] = a;
            }
            for(int j=0;j<len;j++)
            {
                if(uglyNumber[i]/primes[j]==uglyNumber[index[j]])
                {
                    index[j]++;
                    break;
                }
            }
        }
        return uglyNumber[n-1];
    }
}
```

