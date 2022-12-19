public class Solution {
    public bool IsPalindrome(int x) {
        // if x is negative number or Single digit is 0
        if (x < 0 || (x > 0 && x % 10 == 0))
          {
              return false;
          }
        
        // check how long the number
         var d = 1;
         while (x / d >=10)
            {
                d = d * 10;
            }

        while (x > 0)  // 12321
        {
            var s = x / d;   // get Single digit 
            var g = x % 10;  // get highest digit 
            if (s != g) // compare first and last number
            {
                return false;
            }

            x = x % d / 10; // remove first and last to get new number
            d = d / 100; // due to remove two number, it should remove 10 * 10   
        }

        return true;
    }
}