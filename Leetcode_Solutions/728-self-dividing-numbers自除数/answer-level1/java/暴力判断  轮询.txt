```
class Solution {
    boolean  isselfDividingNumber(int num ){
        boolean  ret = true ;
        int  src  = num ;
        while(num != 0){
            int temp  =  num%10 ;
            if(0 != temp )  {
                if( 0 != (src%temp) ) return  false ;
            }else{
                return false;
            }
            num = num/10 ;
        }
        return ret ;
    }

    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer>  ret =  new   ArrayList<>();
        for( int i = left ; i<= right; i++ ){
            if( true ==  isselfDividingNumber(i) ) ret.add(i);
        }
        return  ret ;
    }
}
```
