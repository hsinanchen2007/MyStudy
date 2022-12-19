```
class Solution {
    public int rotatedDigits(int N) {
        int result = 0;
        for(int i=2;i<=N;i++){
            if(test(i)==true){
                result++;
            }
        }
        return result;
    }
    
    private boolean test(int num){
        boolean flag=false;
        int[] map={0,0,1,-1,-1,1,1,-1,-1,1};
        while(num!=0){
            int mod = num%10;
            if(mod == 3 || mod == 4 || mod == 7){
                return false;
            }else if(mod == 2 || mod == 5 || mod == 6 || mod == 9){
                flag=true;
            }
            num /= 10;
        }
        return flag;
    }
}
```
