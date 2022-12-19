```
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int left = 0;
        int right = letters.length - 1;
        // 如果越界，直接返回左侧的值
        if (target >= letters[right]) {
            return letters[0];
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target) { //这里注意相等的情况，也要移动
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        //跳出循环的时候，left大于right，此时，返回left下标的值
        return letters[left];
    }
}
```

