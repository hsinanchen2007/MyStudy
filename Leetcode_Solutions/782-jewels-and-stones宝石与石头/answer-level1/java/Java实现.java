```
class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] cs = S.toCharArray();
        char[] js = J.toCharArray();
        int sum = 0;
        
        byte[] a = new byte[58];
        for(char i : cs){
            a[i - 65]++;
        }
        for(char i : js){
            if(a[i - 65] != 0){
                sum += a[i - 65];
            }
        }
        return sum;
    }
}
```
