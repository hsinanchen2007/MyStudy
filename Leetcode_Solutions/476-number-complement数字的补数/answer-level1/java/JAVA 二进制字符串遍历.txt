```
class Solution {
    public int findComplement(int num) {
        StringBuffer sb=new StringBuffer(Integer.toBinaryString(num));
        StringBuffer ans=new StringBuffer();
        int i=0;
        while(i<sb.length()){
            if(sb.charAt(i)=='0'){ans.append('1');}
            else{ans.append('0');}
            i++;
        }
        return Integer.valueOf(ans.toString(),2);
    }
}
```
