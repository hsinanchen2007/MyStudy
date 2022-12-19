### 解题思路
1.本来是想用DFS+递归回溯求出第k个组合，但是超时了
2.使用C++提供的函数库：
1）next_permutation：表示当前排列的下一个排列
2）prev_permutation：表示当前排列的上一个排列

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k)
    {
		string str;
		for(int i = 1;i<=n;i++){
			str.push_back(i+'0');
		}

		for(int i = 1;i<k;i++){
			next_permutation(str.begin(),str.end());
		}

        return str;
    }
};
```