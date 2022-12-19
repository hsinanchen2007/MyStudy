import java.util.Arrays;
import java.util.TreeSet;
class Solution {
    
    public  static TreeSet<Integer> set = new TreeSet <>();
        public  static int nthUglyNumber(int n, int a, int b, int c) {
        if(n == 0 )return  -1  ;
        int i = 1;
        while(i<=n){
            set.add(a*i);
            set.add(b*i);
            set.add(c*i);
            i++;
        }
        Object[] demo = set.toArray();
        return (int)demo[n-1];
    }
}