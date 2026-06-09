### 解题思路
（a）求整个数组的和sum1；
（b）顺序累加数组，记录最大值，当值小于零时抛弃之前累加值，并置零。继续累加，直至序列结束；sum3为最大值
（c）k = 1 时，返回b步骤的最大值；
（d）k = 2 时，在b的基础上复制一次序列，返回最大值；
（e）k > 2 时，若sum1>0,返回d的最大值+（k-2）*sum1，若sum1>0,返回d的最大值。
PS 代码中d e 两步一起写。 对计算d步骤时
### 代码

```cpp
class Solution {
public:
   int kConcatenationMaxSum(vector<int>& arr, int k) {
		int sum1 = 0; //整个数组求和
		int sum2 = 0;  
		int sum3 = 0;
		for (int i = 0; i < arr.size(); i++) {
            sum1 += arr[i];
			sum2 += arr[i];
			if (sum2 < 0) {
				sum2 = 0;
			}
			else {				
				if (sum2 > sum3) {
					sum3 = sum2;
				}
			}
		}	
		if (k == 1) {
			return sum3;
		}
		int sumleft = sum3;
		int sumright = 0;
		if (k >= 2){
            if(sumleft<sum1){
                long sum11 = sum1 % 1000000007;			    
                return (k * sum11 )% 1000000007;
            }
			int maxij=0;
			for (int i = 0; i < arr.size(); i++) {
				sum2 += arr[i];
				if (sum2 < 0) {
					sum2 = 0;
					break;
				}
				else {					
					if (sum2 > sum3) {
						sum3 = sum2;
					}					
				}
			}
            sumright = sum3;
			if (sum1 > 0){
				maxij = sumleft + sum1;
				maxij=maxij > sumright ? maxij : sumright;
			} 
			else {
				maxij=(sumleft > sumright) ? sumleft : sumright;
			}
            long sum11 = sum1 % 1000000007;
			long max = ((k - 2) * sum11 )% 1000000007;
			return (sum1 > 0) ? (maxij + max) : maxij;
		}
		return -1;
	}
};
```