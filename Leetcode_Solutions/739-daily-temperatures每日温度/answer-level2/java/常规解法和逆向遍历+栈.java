解法一(双指针)：
    慢指针：数组的索引值（遍历数组）
    快指针：基于慢指针的位置+1为快指针的起始位置，移动快指针，找到第一个快指针对应的值大于慢指针的值，返回快慢指针之间的差距，如果没有找到，则返回0
    代码实现：   
```
    class Solution {
        public int[] dailyTemperatures(int[] T) {
            int[] result = new int[T.length];
            for (int i=0; i<T.length; i++) {
                int j = i+1;
                boolean flag = false;
                while(j < T.length) {
                    if (T[j]>T[i]) {
                        flag = true;
                        break;
                    }
                    j++;
                }
                if (flag) {
                    result[i] = j-i;
                } else {
                    result[i] = 0;
                }
            }
            return result;
        }
    }
```
    这种方法是最简单的，双循环，同时也是最容易想到的方法，但是循环的次数多
解法二（逆向遍历 + 栈）：遇大弹大，遇小压栈
    为什么要逆向遍历？如果我们按常规思想，正向遍历，跟上面第一种思路没什么两样，现在我们要减少遍历次数，如果我们从右边开始遍历，每个数就只需要顾及自己右边的第一个数即可
    什么意思呢？打比方说，T[i] = 50,T[i+1]=60,那我就不用关心i+1后面的数了，因为后面数都是无效的，那如果T[i+1]=40呢，那是不是又是跟第一种解法重复了呢？那如果我能保证
    T[i],T[i+1],T[i+2]是保持相对大小顺序的呢？这就是栈，栈顶到栈低从小到大，每次压入栈前，比较当前值和栈顶值得区别，遇大弹大，遇小压栈，保证栈内值的大小顺序
    代码实现：
```
        int[] result = new int[T.length];
        Stack<Integer> stack = new Stack();
        for (int i=T.length-1; i>=0; --i) {
            while(!stack.isEmpty() && T[i] > T[stack.peek()]) stack.pop();
            result[i] = stack.isEmpty() ? 0 : stack.peek() - i;
            stack.push(i);
        }
        return result;
    不理解的话 可以画画图模拟压栈时元素的变化
```
