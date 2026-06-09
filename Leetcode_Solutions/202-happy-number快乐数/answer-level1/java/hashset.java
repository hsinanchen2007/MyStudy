class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> set= new HashSet<>();
        int a=0;
        while(a!=1){
            a=0;
            while(n!=0){
                a=a+ (n%10)*(n%10);
                n=n/10;
            }
            if(a==1){
                return true;
            }
            else{
                if(set.contains(a)) return false;
                else {set.add(a);
                n=a;}
            }
        }
        return false;
    }
}