### 解法Ⅰ 暴力
```cpp
class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int ans = arr1.size();
		for (int a1 : arr1) {
			for (int a2 : arr2) {
				if (abs(a1 - a2) <= d) {
					--ans;
					break;
				}
			}
		}
		return ans;
	}
};
```

### 解法Ⅱ 二分法
```cpp
class Solution {
public: 
    int biSch1(int l, int r, vector<int> arr, int target) {
        if (l >= r) return l;

        int m = (l + r) >> 1;
        if (arr[m] == target) return m;
        return arr[m] < target ? biSch1(m + 1, r, arr, target) : biSch1(l, m, arr, target);
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0, n = arr2.size() - 1;
        sort(arr2.begin(), arr2.end());
        for (auto a : arr1) {
            int idx = biSch1(0, n, arr2, a);
            if (abs(arr2[idx] - a) <= d) continue;
            else {
                if (abs(arr2[max(0, idx - 1)] - a) <= d) continue;
                else if (abs(arr2[min(idx + 1, n)] - a) <= d) continue;
                ++ans;
            }
        }
        return ans;
    }
};
```