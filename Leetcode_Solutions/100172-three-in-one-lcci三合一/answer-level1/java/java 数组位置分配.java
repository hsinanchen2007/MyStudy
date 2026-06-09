**思路**
定义一个数组arr，数组的位置分配规则如下：
1. 数组的下标为$[0, 0 + 3, ... , 0 + 3 * (stackSize - 1)]$ 存放$stack_0$;
2. 数组的下标为$[1, 1 + 3, ... , 1 + 3 * (stackSize - 1)]$ 存放$stack_1$;
3. 数组的下标为$[2, 2 + 3, ... , 2 + 3 * (stackSize - 1)]$ 存放$stack_2$;

然后，新建一个数组stackTop，用来标记每个栈的栈顶可插入元素的下标（在arr中的下标）。
当执行push操作的时候，需要处理判满，当执行pop或peek操作的时候需要处理判空。其中判空和判满都是根据stackTop来判断。具体详见如下代码：

```java
class TripleInOne {

        private int[] arr;
        private int[] stackTop; // 每个栈当前可push的索引（对应到arr中的索引）
        private int stackSize;

        public TripleInOne(int stackSize) {
            this.stackSize = stackSize;
            arr = new int[stackSize * 3];
            stackTop = new int[]{0, 1, 2};
        }

        public void push(int stackNum, int value) {
            int curStackTop = stackTop[stackNum];
            if (curStackTop / 3 == stackSize) {
                // 栈已满
                return;
            }

            arr[curStackTop] = value;
            stackTop[stackNum] += 3;
        }

        public int pop(int stackNum) {
            if (isEmpty(stackNum)) {
                return -1;
            }


            int value = arr[stackTop[stackNum] - 3];
            stackTop[stackNum] -= 3;
            return value;
        }

        public int peek(int stackNum) {
            if (isEmpty(stackNum)) {
                return -1;
            }

            return arr[stackTop[stackNum] - 3];
        }

        public boolean isEmpty(int stackNum) {
            return stackTop[stackNum] < 3;
        }
    }
```