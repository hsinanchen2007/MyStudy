### 解题思路
此处撰写解题思路
	// 数组尾到 i 的总和
	int temp = 0;
	// 数组头到 i 的总和
	int temp_tar = 0;
	// 定义vector用来存储成功的次数
	vector<int>success;
	// 解题思路: 循环中一定不包含当前位置(i)即 i<current || current>i 经过循环迭代使用if得到结果
	// 成功的话 将 i 送入 vector
			success.push_back(i);
	// 假如success容器中元素>=1 则肯定至少有两个元素，根据本题规则 只需返回success容器中的第一个元素
	if (success.size()>=1) {
		return success[0];
	}
	
	// 假如都不成立，则返回-1(条件不成立 退出方法体)
	return -1;
### 代码
	
```
代码块
```
int pivotIndex(vector<int>& vec) {
	// 数组尾到 i 的总和
	int temp = 0;
	// 数组头到 i 的总和
	int temp_tar = 0;
	// 定义vector用来存储成功的次数
	vector<int>success;
	// 解题思路: 循环中一定不包含当前位置(i)即 i<current || current>i 经过循环迭代使用if得到结果
	for (int i = 0; i < vec.size(); i++) {
		temp = 0;
		temp_tar = 0;
		for (int j = (vec.size() - 1); j > i; j--) {
			// if根本不需要，因为根本不会超过vector边界
			if (j < 0 || j>(vec.size())) {
				continue;
			}
			temp += vec[j];
		}
		for (int k = 0; k < i; k++) {
			// if根本不需要，因为根本不会超过vector边界
			if (k < 0 || k>(vec.size())) {
				continue;
			}
			temp_tar += vec[k];
		}
		if (temp == temp_tar) {
			// 成功的话 将 i 送入 vector
			success.push_back(i);
		}
	} // 假如success容器中元素>=1 则肯定至少有两个元素，根据本题规则 只需返回success容器中的第一个元素
	if (success.size()>=1) {
		return success[0];
	}
	// 假如都不成立，则返回-1(条件不成立 退出方法体)
	return -1;
}
```cpp
class Solution {
public:
  
int pivotIndex(vector<int>& vec) {
	// 数组尾到 i 的总和
	int temp = 0;
	// 数组头到 i 的总和
	int temp_tar = 0;
	// 定义vector用来存储成功的次数
	vector<int>success;
	// 解题思路: 循环中一定不包含当前位置(i)即 i<current || current>i 经过循环迭代使用if得到结果
	for (int i = 0; i < vec.size(); i++) {
		temp = 0;
		temp_tar = 0;
		for (int j = (vec.size() - 1); j > i; j--) {
			temp += vec[j];
		}
		for (int k = 0; k < i; k++) {
			temp_tar += vec[k];
		}
		if (temp == temp_tar) {
			// 成功的话 将 i 送入 vector
			success.push_back(i);
		}
	} // 假如success容器中元素>=1 则肯定至少有两个元素，根据本题规则 只需返回success容器中的第一个元素
	if (success.size()>=1) {
		return success[0];
	}
	// 假如都不成立，则返回-1(条件不成立 退出方法体)
	return -1;
}
};
```