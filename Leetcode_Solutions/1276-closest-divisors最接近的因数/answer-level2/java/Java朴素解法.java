```
class Solution {
    public int[] closestDivisors(int num) {
        int[] ans1=helper(num+1);
        int[] ans2=helper(num+2);
        return (ans1[0]-ans2[1])>(ans2[0]-ans2[1])?ans2:ans1;
    }

    int[] helper(int num){
        int i;
        int sq=(int)Math.sqrt(num);
        if (num % sq == sq) {
            return new int[]{sq, sq};
        }else{
            int flag;
            int low = (int)Math.pow(sq, 2);
            int high = (int) Math.pow(sq + 1, 2);
            if ((num - low) >= (high - num)) {
                flag = sq + 1;
            } else {
                flag=sq;
            }

            for (i = flag; i >0; i--) {
                if(num%i==0) break;
            }
            return new int[]{num/i,i};
        }
        
    }
}
```
