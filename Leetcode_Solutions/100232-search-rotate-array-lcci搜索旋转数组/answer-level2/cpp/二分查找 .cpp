二分查找太容易写崩了...很烦
```
class Solution {
public:
	int search(vector<int>& arr, int target) {
		int begin = 0;
		int end = arr.size()-1;

		while (begin < end) {
			int mid = (begin + end) / 2;
			if (arr[mid] == target) {
				while (mid > 0 && arr[mid - 1] == arr[mid]) mid--;
				return mid;
			}
			if (arr[mid] > arr[begin]) {
				//说明左边是顺序数组，右边是旋转数组
				if (arr[begin] <= target && target < arr[mid]) end = mid;
				else begin = mid + 1;
			}
			else if( arr[mid] < arr[end]){
				//说明左边是旋转数组，右边是顺序数组
				if (arr[mid] < target && target < arr[end]) begin = mid + 1;
				else end = mid;
			}
			else {
				if (arr[end] == target) return end;
				else return -1;
			}
		}
		return -1;
	}
};
```
