### 解题思路
快排的思想，分治法

### 代码

```cpp
//分治法
class Solution {
    vector<vector<int>> points;
    int target;
private:
    int dist(int i) {
        return points[i].front() * points[i].front() + points[i].back() * points[i].back();
    }

    int partition(int low, int high) {
        int pivot = dist(low);
        vector<int> pivotPoint = points[low];

        while (low < high) {
            while (low < high && dist(high) > pivot) {
                high--;
            }
            points[low] = points[high];

            while (low < high && dist(low) <= pivot) {
                low++;
            }
            points[high] = points[low];
        }
        points[low] = pivotPoint;

        return low;
    }

    void dfs(int low, int high, int k) {
        if (low >= high) {
            return;
        }

        int pivot = partition(low, high);

        if (pivot == target) {
            return;
        } else if (pivot < target) {
            return dfs(pivot + 1, high, target);
        } else {
            return dfs(low, pivot - 1, target);
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        this->points = points;
        this->target = K - 1;

        dfs(0, points.size() - 1, target);

        vector<vector<int>> result;

        for (int i = 0; i < K; ++i) {
            result.push_back(this->points[i]);
        }

        return result;
    }
};
```