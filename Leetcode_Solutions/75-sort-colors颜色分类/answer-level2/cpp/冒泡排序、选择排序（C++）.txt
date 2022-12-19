# 一、冒泡法
+ 原理：相邻两个数进行比较，如果前面比后面的大，则进行交换。（稳定排序）
+ 学习冒泡法的同时，让我想起了神秘巨星的一句台词 
 **你会成为巨星的，就像苏打水里的气泡，浮上来完全靠自己。（神秘巨星）**
```C++
void sortColors(vector<int>& nums) {
		for (int i = 0; i < nums.size()-1; i++) {
			for (int j = 0; j < nums.size()-i-1; j++) {
				if (nums[j] > nums[j+1]) {
					//swap(nums[j], nums[j + 1]);
					int temp = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = temp;
				}
				
			}
		}
	
	}
```
### 二、选择排序
+ 原理：第一次从待排序的数据元素中，选出最小（大）的的一个元素，与起始位置相交换，然后再依此类推直至拍完。
```C++
void sortColors2(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			int min = i;
			for (int j = i+1; j < nums.size(); j++) {
				if (nums[min] > nums[j]) {
					min = j;
				}

			}
			if (min != i) {
				int temp = nums[i];
				nums[i] = nums[min];
				nums[min] = temp;
			}
		}

	}
```
### 三、其他方案
一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
```C++
void sortColors3(vector<int>& nums) {
		vector<int>::iterator it;
		int i = 0, j = 0, k = 0;
		for (it = nums.begin(); it != nums.end();it++) {
			if (*it == 0) {
				i++;
			}else if(*it == 1){
				j++;
			}
			else if (*it == 2) {
				k++;
			}
		}
		for (it = nums.begin(); it != nums.end(); it++) {
			if (i != 0) {
				i--;
				*it = 0;
			}
			else if (j != 0) {
				j--;
				*it = 1;
			}
			else if (k != 0) {
				k--;
				*it = 2;
			}
		}

	}
```