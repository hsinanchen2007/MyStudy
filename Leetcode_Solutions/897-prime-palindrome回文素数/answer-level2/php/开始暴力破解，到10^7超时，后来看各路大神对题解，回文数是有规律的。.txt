class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function primePalindrome($N) {
        if ($N < 1) return 'error';
        if ($N == 1) return 2;
        if ($N == 2) return 2;

        $firstPalindrome = $N % 2 == 0 ? $N + 1 : $N;
        while (!Solution::checkIsPalindrome($firstPalindrome)) {
            $firstPalindrome++;
        }
        if (Solution::checkIsPrimeNumber($firstPalindrome)) return $firstPalindrome;
        $len = strlen($firstPalindrome);
        $flag = $len % 2 == 0 ? true : false;
        $baseLen = $flag ? $len / 2 : ($len + 1) / 2;
        $preBase = substr($firstPalindrome, 0, $baseLen);
        $base = $preBase + 1;

        while (true) {
            if (substr($preBase, 0, 1) == 9 && substr($base, 0, 1) == 1) {
                if ($flag == false) {
                    $flag = true;
                    $base = $base / 10;
                } else {
                    $flag = false;
                }
            }
            $palindrome =  Solution::generatePalindrome($base, $flag);
            if (Solution::checkIsPrimeNumber($palindrome)) return $palindrome;

            $preBase = $base;
            $base ++;
        }
    }

    static function checkIsPalindrome($number)
    {
        if ($number < 0) return false;
        if ($number < 10) return true;
        if (strrev($number) == $number) {
            return true;
        }
        return false;
    }

    static function checkIsPrimeNumber($number)
    {
        if ($number <= 1) return false;
        if ($number == 2) return true;
        if ($number % 2 == 0) return false;
        $len = floor(sqrt($number));
        for ($i = 2; $i <= $len; $i ++) {
            if ($number % $i == 0) {
                return false;
            }
        }

        return true;
    }

    static function generatePalindrome($base, $flag)
    {
        if ($flag) {
            return $base . strrev($base);
        } else {
            return $base . strrev(substr($base, 0, strlen($base ) - 1));
        }
    }
    
}
![image.png](https://pic.leetcode-cn.com/d3176e1e32362caecac50f89b69a6463d90907c27f78e456de0c3031c35454c0-image.png)
