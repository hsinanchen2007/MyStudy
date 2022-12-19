```
char solve2(vector<char>& letters, char target) {
        
        int left = 0, right = letters.size() - 1;
        if(left > right || target < letters[0] || target >= letters[right]) {
            return letters[0];
        }
        // if(letters[0] == target && target < letters[1] ) {
        //     return letters[1];
        // }
        left = 1; //left = 1时和上面去除边界的条件问题等价  效果是一样的
        while(left <= right) {
            if(target < letters[left] || target > letters[right]) {
                return letters[left];
            }
            int mid = left + (right - left) / 2;
            if(letters[mid - 1] <= target && target < letters[mid]) {  
                return letters[mid];
            }else if(target >= letters[mid]) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        
        if(left > right || target <= letters[0]) {
            return letters[0];
        }else{
            return letters[0];
        }
        
    }