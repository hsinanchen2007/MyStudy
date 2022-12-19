![image.png](https://pic.leetcode-cn.com/a01fc9dd5195a610b7c19980f07e9c927ff2a4186ef993217673bf872172788b-image.png)

**链表节点**
```
class Node {
        Node next;
        int value;
        Node(int value) {
            this.value = value;
        }
}
```

创建两个栈：*普通栈*和*最小栈*
```
private Node normal;
private Node min;
```

**普通栈**
正常入栈弹栈。

**最小栈**
1、最小栈为空时入栈。
2、每次入栈时和最小栈比较，如果入栈的值小于最小栈就用入栈的值压栈，入栈的值大于最小栈时用最小栈栈顶的值再次压栈。

**构造器**
```
normal = null;
min = null;
```

**入栈**
```
public void push(int x) {
    if (normal == null || min == null) {
        normal = new Node(x);
        min = new Node(x);
        return;
    }
    Node tempNormal = new Node(x);
    tempNormal.next = normal;
    normal = tempNormal;
    if (x <= min.value) {
        Node tempMin = new Node(x);
        tempMin.next = min;
        min = tempMin;
    } else {
        Node tempMin = new Node(min.value);
        tempMin.next = min;
        min = tempMin;
    }
}
```

**弹栈**
```
public void pop() {
    if (normal == null || min == null) {
        throw new NullPointerException("The stack is null.");
    }
    normal = normal.next;
    min = min.next;
}
```

**栈顶值**
```
public int top() {
    if (normal == null || min == null) {
        throw new NullPointerException("The stack is null.");
    }
    return normal.value;
}
```

**最小值**
```
public int getMin() {
    if (normal == null || min == null) {
        throw new NullPointerException("The stack is null.");
    }
    return min.value;
}
```
