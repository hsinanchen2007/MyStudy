### 解题思路
一对猫的队列，分别保存猫的数据和猫的入住的时间（index），一对狗的队列，分别保存狗的数据和狗的入住的时间（index）

### 代码

```cpp
class AnimalShelf {
public:
	queue<pair<int, int>> catQueue;
	queue<int>queueCat;
	queue<pair<int, int>> dogQueue;
	queue<int>queueDog;
	int index = 0;

	AnimalShelf() {

	}

	void enqueue(vector<int> animal) {
		if (animal[1] == 0)
		{
			catQueue.push(make_pair(animal[0], animal[1]));
			index++;
			queueCat.push(index);
		}
		else
		{
			dogQueue.push(make_pair(animal[0], animal[1]));
			index++;
			queueDog.push(index);
		}
	}

	vector<int> dequeueAny() {
		if (!dogQueue.empty() && catQueue.empty())
		{
			pair<int, int> temp = dogQueue.front();
			dogQueue.pop();
			queueDog.pop();
			return { temp.first,temp.second };
		}
		if (!catQueue.empty() && dogQueue.empty())
		{
			pair<int, int> temp = catQueue.front();
			catQueue.pop();
			queueCat.pop();
			return { temp.first,temp.second };
		}
		if (!catQueue.empty() && !dogQueue.empty())
		{
			if (queueDog.front() < queueCat.front())
			{
				pair<int, int> temp = dogQueue.front();
				dogQueue.pop();
				queueDog.pop();
				return { temp.first,temp.second };
			}
			else if (queueDog.front() > queueCat.front())
			{
				pair<int, int> temp = catQueue.front();
				catQueue.pop();
				queueCat.pop();
				return { temp.first,temp.second };
			}
		}
		return { -1,-1 };

	}

	vector<int> dequeueDog() {
		if (!dogQueue.empty())
		{
			pair<int, int> temp = dogQueue.front();
			dogQueue.pop();
			queueDog.pop();
			return { temp.first,temp.second };
		}
		return { -1,-1 };
	}

	vector<int> dequeueCat() {
		if (!catQueue.empty())
		{
			pair<int, int> temp = catQueue.front();
			catQueue.pop();
			queueCat.pop();
			return { temp.first,temp.second };
		}
		return { -1,-1 };
	}
};

```