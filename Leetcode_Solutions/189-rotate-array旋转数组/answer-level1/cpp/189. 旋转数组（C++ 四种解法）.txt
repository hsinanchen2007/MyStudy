# 189. 旋转数组
**方法一:利用辅助空间**

```
//辅助空间
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int length = nums.size();
		vector<int> temp(length);
        for (int i = 0; i < length; ++i ){
			temp[(i+k)%length] = nums[i];
		}
		nums = temp;
    }
};

```
**方法二:暴力法**
时间可能会超出
```
//k次循环
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int length = nums.size();
		int temp;
        for (int i = 0; i < k; ++i ){
			temp = nums[length-1];
			for(int j = length-2; j >= 0; --j){
				nums[j+1] = nums[j];
			}
			nums[0] = temp;
		}
    }
};
```
**方法三:循环替换**
```
//循环替换
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
        int count = 0;
        for (int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
        }
    }
};
```
**方法四:数组翻转**
```
//翻转
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		reverse(nums.begin(),nums.end());
		reverse(nums.begin(),nums.begin()+k);
		reverse(nums.begin()+k,nums.end());
    }
};
```
