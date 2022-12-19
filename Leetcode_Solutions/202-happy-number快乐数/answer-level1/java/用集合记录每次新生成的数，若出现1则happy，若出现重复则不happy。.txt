用集合记录每次新生成的数，若出现1则happy，若出现重复则不happy。
```
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set=new HashSet<>();
        while(n!=1){
            int temp=0;
            while(n!=0){
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n=temp;
            if(n==1)return true;
            if(set.contains(n))return false;
            set.add(n);
        }
        return true;
    }
}
```
执行用时 :3 ms, 在所有 Java 提交中击败了33.25%的用户
内存消耗 :33.8 MB, 在所有 Java 提交中击败了26.65%的用户