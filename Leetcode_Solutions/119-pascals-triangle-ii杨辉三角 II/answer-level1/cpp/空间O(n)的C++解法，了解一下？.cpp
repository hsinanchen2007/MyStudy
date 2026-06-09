### 解题思路
方法是用两个for循环，第一个是建立杨辉三角的行，第二个是每行的列。额外的两个int变量t1,t2,用来存当前计算的列的前两项t1=Y[i-1],t2=Y[i];Y[i]=t1+t2;然后让t1与t2都向前移动一位，t1=t2;t2=Y[i+1];(注意i+1是否数组越界)。

### 代码

```cpp
class Solution{
public:
	vector<int> getRow(int rowIndex){
		vector<int> Y;							//初始化
		for (int i = 0; i <=rowIndex; i++) {	//循环0~rowIndex次，
			int t1,t2;							//用两个额外的变量存Y[i-1]与Y[i]；防止Y[i]=Y[i-1]+Y[i]时Y[i]被覆盖；
			if (i == 0) {
				Y.push_back(1);
			}
			if (i == 1) {
				Y.push_back(1);
			}
			if (i > 1) {
				t1 = Y[0];						 //从Y[0]和Y[1]开始计算
				t2 = Y[1];
				for (int j = 1; j <= i; j++)
				{
					if (j == i) {
						Y.push_back(1);			  //j==i时是结尾push_back(1)
					}
					else {
						Y[j] = t1 + t2;			  //其它项都是Y[i]=Y[i+1]+Y[i];也就是当前项与前一项的和再存回当前项
						t1 = t2;				  //t1向前移动一位
						if ((j + 2) > i) {		  //防止数组越界
							continue;
						}
						else {
							t2 = Y[j + 1];		   //t2向前移动一位，在确保不会越界。
						}
					}
				}
			}
		}
		return Y;
	}
};
```