### 解题思路
stack1负责插入，stack2负责删除
举例如下图所示
![image.png](https://pic.leetcode-cn.com/9b6b70a43b924701001198626738f66db6ef978a738974ea2f1de009ad25a9ae-image.png)
### 代码

```cpp
class CQueue {
public:
	stack<int> s1,s2;//s1负责插入，s2负责删除
	CQueue() {

	}
	//队列尾部插入数据
	void appendTail(int value) {
		s1.push(value);
	}
	//队列头部删除
	int deleteHead() {
		if (s2.empty())//s2为空，则判断s1是否为空，不为空，将s1中数据压入到s2中
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		if (s2.empty())//如果s2压入s1数据后仍然为空
			return -1;
		//删除首元素
		int value=s2.top();
		s2.pop();
		return value;
	}
};
```