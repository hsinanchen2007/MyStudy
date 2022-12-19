```
class Solution {

  private int[] digits = new int[]{0, 1, 6, 8, 9};

  public int confusingNumberII(int N) {
    int res = 0;
    for (int i = 1; i <= 4; i++) {
      long num = digits[i];
      res += dfs(N, num);
    }
    return res;
  }

  private int dfs(int max, long num) {
    if (num > max) {
      return 0;
    }
    int res = 0;
    if (isValid(num)) {
      res++;
    }
    for (int digit : digits) {
      num *= 10;
      num += digit;
      res += dfs(max, num);
      num /= 10;
    }
    return res;
  }

  private boolean isValid(long num) {
    long tmp = num;
    long newNum = 0;
    while(tmp > 0){
      newNum *= 10;
      int digit = (int)(tmp % 10);
      if(digit == 6){
        newNum += 9;
      } else if(digit == 9){
        newNum += 6;
      } else {
        newNum += digit;
      }
      tmp /= 10;
    }
    return num != newNum;
  }
}
```