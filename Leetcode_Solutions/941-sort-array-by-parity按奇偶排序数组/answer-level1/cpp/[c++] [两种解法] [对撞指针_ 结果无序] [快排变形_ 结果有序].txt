### 解题思路
解法1：对撞指针
![image.png](https://pic.leetcode-cn.com/2c82cf9e81193d492b782f92d72e47ad809db2b5877fe9610f167a06d4bf2813-image.png)
解法2：快排思想

### 代码
解法1
```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size()==0){
            return {};
        }
        int left=0;
        int right=A.size()-1;
        while(left<right){
            //向后移动，是奇数就跳过
            while((left<right)&&(A[left]&0x1)==0){
                left++;
            }
            //向前移动，是偶数就跳过
            while((left<right)&&(A[right]&0x1)!=0){
                right--;
            }
            if(left<right){
                swap(A[left],A[right]);
            }
        }
        return A;
    }
};
```
解法2
```
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int len = A.size();
		if (len <= 1) { // 数组空或长度为1
			return A;
		}

		int i = 0;
		while (i < len) {
			int j = i + 1;
			if (j < len && A[i] % 2 != 0) { // a[i]为奇数，j前进，直到替换
				while (A[j] % 2 != 0) { // j为奇数，前进
					if (j == len - 1)// i为奇数，j也为奇数，一直后移到了末尾，证明后面都是奇数
						return A;
					j++;
				}
				// 此时j为偶数
				int count = j - i;
				int temp = A[i];
				A[i] = A[j];
				while (count > 1) {
					A[i + count] = A[i + count - 1];//数组后移
					count--;
				}
				A[i + 1] = temp;
			}
			i++;
		}
		return A;
	}
};
```
