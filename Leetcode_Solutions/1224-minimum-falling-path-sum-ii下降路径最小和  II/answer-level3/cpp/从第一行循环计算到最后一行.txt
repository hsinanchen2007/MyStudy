### 解题思路
搜索每一行最小的两位数，并且记录其索引值，

### 代码

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int arrsize0 = arr.size();//行数
		int arrsize1 = arr[0].size();//列数
		if (arrsize0 == 1) {
			return arr[0][0];
		}
		vector<int> temp_row1 = arr[0];
		int temp_0[2]={0,0}; ////存储 累计 行和 最小 的两个数 【最小，第二小】
		int temp_1[2]={0,0};//存储每行最小的两个数 【最小，第二小】
		int temp_2[2]={0,0};
		int cnt11 = -1; //存储累计 行和 最小 的两个数 的 列索引
		int cnt22 = -1;
		int cnt1=0; // 存储每行最小的两位数的列索引
		int cnt2=1;
		for (int i = 0; i < arrsize0; i++) {
			temp_row1 = arr[i]; //取第i行 // 找出最小的两位数 仅仅找出两位数，不必使用向量全部排序；
			temp_1[0] =  temp_row1[0];
			temp_1[1] =  temp_row1[1];
            cnt1 = 0;
			cnt2 = 1;   
			for (int j = 1; j < arrsize1; j++) {
				if (temp_row1[j] <= temp_1[0]) {
					temp_1[1] = temp_1[0];
					temp_1[0] = temp_row1[j];
					cnt2 = cnt1;
					cnt1 = j;
				}
				else if (temp_row1[j] < temp_1[1]) {
					temp_1[1] = temp_row1[j];
					cnt2 = j;
				}
			} 
            //当前行加 上一次最小的两个值，列数索引相等不能加
			if (cnt1 != cnt11) {
				temp_2[0] = temp_1[0] + temp_0[0];
			}
			else {
				temp_2[0] = temp_1[0] + temp_0[1];
			}
			if (cnt2 != cnt11) {
				temp_2[1] = temp_1[1] + temp_0[0];
			}
			else {
				temp_2[1] = temp_1[1] + temp_0[1];
			}
            // 更新索引，并使 存贮格式为【最小，第二小】
            if (temp_2[0] < temp_2[1]) {
				cnt11 = cnt1;
				cnt22 = cnt2;
			}
			else {
				cnt11 = cnt2;
				cnt22 = cnt1;
				int temp = temp_2[0];
				temp_2[0] = temp_2[1];
				temp_2[1] = temp;
			}
			temp_0[0] = temp_2[0];
            temp_0[1] = temp_2[1];
		}
		return temp_0[0];
    }
};
```