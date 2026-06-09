写这个的时候笑死我真的是暴力
注意：这是个钻空子的解法，其实不用try-catch就可以


public class Solution {
    public bool IsPalindrome(int x) {
        int endNum = 0;
            int x1 = x;
            do
            {
                try
                {
                    int pop = x1 % 10;
                    x1 /= 10;
                    endNum = endNum * 10 + pop;
                }
                catch
                {
                    return false;
                }

            } while (x1 != 0);
            if (x == endNum&&x>=0) return true;
            else return false;
    }
}