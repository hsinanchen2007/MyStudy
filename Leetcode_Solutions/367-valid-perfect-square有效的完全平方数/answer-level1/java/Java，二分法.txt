执行结果：通过显示详情执行用时 :1 ms, 在所有 Java 提交中击败了94.81%的用户内存消耗 :33.5 MB, 在所有 Java 提交中击败了11.05%的用户
用long避免了值越界。
```
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num==1){
            return true;
        }
        long left = 1;
        long right = num;
        long mid = left+(right-left)/2;
        while(left<=right){
            if(mid*mid==num){
                return true;
            }else if(mid*mid>num){
                right = mid-1;
                mid = left+(right-left)/2;
            }else if(mid*mid<num){
                left = mid+1;
                mid = left+(right-left)/2;
            }
        }
        return false;
    }
}
```
