### 解题思路
// https://bbs.huaweicloud.com/blogs/104892 采用栈的形式
// 1.一个栈用于存放数字就够了，
// 2. 遇到数字时，就存起来，遇到运算符时，就弹出栈顶的两个元素(栈顶索引减去2);
// 3. 运算完成后，就再放入栈中，栈顶索引加1
// 因为表达式总是有效的，所以不用判断异常情况

// 在写代码过程中，有两点需要注意：
// 1.  每位的数字有可能不只是一个数字，比如13，不能只判断首位  // getNumber
// 2. "-" 和 "-11"，减号和负数如果只根据首位来判断，无法区分是操作符还是数字，需要单独处理一下。 // isNumber

### 代码

```c
// https://bbs.huaweicloud.com/blogs/104892 采用双栈的形式
// 1.一个栈用于存放数字就够了，
// 2. 遇到数字时，就存起来，遇到运算符时，就弹出栈顶的两个元素(栈顶索引减去2);
// 3. 运算完成后，就再放入栈中，栈顶索引加1
// 因为表达式总是有效的，所以不用判断异常情况

// 在写代码过程中，有两点需要注意：
// 1.  每位的数字有可能是多位的，不能只判断首位  // getNumber
// 2. "-" 和 "-11"，减号和负数如果只根据首位来判断，无法区分是操作符还是数字，需要单独处理一下。 // isNumber


// 还有负数， 这样负数处理的时候还需要和减号作区分才行。
// 所以要判断是数字还是运算符
bool isNumber(char *str) {
    if (*str == '*' || *str == '/' || *str == '+') {
        return false;
    }
    if (*str == '-' && strlen(str) == 1) {
        return false;
    }
    return true;
}


// 本题的初始数据是string类型，需要将其转换成int类型。
// 要注意，使用单引号作为字符，而不是字符串来比较
// 同时，数字有可能是多位的，不能简单减去 '0' 就可以了。
int getNumber(char *str) { // str是 token[i]  // 注意负数的处理
    int result = 0;
    if (*str == '-') {
        for (int i = 1; i < strlen(str); i ++) {
            result = result * 10 + (*(str + i) - '0');
        }
        result = 0 - result;
    } else {
        for (int i = 0; i < strlen(str); i ++) {
            result = result * 10 + (*(str + i) - '0');
        }
    }
    return result;
}

int evalRPN(char ** tokens, int tokensSize) {
    // tokens指向的是这个数组的起始地址
    // tokens[i] 指向的是第i位元素的地址，然后可以取值 *token[i]得到此位置的值
    int *stack1 = (int *)malloc(sizeof(int) * tokensSize); // 申请的空间应该还能减少
    int count = 0;
    int temp = 0; // 作为中间变量使用
    
    for(int i = 0; i < tokensSize; i++) {
        if(isNumber(tokens[i])) { 
            // 说明是数字
            // printf("%c, %d \n",*tokens[i], *tokens[i] - '0');
            stack1[count++] = getNumber(tokens[i]); // 存起来数字
        } else {
            int second = stack1[--count]; // 比如count为2， --后，count为1来使用
            int first = stack1[--count]; // --后，count为0来使用
            // printf("first=%d,second=%d \n",first, second);
            if(*tokens[i] == '+') {
                temp = first + second;
            } else if (*tokens[i] == '-') { 
                temp = first - second;
            } else if (*tokens[i] == '*') {
                temp = first * second;
            } else {
                temp = first / second;
            }
            stack1[count++] = temp;
        }
    }
    return stack1[0];

}



// 题解： 
// bool isNumber(char *str) {
//     if (*str == '*' || *str == '/' || *str == '+') return false;
//     if (*str == '-' && strlen(str) == 1) return false;
//     return true;
// }
// int convertToNumber(char *str) {
//     int result = 0;
//     if (*str == '-') {
//         for (int i = 1; i < strlen(str); i ++) {
//             result = result * 10 + (*(str + i) - '0');
//         }
//         result = 0 - result;
//     }
//     else {
//         for (int i = 0; i < strlen(str); i ++) {
//             result = result * 10 + (*(str + i) - '0');
//         }
//     }
//     return result;
// }
// int evalRPN(char ** tokens, int tokensSize){
//     if (tokensSize == 1) {
//         return convertToNumber(tokens[0]);
//     }
//     int result = 0;
//     int stack[10000] = {0};
//     int count = 0;
//     for (int i = 0; i < tokensSize; i ++) {
//         if (isNumber(tokens[i])) {
//             stack[count ++] = convertToNumber(tokens[i]);
//         }
//         else {
//             if (*tokens[i] == '+') {
//                 result = (stack[count - 2] + stack[count - 1]);
//             }
//             if (*tokens[i] == '-') {
//                 result = (stack[count - 2] - stack[count - 1]);
//             }
//             if (*tokens[i] == '*') {
//                 result = (stack[count - 2] * stack[count - 1]);
//             }
//             if (*tokens[i] == '/') {
//                 result = (stack[count - 2] / stack[count - 1]);
//             }
//             count -= 1;
//             stack[count - 1] = result;
//         }
//     }
//     return result;
// }

// 作者：nicedream
// 链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/solution/yu-dao-shu-zi-ru-zhan-yu-dao-suan-zhu-fu-chu-zhan-/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




```