### 解题思路
此处撰写解题思路

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
		return 0;
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
    int evalRPN(vector<string>& tokens) {
	if (tokens.size() == 1)
		return atoi(tokens[0].c_str());
	else
	{
		MyStack<int> stk(tokens.size());
		int temp_first = 0;
		int temp_sec = 0;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
				stk.Enstack(atoi(tokens[i].c_str()));
			else
			{
				int cal = 0;
				cal = tokens[i][0];
				temp_sec = stk.Behind();
				stk.Destack();
				temp_first = stk.Behind();
				stk.Destack();
				switch (cal)
				{
				case 43:
					stk.Enstack(temp_first + temp_sec);
					break;
				case 45:
					stk.Enstack(temp_first - temp_sec);
					break;
				case 42:
					stk.Enstack(temp_first * temp_sec);
					break;
				case 47:
					stk.Enstack(temp_first / temp_sec);
					break;
				}
			}
		}
		return stk.Behind();
	}
    }
};
```