笨方法，开始没想到异或运算，直接进行字符串比较
```
class Solution {
    public int hammingDistance(int x, int y) {
        String s1=Integer.toBinaryString(x);
        String s2=Integer.toBinaryString(y);
        int count=0;
        char[] c1=s1.toCharArray();
        char[] c2=s2.toCharArray();
        int i=c1.length-1;
        int j=c2.length-1;
        char s='0';//比较的是字符，所以不能直接和0进行比较
        while (i>=0||j>=0){
            if(i<0){
                if(c2[j]!=s){
                    count++;
                }
            }else if(j<0){
                if(c1[i]!=s) count++;

            }else {
                if(c1[i]!=c2[j]) count++;
            }
            i--;
            j--;
        }
        return count;
    }
}
```
