```
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int left = 0,right = letters.length - 1;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            char let = letters[mid];
            if(let > target){
                right = mid - 1; 
            }else if(let <= target){
                left = mid + 1;
            }
        }
        return letters[left % letters.length];
    }
}
```
