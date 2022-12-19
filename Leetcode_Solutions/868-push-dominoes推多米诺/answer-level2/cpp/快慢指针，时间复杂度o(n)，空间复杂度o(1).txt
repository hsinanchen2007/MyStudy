### 解题思路
首先定义4个指针，快指针front，慢指针rear。另外两个辅助指针用于处理左右夹击的情况。
利用快慢指针遍历一次字符串，快指针先走，有以下几种情况：
1.快指针为L，慢指针为L或.。此时只需要将慢指针按照步长为1移到快指针处，并将所经过的位置改写成L。
2.快指针为L，慢指针为R。此时需要两侧夹击，改写两个指针内测的字符串，此时引入left和right指针辅助实现。
3.快指针为R，慢指针为R或.。此时只需要将慢指针按照步长为1移到快指针处，并将所经过的位置改写成R。
4.快指针为R，慢指针为L。此时中间部分不受影响，直接让慢指针移到快指针位置，开始下一次循环。
还需要注意一些特殊情况的处理，例如..R..
### 代码

```cpp
class Solution {
public:
string pushDominoes(string dominoes) {

	int front=0, rear=0, left=0, right = 0;
	int len = dominoes.size();
	while (front < len) {
		if (dominoes[front] == '.') front++;
		if (front == rear) front++;
		if (dominoes[front] == 'L' && dominoes[rear] != 'R')
		{
			while (front != rear)
			{
				dominoes[rear] = 'L';
				rear++;
			}
		}

		else if (dominoes[front] == 'L' && dominoes[rear] == 'R')
		{
			left = rear;
			right = front;
			while (left < right)
			{
				dominoes[left] = 'R';
				left++;
				dominoes[right] = 'L';
				right--;
			}
			rear = front;
		}

		else if(dominoes[front] == 'R' && dominoes[rear] == 'R')
		{
			while (rear != front)
			{
				dominoes[rear] = 'R';
				rear++;
			}

		else if (dominoes[front] == 'R' && dominoes[rear] != 'R')
		{
			rear = front;
		}

		}
		else if (front == len - 1 && dominoes[rear] == 'R')
		{
			while (rear < front)
			{
				rear++;
				dominoes[rear] = 'R';
			}
		}
	}
	return dominoes;
}
};
```