```
int calPoints(char ** ops, int opsSize){
    int valid[1001] = {0};
    int top;
    int i;
    int sum = 0;
    top = 0;
    for (i = 0; i < opsSize; i++) {
        if (ops[i][0] == 'C') {
            if (top == 0) {
                continue;
            } else {
                top--;
            }
        } else if (ops[i][0] == 'D') {
            if (top == 0) {
                continue;
            }
            valid[top] = 2 * valid[top - 1]; 
            top++;
                     
        } else if (ops[i][0] == '+') {
            if (top == 0) {
                continue;
            } else if (top == 1) {
                valid[top] = valid[top - 1];
                top++;
                continue;
            }
            valid[top] = valid[top - 1] + valid[top - 2];
            top++;
        } else {
            valid[top] = atoi(ops[i]);
            top++;
        }
    }

    for (i = 0; i < top; i++) {
        sum += valid[i];
    }
    
    return sum;
}
```
