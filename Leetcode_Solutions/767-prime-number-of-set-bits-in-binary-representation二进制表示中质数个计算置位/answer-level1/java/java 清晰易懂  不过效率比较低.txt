```
class Solution {
    public int countPrimeSetBits(int L, int R){
        int sumSum=0;
        for(int i=L;i<R+1;i++){
            int sum=0;
           String str=Integer.toBinaryString(i);//转二进制
            StringBuilder s=new StringBuilder(str);
            System.out.println(s);
           for(int j=0;j<s.length();j++){     
              if(s.charAt(j)=='1') sum++;
           }
           if(isPrime(sum)) sumSum++;
        }
        return sumSum;
    }
    public boolean isPrime(int k){//判断是否是质数
        if(k<3){
            if(k==2) return true;
            else return false;
        }
        else 
        for(int i=2;i<k;i++){
            if(k%i==0) return false;
        }
        return true;
    }
}
```