### 解题思路
运用辗转相除法，用栈存储，利用其先进后出特点，将1-余数 存进栈里面

### 代码

```java
class Solution {
    public int bitwiseComplement(int N) {
        Stack<Integer> stack = new Stack<>();
        handle(stack,N);
        int sum = 0;
        while (!stack.empty()){
            int num = stack.pop();
            sum += num * Math.pow(2d, stack.size());
        }

        return sum;
    }

    public void handle(Stack<Integer> stack, int n) {
        //被除数
        int num = n / 2;
        //余数
        int ys = n % 2;
        stack.push(1-ys);
        if (num != 0) {
            handle(stack, num);
        }
    }
}
```