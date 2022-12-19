### 解题思路
通过样例可以看出，搜索到当前文件时，只需要确定对应当前文件的目录就行，同一层目录只需要维护最新的目录字符串长度就行，记录下了每一层的目录字符串长度，当前路径的字符串长度为0层~当前各层目录字符串长度之和加上层数（层数对应‘\’的数目，我的层数从0开始）。
![J5ODM6NU8}B`~69MVQJLY(T.png](https://pic.leetcode-cn.com/448ea944c5cfeb02624cf7ebb551af8b6969c9bb50aa507433e56cf4a73880b7-J5ODM6NU8%7DB%60~69MVQJLY\(T.png)


### 代码

```cpp
class Solution {
public:
    int lengthLongestPath(string input) {
	int len = input.length();
	vector<int> v;
	int res = 0,cnt = 0,layer = 0,sum = 0,flag = 0,MAX = -1;
	for(int i = 0;i < len;++i){
			if(input[i]=='\t'){
				layer++;
				cnt = 0;
			}
			else if(input[i]=='\n'){
				if(layer>MAX){
					v.push_back(cnt);
					MAX = layer;
				}
				else {
					v[layer] = cnt;
				}
				if(flag){
					sum = 0;
				for(int j = 0;j <= layer;++j){
					sum += v[j];
				}
				res = max(res,sum+layer);
                flag = 0;
			}
				cnt = 0;
				layer = 0;
			}
			else {
				cnt ++;
				if(input[i]=='.')flag = 1; 
			}
 	}
	if(cnt != 0&& flag ){
		if(layer>MAX){
					v.push_back(cnt);
					MAX = layer;
		}
		else {
			v[layer] = cnt;
			}
		sum = 0;
		for(int j = 0;j <= layer;++j){
			sum += v[j];
		}
		res = max(res,sum+layer);
        // cout << res << endl;
	}
	return res;
}

};
```