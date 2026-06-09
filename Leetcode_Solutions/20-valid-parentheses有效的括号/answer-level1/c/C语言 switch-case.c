### 解题思路
维护一个数组，采用switch--case将括号与数值关联。左括号+1，右括号-1
关键是处理好特殊情况，不满足约束的时候直接返回false。

### 代码

```c


bool isValid(char * s){
    int i = 0;
    int val = 0;
    int lens = strlen(s);
    int index = 0;

    if (lens % 2 == 1 || s == NULL) {
        return false;
    }

    int array[10000] = { 0 };

    for (i = 0; i < lens; i++) {
        switch (s[i]) {
            case '(':
                val = 1;
                break;
            case '[':
                val = 2;
                break;
            case '{':
                val = 3;
                break;
            case ')':
                val = 11;
                break;
            case ']':
                val = 12;
                break;
            case '}':
                val = 13;
                break;
            default:
                return false;
        }

        if (val < 10) {
            array[index] = val;
            index++;
        } else if (index <= 0) {
            return false;
        } else {
            if (array[index - 1] == val - 10) {
                index--;
            } else {
                return false;
            }
        }
    }

    if (index == 0) {
        return true;
    } else {
        return false;
    }
}

```