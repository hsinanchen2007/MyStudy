**1.定义一个辅助栈;
2.遍历pushed数组,先将当前数字放入栈中,判断栈顶元素是否为popped数组的第一个数字,如果是就pop,并且index指针移动到poped数组的下一个位置,继续循环判断;
3.最后判断stack中的元素是否全部被pop完即可,即判断栈空;
4.完结。**


        public boolean validateStackSequences(int[] pushed, int[] popped) {
            if (pushed.length != popped.length)
                return false;
            
            int index = 0;
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < pushed.length; i++) {
                stack.push(pushed[i]);
                while (!stack.isEmpty() && stack.peek() == popped[index]) {
                    stack.pop();
                    index++;
                }
            }
            return stack.isEmpty();
        }