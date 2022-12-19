C语言，模拟一个栈的结构，时间复杂度O(N)，0ms超过100%用户。 将字符挨个压入栈中，如果字符匹配则弹出数据，记录栈中的字符以及其对应的下标。遍历完字符串以后，栈中剩下的都是没有匹配的字符以及下标。根据这些下标计算出最大的有效括号长。
```
// 栈
int longestValidParentheses(char * s){
    int max = 0, index = 0;  // index为栈首元素的指针
    int len = strlen(s);
    if(len == 0 || len == 1) return 0;
    // 申请一个栈stack来存放要放入的字符，申请一个栈label来存放stack中字符对应的下标
    char* stack = (char *)malloc(sizeof(char)*(len+1));
    int* label = (int *)malloc(sizeof(int)*(len+1));
    stack[0] = s[0];
    stack[len] = '\0';
    label[0] = 0;
    for(int i = 1; i < len; i++){
        // 栈中无元素时
        if(index < 0){
            index++;
            stack[index] = s[i];
            label[index] = i;
        }
        // s[i]元素与栈首的字符匹配时，将栈首的字符弹出
        else if(s[i] != stack[index] && s[i] == ')'){
            index--;
        }
        // 否则，将s[i] 压入栈中
        else{
            index++;
            stack[index] = s[i];
            label[index] = i;
        }
    }
    // 最终，label中存放的下标都是没有匹配字符的下标，根据这些下标可以计算最长有效括号数
    if(index < 0) return len;
    else{
        label[index+1] = len;
        max = max > label[0]? max:label[0];
        for(int i = 0; i < index+1; i++){
            max = max > label[i+1]-label[i]-1? max:label[i+1]-label[i]-1;
        }
    }
    free(stack);
    free(label);
    return max;
}```
```
