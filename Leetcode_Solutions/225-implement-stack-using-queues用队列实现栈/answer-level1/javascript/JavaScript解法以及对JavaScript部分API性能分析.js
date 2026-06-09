### 解题思路
利用JavaScript数组来解决此题。此解法未采用js内置的数组api，所以时间损耗上会相对较低。
如果想要用原生模仿js中push、pop等操作，我们需要清楚这些操作的运行方式以及响应返回值。
题解最后有对js内置数组api的一个小小的性能分析

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.stack = [];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.stack[this.stack.length] = x;
    return this.stack.length;
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    if(this.empty()) {
        return undefined;
    }
    let popEle = this.stack[this.stack.length-1];
    this.stack.length = this.stack.length - 1;
    return popEle;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.stack[this.stack.length - 1];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    if(this.stack.length === 0) {
        return true;
    }else return false;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
```

### 个人性能测试：

首先我们分别对pop和unshift进行下性能测试:

```javascript
let arr = [],  	
s = +new Date;  // 将日期对象转换成 number 类型

// 顺便测试下 push
for (let i = 0; i < 70000; i++) {
arr.push(i);    // 入栈操作填充该数组
}

console.log(+new Date - s);    // 差值显示执行时间

// pop 测试
s = +new Date;


for(let i = 0; i < 70000; i++) {
arr.pop();
}

console.log(+new Date - s);

// unshift 测试
s = +new Date;

for(let i = 0; i < 70000; i++) {
arr.unshift(i);
}

console.log(+new Date - s);

// 害顺便也测试一下 shift 吧
s = +new Date;


for(let i = 0; i < 70000; i++) {
arr.shift();
}

console.log(+new Date - s);

	
		
```
![image-20200227162406796.png](https://pic.leetcode-cn.com/2c1cf30c110011689d51a182b9a34a808749e8dab79354bf3ce61efa960b68f3-image-20200227162406796.png)




由此可见 shift 和 unshift 真的很伤性能！比 pop 和 push 慢了百倍！

我们可以来想想为什么...

shift和unshift是对于数组的首元素进行操作的，由于数组是个引用类型的数据类型，它在变量赋予的时候其实是赋予了一个指针，也就是说我们首元素出列了或者有元素入列了，我们变量名所挂钩的指针是**不会变的**，所以说每次对首元素操作后面的元素都会受到影响，都会有一步操作。

而 pop 和 push 这样的操作，每次只会对尾元素进行操作，不会对整个数组的元素有影响，即：

```javascript
// 模拟入栈操作（push）
Array.prototype.push = function () {
    for (var i = 0; i< arguments.length; i++) {
        this[this.length] = arguments[i];
    }
    return this.length;
}
```

上面是我用 JavaScript 模拟的操作，让我们从 Chrome 源码来看看方法的具体实现：

在 Chrome 中，push方法的实现是用的汇编，而pop、unshift以及shift则是是用的 C++，这里就单独拎出unshift的来看看：

```c++
intinsertion_index=add_position==AT_START?0:length;
// Copy the arguments to the start.
Subclass::CopyArguments(args,backing_store,add_size,1,insertion_index);
// Set the length.
receiver->set_length(Smi::FromInt(new_length));

/* 
	先判断容量是否足够。
	如果不够，将容量扩展，然后把老元素移到新的内存空间偏移为unshift元素个数的位置，也就是说要腾出起始的空间放unshfit传进来的元素
	如果空间足够了，则直接执行memmove移动内存空间，最后再把unshif传进来的参数copy到开始的位置。
	最后更新 array length
*/
```



回到 JavaScript，刚刚我们看到了 unshift 是十分损伤性能的，特别是对大数组。那如果我们一定要实现是用 unshift 这样的入队方式呢？有没有其他什么方法？

还记得 JavaScript 里有个叫 reverse 的内置方法吗😆

我们是不是用 push 进行入栈，然后用 reverse 来进行数组全反转是不是就是实现了队列入队？是不是有内味了😜

来！测试一下 reverse 的性能：

```javascript
    var arr = [ ], s = +new Date;

    for (var i = 0; i < 50000; i++) {
      arr.push(i);
    }
    arr.reverse();

    console.log(+new Date - s);
```

![image-20200227180720738.png](https://pic.leetcode-cn.com/305405bbe86b1fc527aed751d3ccf4009fdd5791c78a73ae4a052ec237699eb8-image-20200227180720738.png)


​	可以看出 reverse 性能是极高的😮