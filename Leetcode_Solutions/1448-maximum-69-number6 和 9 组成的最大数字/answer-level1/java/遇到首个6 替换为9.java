```
class Solution {
    public int maximum69Number (int num) {
        StringBuilder  test = new StringBuilder( ""+num);
        for( int i =0 ;i< test.length();i++){
            if( test.charAt(i)== '6'){
                test.setCharAt(i,'9');
                break;
            }
        }
        return  Integer.parseInt(test.toString()) ;
    }
}
```

