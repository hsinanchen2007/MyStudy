**1.此题和503下一个更大元素Ⅱ极其相似;
2.栈每次存储下标,即为 i 的值;
3.符合条件将 i - n 即距离值赋给对应的下标,默认为 0 ;
4.完结。**


        public int[] dailyTemperatures(int[] T) {
            int[] res = new int[T.length];
            Stack<Integer> stack = new Stack<>();

            for (int i = 0; i < res.length; i++) {
                while (!stack.isEmpty() && T[stack.peek()] < T[i]) {
                    int n = stack.peek();
                    res[stack.pop()] = i - n;
                }
                stack.push(i);
            }
            return res;
        }