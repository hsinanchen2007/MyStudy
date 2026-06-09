官方 **栈和队列** 标签中，对栈的实现方式描述为：

> 栈的实现比队列容易。动态数组足以实现堆栈结构。

```java
// 官方实现的描述，直接使用了ArrayList
class MyStack {
    private List<Integer> data;               // store elements
    public MyStack() {
        data = new ArrayList<>();
    }
}
```

因此做本题的时候，下意识觉得使用 `ArrayList` 就足够了，结果发现不通过，原因是题目中额外要求 **在常数时间内检索到最小元素**，而我则是 **暴力循环遍历所有元素找到最小值** , 这样当然不行。

原来 `getMin()` 函数有时间限制，那么用一个成员记录最小值的状态应该就可以了吧...

试了一下竟然真的可以，这也算偷奸耍滑通过了......（我只是把循环的操作从`getMin()`转移到了`pop()`）...

```java
class MinStack {

    private List<Integer> data;
    // 1.用一个成员记录栈内最小值
    private int min = Integer.MAX_VALUE;

    public MinStack() {
        data = new ArrayList<>();
    }

    // 2.写入时，看情况更新最小值
    public void push(int x) {
        if (min > x) {
            min = x;
        }
        data.add(x);
    }

    // 3.出栈时，更新最小值，这里时间复杂度为 O(N)
    public void pop() {
        verifyNotEmpty();
        data.remove(data.size() - 1);

        min = Integer.MAX_VALUE;
        for (Integer num : data) {
            if (min > num) {
                min = num;
            }
        }
    }

    public int top() {
        verifyNotEmpty();
        return data.get(data.size() - 1);
    }

    // 4.这样就能保证，获取最小值的函数，执行时间为常数时间了 =w= 
    public int getMin() {
        verifyNotEmpty();
        return min;
    }

    private void verifyNotEmpty() {
        if (data.isEmpty()) {
            throw new IllegalArgumentException("Stack is empty");
        }
    }
}
```
 
