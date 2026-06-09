若一个数是快乐数，最终变换会回到1，因此确定循环终结条件；
若不是快乐数，会进入死循环，如何终至死循环，将每次变换过后的值存入HashSet中，判断是否出现过重复值，出现则return false;
```
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new HashSet<>();
        set.add(n);
        while(n != 1){
            n = change(n);
            if(set.contains(n)) return false;
            set.add(n);
        }
        return true;
    }
    
    public int change(int n){
        int sum = 0;
        int num;
        while(n != 0){
            num = n%10;
            n /= 10;
            sum += num*num;
        }
        return sum;
    }
}
```
