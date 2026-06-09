遍历表达式, 举个累计系数和常数的值. 等号左边正数还是正数, 负数还是负数. 等号右边, 正数取负, 负数取正.


```java
public String solveEquation(String equation) {
    int coefficient = 0, constant = 0;
    equation = equation + "#";

    Integer number = null;
    int sign = 1, left = 1;
    for (char c : equation.toCharArray()) {
        if ('0' <= c && c <= '9') {
            number = number == null ? c - '0' : number * 10 + c - '0';
        } else if (c == 'x') {
            coefficient += left * sign * (number == null ? 1 : number);
            sign = 1;
            number = null;
        } else if (c == '+' || c == '-' || c == '#') {
            if (number != null) {
                constant += left * sign * number;
                number = null;
            }
            sign = c == '+' ? 1 : -1;
        } else {// if (c == '=')
            if (number != null) {
                constant += left * sign * number;
                number = null;
            }
            left = -1;
            sign = 1;
        }
    }

    if (coefficient == 0 && constant == 0) {
        return "Infinite solutions";
    } else if (coefficient == 0 && constant != 0) {
        return "No solution";
    } else {
        return "x=" + String.valueOf(-constant / coefficient);
    }
}
```