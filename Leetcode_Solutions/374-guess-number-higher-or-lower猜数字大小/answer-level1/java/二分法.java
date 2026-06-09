    // 找区间端点用 left < right
	// 找确切的某个值用 left <= right
    public class Solution extends GuessGame {
        public int guessNumber(int n) {
            int left = 1;
            int right = n;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(guess(mid) == 0) {
                    return mid;
                }else if(guess(mid) == 1) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }
            }
            return -1;   // 你的数字不在（1 - n）内
        }
    }