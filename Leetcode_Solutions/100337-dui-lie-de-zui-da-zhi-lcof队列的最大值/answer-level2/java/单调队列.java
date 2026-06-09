### 解题思路
34ms/98.78
一：变量说明
1.	val数组用来模拟队列，存放队列中的值
	head指针，初始值为0，代表val队列队头指针
	tail指针，初始值为0，代表val队列队尾指针
2.	max数组用来存放当前队列中“可能的”最大值在val数组中的下标，也是一个队列
	max_head指针，初始值为0，代表max数组的队头指针
	max_tail指针，初始值为0，代表max数组的队尾指针

二：核心思想
max队列用来存放当前队列中的“可能的”最大值在val数组中的下标
比如，先向队列中放入一个1
此时，val队列为：

	
![image.png](https://pic.leetcode-cn.com/d80d184bcef608192da6a2c705acc55357f05fbadb03fb2f1e02d155f51c58ee-image.png)
max队列为：（因为val中只有一个元素，下标为0）
![image.png](https://pic.leetcode-cn.com/a0e893b436c55578d2b5f80ed7bf652db393fe01f715d6f2759b12fa2292a39b-image.png)


接下来，放入一个2
此时，val队列为：
![image.png](https://pic.leetcode-cn.com/2d80a1d6014fcb2a6a3b82eea8b26f27785556f4f5c9206b2fddb4674cd1344c-image.png)
max队列为：
![image.png](https://pic.leetcode-cn.com/0537951276931ab6d6fe56b55b31430577dbda6edf39d9e691bd1f3988f414c3-image.png)

解释如下：因为新放入的元素大于第一个元素，而且第一个元素肯定比第二个元素先出队列，所以，我们一定可以淘汰第一个元素，在max数组中删除第一个值，此时的队列中的最大值为val队列中的第二个元素2

接下来再看一个例子：
当前val队列为：
![image.png](https://pic.leetcode-cn.com/fb67ac726604a5b229580d375e77ee18587a0ffd21d84c1f9c5c32e89aade884-image.png)
max队列为：
![image.png](https://pic.leetcode-cn.com/42989f96091896f5d1a3a1cccc1ba2f96917f0e7bfe743a201496e24320c4bf3-image.png)

然后在val队列中放入6
val队列变为：
![image.png](https://pic.leetcode-cn.com/0ecf43e946d5f8c912f2a66e185614ba6fe5af12100066fea4297698777f577c-image.png)
更新max队列的过程：
说明：val[max[max_tail]]表示以max队列中最后一个元素为下标，val队列中的值.
1.6和val[max[max_tail]]比较，6>val[max[3]]=2,有因为2肯定比6弹出的早，所以我们在max数组中把2的下标删掉，即max_tail--;
2.重复这个过程，直到6<val[max[max_tail]]或者max_head==max_tail
最后max队列为：
![image.png](https://pic.leetcode-cn.com/4c36364953205931041745fe6f9d5fa621436089e7505053fb2ee40a3256ee1f-image.png)
这个操作的具体代码如下：
```java
public void push_back(int value) {
    while(max_head<max_tail&&value>=val[max[max_tail-1]]) {
    	max_tail--;
    }
	//将value的下标存放在max中
    max[max_tail++]=tail;
	//存放val
    val[tail++]=value;
}
```
### 代码

```java
class MaxQueue {
	//存放值
	private int[] val;
	//队头指针
	private int head;
	//队尾指针
	private int tail;
	//存放val数组中可能“最大值”的下标
	private int[] max;
	//最大值数组的头指针
	private int max_head;
	//最大值数组的尾指针
	private int max_tail;
    public MaxQueue() {
    	//未采用动态扩容的方式
    	val=new int[10000];
    	max=new int[10000];
    	head=0;
    	tail=0;
    	max_head=0;
    	max_tail=0;
    }
    /**
     * 返回当前数列中的最大值
     * @return
     */
    public int max_value() {
		//判断队列是否为空
    	if(head==tail) return -1;
    	return val[max[max_head]];
    }
    /**
     * 队尾插入一个元素
     * @param value
     */
    public void push_back(int value) {
    	while(max_head<max_tail&&value>=val[max[max_tail-1]]) {
    		max_tail--;
    	}
    	max[max_tail++]=tail;
    	val[tail++]=value;
    }
    /**
     * 队头弹出一个元素
     * @return
     */
    public int pop_front() {
    	if(head==tail) return -1;
    	//要弹出的元素的下标是否为max数组的第一个值
    	if(head==max[max_head]) max_head++;
    	return val[head++];
    }
}

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
```