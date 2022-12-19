### 思路
本题一开始，一直纠结于一次遍历的算法，结果发现要考虑很多特殊情况：如比较波峰波谷时需不需要更新糖果值。
后来，看了题解发现，两次遍历（从左开始和从右开始）的速度更快，且代码简洁。
但以下还是呈现一次遍历的思路。
（总感觉代码不够简洁，请大佬们多多指教）

### 代码
```
int candy(vector<int>& ratings) {
	int result = 1;//先添加1作为第一个元素的初步糖果
	int down_num = 1;//记录连续下降的个数
	int former=1 ;//记录波峰或前一个人的糖果数

	for (int i = 1; i < ratings.size(); i++)
	{
		if (ratings[i] > ratings[i-1])
		{
			if (former < down_num)//上升要求的波峰糖果数小于下降要求的糖果数：更新
			{
				result = result - former + down_num;
				former = 1;//前一个人的糖果数
			}
			else if (former >= down_num && down_num != 1)
			{
				former = 1;//前一个人的糖果数
			}
			former++;
			result += former;
			down_num = 1;
		}
		else if (ratings[i] == ratings[i - 1])
		{
			if (former < down_num)//上升要求的波峰糖果数小于下降要求的糖果数：更新
			{
				result = result - former + down_num;
			}
			former = 1;
			result += former;
			down_num = 1;
		}
		else //ratings[i]<ratings[i-1]单调下降
		{
			result += down_num;//此时，相当于补一个down_num
			down_num++;
		}
	}
	if(down_num!=1&&former<down_num)
		result = result - former + down_num;

	return result;

}
```
