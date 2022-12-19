```
int maximum69Number (int num){
    int arr[5] = {0};
    int count = 0;
    while (num) {
        arr[count++] = num % 10;
        num = num / 10;
    }
    for (int i = count - 1; i >= 0; i--) {
        if (arr[i] == 6) {
            arr[i] = 9;
            break;
        }
    }
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i] * pow(10, i);
    }
    return sum;
}
```
