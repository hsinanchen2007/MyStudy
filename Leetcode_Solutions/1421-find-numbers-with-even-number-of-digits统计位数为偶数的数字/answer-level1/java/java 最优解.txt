```
class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int num:nums) {
            if (numberPlace(num)%2 == 0) {
                count++;
            }
        }
        return count;
    }

    private int numberPlace(int num) {
        int place = 0;
        while(num != 0) {
            place++;
            num/=10;
        }
        return place;
    }
}
```
