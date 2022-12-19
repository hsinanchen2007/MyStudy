思路：
直接按题目字面意思计算和计数
```
int numberOfSteps (int num){
    int count = 0;
    while (num != 0) {
        if (num % 2 == 1) {
            num = num - 1;
        } else {
            num = num / 2;
        }
        count++;
    }
    return count;
}
```
