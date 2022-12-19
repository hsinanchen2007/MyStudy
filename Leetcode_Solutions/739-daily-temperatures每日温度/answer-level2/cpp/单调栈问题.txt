### 解题思路
栈中储存的是温度序号而不是温度值，这样做便于统计相隔天数

### 代码

```cpp
template<typename T>
class MyStack
{
public:
	MyStack(int size);
	int stackSize();
	void Enstack(T x);
	bool Destack();
	T Behind();
	bool IfEmpty();
	~MyStack();
private:
	T* data;
	int rear;
};

template<typename T>
MyStack<T>::MyStack(int size)
{
	data = new T[size + 1];
	rear = -1;
}

template<typename T>
int MyStack<T>::stackSize()
{
	return rear + 1;
}

template<typename T>
bool MyStack<T>::IfEmpty()
{
	if (rear < 0)
		return true;
	else
		return false;
}

template<typename T>
bool MyStack<T>::Destack()
{
	if (IfEmpty())
		return false;
	rear = (rear - 1);
	return true;
}

template<typename T>
void MyStack<T>::Enstack(T x)
{
	rear = (rear + 1);
	data[rear] = x;
}

template<typename T>
T MyStack<T>::Behind()
{
	if (IfEmpty())
		return false;
	T temp = data[rear];
	return temp;
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[] data;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
	vector<int>res(T.size(), 0);
	MyStack<int>stack(T.size());
	stack.Enstack(0);
	for (int i = 1; i < T.size(); i++)
	{
		if (T[i] > T[stack.Behind()])
		{
			while (T[stack.Behind()] < T[i]&&!stack.IfEmpty())
			{
				res[stack.Behind()] = i - stack.Behind();
				stack.Destack();
			}
			stack.Enstack(i);
		}
		else
		{
			stack.Enstack(i);
		}
	}
	return res;
}
};
```