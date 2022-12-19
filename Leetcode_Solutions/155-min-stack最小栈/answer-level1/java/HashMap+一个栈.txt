
# 最小栈

### 题目描述

设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

- push(x) -- 将元素 x 推入栈中。
- pop() -- 删除栈顶的元素。
- top() -- 获取栈顶元素。
- getMin() -- 检索栈中的最小元素

### 示例

```java
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

### 思路 : 

① 最小栈能够找到当前栈中的最小元素

② 用HashMap存取当前栈中已存放的数据以及该数据出现的次数

例如 : 

```java
{0=1, 2=1, 3=3, 4=1, -1=2}
//0在栈中出现1次, 2在栈中出现1次, 3在栈中出现3次......
```

③ 当有数据压入或弹出栈中时, 同时需要更新HashMap, 并且判断最小值是否发生改变, 因为有可能在栈中当前最小值在栈顶且只出现一次, 所以在弹出栈时, 要重新选出新的最小值

### 编程

```java
package min_Stack;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

/**
 * @author Jack
 * @date 2019-06-22-18:06
 */
public class MinStack {
    //栈
    private Stack<Integer> stack;
    //最小值
    private int min = Integer.MAX_VALUE;
    //存放栈中的元素及每个元素出现的次数
    private Map<Integer, Integer> count = new HashMap<Integer, Integer>();

    /** initialize your data structure here. */
    public MinStack() {
        this.stack = new Stack<Integer>();
    }

    public void push(int x) {
        //判断是否需要更新最小值
        if (x <= min){
            min = x;
            //判断该元素是否已经存在于栈中
            if(count.containsKey(x)){
                count.put(x, count.get(x)+1);
            }else{
                count.put(x, 1);
            }
        }
        stack.push(x);
    }

    public void pop() {
        Integer pop = stack.pop();
        //判断当前弹出的元素是否为最小值
        if (min == pop){
            //判断该元素在栈中是否只出现一次, 若是, 则重新选举, 遍历HashMap的键来重新选出新的最小值
            if(count.get(pop)==1){
                count.remove(pop);
                min = Integer.MAX_VALUE;
                for (Integer number:
                count.keySet()) {
                    if (number < min){
                        min = number;
                    }else{
                        continue;
                    }
                }
            }else{
                count.put(min,count.get(pop)-1);
            }
        }
    }

    public int top() {
        if(stack.size()==0){
            return 0;
        }else{
            return stack.get(stack.size()-1);
        }

    }

    public int getMin() {
        return min;
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(2);
        minStack.push(0);
        minStack.push(3);
        minStack.push(0);
        System.out.println("min:"+minStack.getMin());  //min:0
        minStack.pop(); //弹出0
        System.out.println("min:"+minStack.getMin()); //min:0
        minStack.pop();//弹出3
        System.out.println("min:"+minStack.getMin());//min:0
        minStack.pop();//弹出0
        System.out.println("min:"+minStack.getMin());//min:2
    }

}

执行结果 :
	min:0
    min:0
    min:0
    min:2
```

### 思考

1. **为什么不能直接遍历栈中的元素 ?** 

会遇到下面的这样一个错误


![1561205503318.png](https://pic.leetcode-cn.com/4b5d360ae5b4cfb2b5374f804d5670ec53cb74eccb9e0fabeb93f97d980ccce0-1561205503318.png)

因为测试用例插入了大量的数值, 几万几十万个数值, 遍历栈需要的时间代价非常巨大, 这次错误我数了一下插入的个数, 数不清....

2. **为什么用HashMap?**

   因为它查找元素非常地快, 当我判断是否需要重新选举最小值或者判断压入栈的值是否已在栈内出现过时, 都需要去遍历一次栈的元素, 而用HashMap避免了需要遍历整个栈的弊端, 解除了时间的代价.

### 成绩


![1561205959401.png](https://pic.leetcode-cn.com/311f548ac1119a6fc8bb6fcde0cfbda39ab2e6d48c5a616442d4f2a6527e65c1-1561205959401.png)

**感受到了HashMap的强大之处!!!**
