第一种方法，容易想到的就是用新创建一个栈模拟进行入栈和出栈。
```
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> stack = new Stack<>();
        //入栈数组的指针，必须维护，才知道此时应该是哪个数入栈
        int pushIndex = 0;
        //遍历要出栈的数组,如果可以全部出栈成功，那么返回TRUE
        for (int poppedIndex = 0; poppedIndex < popped.length; ++poppedIndex) {
            //这个条件很关键，当 还有数可以入栈 && (栈为空，那么直接入栈，或者栈顶元素与要弹出的数不一样，那么继续入栈)
            while (pushIndex < pushed.length && (stack.empty() || stack.peek() != popped[poppedIndex]))
                stack.push(pushed[pushIndex++]);
            //能走到这里，要么没有数可以继续入栈了，要么此时的栈顶元素和要弹出的数一致
            //如果栈顶元素和要弹出的数不一致，那么直接返回FALSE，因为正如上面所说，能走到这里还可能是因为没有数可以继续入栈了
            if (stack.peek() != popped[poppedIndex])
                return false;
            //如果一致，那么出栈
            else
                stack.pop();
        }
        //走到这里说明全部出栈成功，那么返回TRUE
        return true;
    }
}
```
第二种方法就是直接使用原pushed数组以及自己维护一个stack直接来模拟一个栈。其实栈不过也是数组实现的，会维护一个指针，指针所指的元素即为栈顶元素。
```
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {   
        //用stack指针和原pushed数组模拟一个栈，指针所指即为栈顶元素，其他与上一种解法一致
        //入栈数组的指针，必须维护，才知道此时应该是哪个数入栈
        int stack = -1, pushIndex = 0;
        //遍历要出栈的数组,如果可以全部出栈成功，那么返回TRUE
        for (int poppedIndex = 0; poppedIndex < popped.length; ++poppedIndex) {
            //这个条件很关键，当 还有数可以入栈 && (栈为空，那么直接入栈，或者栈顶元素与要弹出的数不一样，那么继续入栈)
            while (pushIndex < pushed.length && (stack < 0 || pushed[stack] != popped[poppedIndex])) {
                pushed[++stack] = pushed[pushIndex++];
            }
            //能走到这里，要么没有数可以继续入栈了，要么此时的栈顶元素和要弹出的数一致
            //如果栈顶元素和要弹出的数不一致，那么直接返回FALSE，因为正如上面所说，能走到这里还可能是因为没有数可以继续入栈了
            if (pushed[stack] != popped[poppedIndex])
                return false;
            //如果一致，那么出栈
            else 
                --stack;
        }
        //走到这里说明全部出栈成功，那么返回TRUE
        return true;
    }
}
```

