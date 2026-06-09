算法描述：
![IMG_20191106_205926.jpg](https://pic.leetcode-cn.com/51b08647e6b5b1c2c5b931565458d543b2591e876c6c7e0c4f75628dedace1fe-IMG_20191106_205926.jpg)
如图所示，左图是用来保存逻辑队列的，右边一个栈是用来装左边的数据的；
# 1. pop() 操作：
    想想一个队列是头删除，尾巴进元素，然而栈进出只能使用栈尾，要想实现栈的操作
就得再用一个栈，把左边的栈出栈后保存到右边，那么栈中的元素排列正好相反，就把
栈头的元素弄到栈顶了，把它出栈栈顶元素后再搞到左边栈形成逻辑队列
直接上图好描述，笔者分析时也是画图分析：
![IMG_20191106_211837.jpg](https://pic.leetcode-cn.com/dc1f427958ddfe92c961343d4b0376c4d158341af48587f072a4af39d151717b-IMG_20191106_211837.jpg)
# 2. peek操作同理：
    也是需要先把左边栈sack_A的元素倒到右边的栈，再访问右边的栈stack_b的栈顶，最后记得访问后再倒回去
# 3代码实现 code:
时间复杂度：pop() ,和peek()的操作都是O(n)其他O(1) ,空间:O（n）要开辟和他一样的栈
class MyQueue {
public:
    /** Initialize your data structure here. */
   MyQueue()
	{
		stAQ=new std::stack<int>;
		stB = new std::stack<int>;
	}
    
   void push(int x) {
		stAQ->push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stAQ->empty())
		{
			return false;
		}

		else
		{
			while (!stB->empty())
			{
				stB->pop();

			}
	
			int x=0;
			while (!stAQ->empty())
			{
				x = stAQ->top();
				stB->push(x);
				stAQ->pop();
			}
            int sult=stB->top();
			stB->pop();
			int y = 0;
			while (!stB->empty())
			{
				y = stB->top();
				stAQ->push(y);
				stB->pop();
			}
			return sult;
		}
	}

	/** Get the front element. */
	int peek() {
		int sult = 0;
		if (stAQ->empty())
		{
			return false;
		}
		else
		{
			int a = 0;
			while (!stB->empty())
			{
				stB->pop();
			}

			while (!stAQ->empty())
			{
				

				a = stAQ->top();
				stB->push(a);
				stAQ->pop();
		    }
			sult = stB->top();

			while (!stB->empty())
			{

				a = stB->top();
				stAQ->push(a);
				
					stB->pop();
				
			}
		}
		return sult;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stAQ->empty();
	}

private:
	std::stack<int >*stAQ;
	std::stack<int >*stB;
};
