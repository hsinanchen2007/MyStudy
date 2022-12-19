```
class ConSum     //用构造函数实现
{
public:
	ConSum()      //利用创建n个对象来调n次构造函数
	{
		n++;
		sum += n;
	}
	static int GetSum()
	{
		return sum;
	}
	static int n;   //用静态数据存储才可达到累加效果
	static int sum;
};

int ConSum::n = 0;       //初始化静态成员
int ConSum::sum = 0;
class Solution {
public:
    int sumNums(int n) {
        ConSum::n = 0;       //初始化静态成员
        ConSum::sum = 0;
        ConSum *a = new ConSum[n];
	return ConSum::GetSum();   //访问静态成员函数必须用域作用符
    }
};
```
