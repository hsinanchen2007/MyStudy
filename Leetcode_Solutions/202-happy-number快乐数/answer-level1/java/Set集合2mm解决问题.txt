class Solution {
    public boolean isHappy(int n) {
        Set<Integer> temp=new HashSet<>();
        while(n!=1){
            if(temp.contains(n)) return false;
            else {
                temp.add(n);
                n=bitSqrtSum(n);
            }
        }
      return true;
    }
    public int bitSqrtSum(int n){
        int sum=0;
        while(n>0){
            int bit=n%10;
            sum+=bit*bit;
            n=n/10;
        }
        return sum;
    }
}