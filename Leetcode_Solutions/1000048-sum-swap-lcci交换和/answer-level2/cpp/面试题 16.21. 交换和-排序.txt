方法一：首先排序，然后依次遍历两个数组的每个元素，时间复杂度O(Nlog(N))
```
class Solution {
private:
	int Sum(vector<int>& a) {
		int s = 0;
		for (auto& i : a) {
			s += i;
		}
		return s;
	}
public:
	vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
		if (array1.size() == 0 || array2.size() == 0) {
			return {};
		}
		int dif = Sum(array1) - Sum(array2);
		if (abs(dif) & 1 == 1) {
			return {};
		}
		sort(array1.begin(), array1.end());
		sort(array2.begin(), array2.end());
		int count1 = array1.size();
		int count2 = array2.size();
		dif /= 2;
		int l = 0;
		int r = 0;
		while (l < count1 && r < count2) {
			if (array1[l] < array2[r] + dif) {
				l++;
			} else if (array1[l] > array2[r] + dif) {
				r++;
			} else {
				return vector<int>({array1[l],array2[r]});
			}
		}

		return {};
	}
};
```
方法二：改进查找方法，将数组二改造为集合，遍历数组1时直接查找结合中是否存在该数，时间复杂度最差为O(Nlog(N))
```
class Solution {
private:
	int Sum(vector<int>& a) {
		int s = 0;
		for (auto& i : a) {
			s += i;
		}
		return s;
	}
public:
	vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
		if (array1.size() == 0 || array2.size() == 0) {
			return {};
		}
		int dif = Sum(array1) - Sum(array2);
		if (abs(dif) & 1 == 1) {
			return {};
		}
        set<int> s2;
        for(auto& i:array2){
            s2.insert(i);
        }
        dif/=2;
        for(auto &i:array1){
            if(s2.find(i-dif)!=s2.end()){
                return vector<int>({i,i-dif});
            }
        }

		return {};
	}
};
```
