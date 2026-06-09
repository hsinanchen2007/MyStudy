```
class Solution {
    public int numSteps(String s) {
        s="0"+s; 
        int len=s.length();
        int ans=0;
        char[] a=new char[505];
        a=s.toCharArray();
        for(int i=len-1;i>1;){
            if(a[i]=='0'){
                ans++;
                i--;
            }
            else{//+1 并计算有多少个连续的1
                ans++;
                int sum=0;
               
                while(a[i]=='1'){
                    sum++;
                    i--;
                }
                ans=ans+sum;
                a[i]='1';
            }
        }
        return ans;
    }
}
/*
思路：如果末尾是0，则是偶数，可以除以2，消去一个0；
如果末尾是1，则是奇数，需要加1变成偶数，这样在末尾会产生一个0，并且左边会进位生出一个1。
如果有一段连续的1，则会在连续1的左边生出一个1，连续的1串会变成0，逐个消掉就好了。


*/
```
