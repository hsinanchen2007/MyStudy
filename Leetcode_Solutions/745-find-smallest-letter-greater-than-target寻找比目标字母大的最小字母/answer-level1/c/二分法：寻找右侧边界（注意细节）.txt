char nextGreatestLetter(char* letters, int lettersSize, char target){
    int left = 0;
    int right = lettersSize;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(letters[mid] > target){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    if(left < lettersSize){
        return letters[left];
    }else{
        return letters[0];
    }
}