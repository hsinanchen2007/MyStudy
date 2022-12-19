* 一个栈用于存值
* 另一个栈作为辅助栈，存储最小值
给每个值配备一个最小值存入辅助栈中，当然也可以优化，忽略相同的最小值。
```
class MinStack {
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
	 void push(int value) {
        s1.push(value);
        // 相当于给每个值都配了一个最小值
        if(s2.empty()||value<s2.top()){
            s2.push(value);
        }
        else{
            s2.push(s2.top());
        }
    }
    void pop() {
        s1.pop();
        s2.pop();
    }
    int top() {
        return s1.top();
    }
    int min() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

```

另外在***上看到了另一种方法，
>根据单个辅助变量和栈中存储的值就能够推理出top值和min值了，具体规则如下： 入栈：  压缩：将要入栈的元素value减去当前最小值min，得到一个差值diff，只存储该差值； 更新：如果入栈的元素value比当前最小值min小，则要更新最小值：min=value； 初始：第一次入栈比较特殊，因为此时的min变量并没有值，所以令：min=value；  出栈：  更新：如果栈中存储的差值diff是负数，说明出栈的元素是当前最小值min，需要把min值更新为上一个最小值min = min - diff，否则，出栈的元素不是最小值，则不对min变量做任何操作； 还原：如果栈中存储的差值diff是正数，说明 top = min + diff，否则，说明top元素本身是最小值 top = min.

代码能够通过***
```

class Solution {
public:
    stack<int> mystack;
	int mymin, mytop;
public:
	void push(int value) {
		if (mystack.empty())
			mymin = value;
		mystack.push(value - mymin);  // 入栈的值减去当前最小值
		if (value - mymin < 0)  // 如果入栈的值比当前最小值小，更新最小值
			mymin = value;
		// 更新top值
		mytop = value;
	}
	void pop() {

		if (!mystack.empty())  // 如果非空
		{
			if (mystack.top() < 0)  // 说明此时pop出去的是最小值
			{
				mymin = mymin - mystack.top();  // 原来的最小值等于现在的最小值 - 差值（负的）
			}
			mystack.pop(); // 出栈

			mytop = mymin + (mystack.top() < 0 ? 0 : mystack.top());  // 更新top值，如果此时top值小于0，表示top值是min值，否则加差值

		}
		
	}
	int top() {
		return mytop;

	}
	int min() {
		return mymin;

	}
};

```
但是存在一个bug，就是当min = -2147483648, 那么如果此时存入一个正数就会超出int的表示范围，这个问题我暂时还没有想到解决的办法，希望大家一起交流。^_^