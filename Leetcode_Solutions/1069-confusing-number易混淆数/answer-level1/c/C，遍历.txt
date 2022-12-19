```
bool confusingNumber(int N){
    char* str = (char*)malloc(11*sizeof(char));
    memset(str, '\0', 11*sizeof(char));
    sprintf(str, "%d", N);
    int sLen = strlen(str);
    int left = 0;
    int right = sLen - 1;
    bool equal = true;
    if (sLen % 2 == 0) {
        while (left < right) {
            if ((str[left] == '0' || str[left] == '1' || str[left] == '6' || str[left] == '8' || str[left] == '9') &&
                (str[right] == '0' || str[right] == '1' || str[right] == '6' || str[right] == '8' || str[right] == '9')) {
                if (!(str[left] == '0' && str[right] == '0') && !(str[left] == '1' && str[right] == '1') && !(str[left] == '8' && str[right] == '8') && 
                    !(str[left] == '9' && str[right] == '6') && !(str[left] == '6' && str[right] == '9')) {
                    equal = false;
                }
                left++;
                right--;
            }
            else {
                break;
            }
        }
        if (right < left && equal == false) {
            return true;
        }
    }
    else {
        while (left <= right) {
            if ((str[left] == '0' || str[left] == '1' || str[left] == '6' || str[left] == '8' || str[left] == '9') &&
                (str[right] == '0' || str[right] == '1' || str[right] == '6' || str[right] == '8' || str[right] == '9')) {
                if (!(str[left] == '0' && str[right] == '0') && !(str[left] == '1' && str[right] == '1') && !(str[left] == '8' && str[right] == '8') &&
                    !(str[left] == '9' && str[right] == '6') && !(str[left] == '6' && str[right] == '9')) {
                    equal = false;
                }
                left++;
                right--;
            }
            else {
                break;
            }
        }
        if (right < left && equal == false) {
            return true;
        }
    }
    return false;
}
```
