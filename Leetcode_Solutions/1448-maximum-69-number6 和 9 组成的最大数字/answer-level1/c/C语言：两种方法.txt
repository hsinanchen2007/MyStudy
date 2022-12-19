```
int maximum69Number (int num){
    int m = 1000;
    int t = num;
    while (m){
        int n = t / m;
        if (n == 6){
            return num + 3 * m;
        }
        if (n != 0)
            t -= 9 * m;
        m /= 10;
    }
    return num;
}
```

```
int maximum69Number (int num){
    char nums[5];
    sprintf(nums, "%d", num);
    int n = strlen(nums);
    
    for (int i = 0; i < n; i++){
        if (nums[i] == '6'){
            nums[i] = '9';
            break;
        }
    }
    sscanf(nums, "%d", &num);
    return num;
}
```

