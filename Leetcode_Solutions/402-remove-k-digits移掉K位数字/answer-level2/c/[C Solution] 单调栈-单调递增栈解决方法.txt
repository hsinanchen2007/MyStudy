### 解题思路
此处撰写解题思路

### 代码

```c
// 利用单调栈，单调递增栈

char * removeKdigits(char * num, int k){
    char* char_zero = (char*)malloc(sizeof(char) *  2 );
    char_zero[0] = '0';
    char_zero[1] = '\0';
    
    if(strlen(num) <= k){
        return char_zero;
    }

    char* stack = (char*)malloc(sizeof(char) * (strlen(num) + 1 ));
    int stack_idx = 0 , remove_len = 0 , idx = 0, diff = strlen(num) - k;

    for(int i = 0; i < strlen(num) ; i++ ){
        while(stack_idx > 0 && remove_len < k && stack[stack_idx-1] > num[i]){
            stack[stack_idx-1] = num[i];
            remove_len++;
            stack_idx--;  
        }
        if(stack_idx < diff){
            stack[stack_idx] = num[i];
            stack_idx++;
        }else{
            remove_len++;
        }
    }
    stack[stack_idx] = '\0';

    while(stack[idx] == '0'){
         idx++;
    }
    if(strlen(stack) == idx){
        return char_zero;
    }

    char* ret = (char*)malloc(sizeof(char) * (stack_idx - idx + 1));
    strncpy(ret, stack + idx, (stack_idx - idx + 1));
    
    return ret;
}
```