```
 public static boolean judgeSquareSum(int c) {
        //StrictMath.sqrt() 开平方
        //StrictMath.pow(left,2)速度还不如left*left
        int left = 0, right = (int) StrictMath.sqrt(c);
        while (left <= right) {
            int sum = left * left + right * right;
            if (sum < c) left++;
            else if (sum > c) right--;
            else return true;
        }
        return false;
    }
```
