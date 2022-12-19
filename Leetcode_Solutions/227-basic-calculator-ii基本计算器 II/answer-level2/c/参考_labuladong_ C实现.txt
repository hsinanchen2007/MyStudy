#define MAX_STACK_SIZE 100000

typedef struct {
    int size;
    int itop;
    int Data[MAX_STACK_SIZE];
} stack;

stack stk;

int top() {
    if (stk.itop >= MAX_STACK_SIZE)
        return 0;
    return stk.Data[stk.itop];
}

void pop() {
    stk.size--;
    stk.itop--;
}

void push(int data) {
    stk.size++;
    stk.itop++;
    if(stk.itop >= MAX_STACK_SIZE)
        return;
    stk.Data[stk.itop] = data;
}

bool empty() {
    if(stk.size == 0) 
        return true;
    else 
        return false;
}

int calculate(char * s){
    memset(&stk, 0, sizeof(stack));
    int sLen = strlen(s);
    // 记录算式中的数字
    int num = 0;
    // 记录 num 前的符号，初始化为 +
    char sign = '+';
    for (int i = 0; i < sLen; i++) {
        char c = s[i];
        if (isdigit(c)) 
            num = 10 * num + (c - '0');

        if ((!isdigit(c) && c != ' ') || i == sLen - 1) {
            switch (sign) {
                int pre;
                case '+':
                    push(num); 
                    break;
                case '-':
                    push(-num);
                    break;
                // 只要拿出前一个数字做对应运算即可
                case '*':
                    pre = top();
                    pop();
                    push(pre * num);
                    break;
                case '/':
                    pre = top();
                    pop();
                    push(pre / num);
                    break;
            }
            // 更新符号为当前符号，数字清零
            sign = c;
            num = 0;
        }
    }
    // 将栈中所有结果求和就是答案
    int res = 0;
    while (!empty()) {
        res += top();
        pop();
    }
    
    return res;
}
