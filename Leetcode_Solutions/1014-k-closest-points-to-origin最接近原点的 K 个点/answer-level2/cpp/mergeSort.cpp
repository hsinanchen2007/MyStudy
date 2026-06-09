### 解题思路
利用距离构建排序，排序用的mergeSort，同时构建结构体将距离和index绑定，这样就可以求出距离前K的index，根据index再去求数组；

### 代码

```cpp
struct kDistance {
    int distance;
    int index;
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<kDistance> distance;
        for (int i = 0; i < points.size(); i++) {
            kDistance k;
            k.distance = pow(points[i][0], 2) + pow(points[i][1], 2);
            k.index = i;
            distance.push_back(k);
        }
        vector<kDistance> tmp(distance.size());
        mergeSort(distance, tmp, 0, distance.size());
        vector<vector<int>> res;
        for (int i = 0; i < K; i++) {
            res.push_back(points[distance[i].index]);
        }
        return res;
    }

private:
    void mergeSort(vector<kDistance>& arr, vector<kDistance>& tmp, int start, int end) {
        if (start + 1 == end) return;
        int middle = (start + end) / 2;
        mergeSort(arr, tmp, start, middle);
        mergeSort(arr, tmp, middle, end);
        int i = start, j = middle, z = start;
        while (i < middle && j < end) {
            if (arr[i].distance <= arr[j].distance) {
                tmp[z] = arr[i];
                i++;
                z++;
            } else {
                tmp[z] = arr[j];
                j++;
                z++;
            }
        }
        while(i < middle) {
            tmp[z] = arr[i];
            i++;
            z++;
        }
        while(j < end) {
            tmp[z] = arr[j];
            j++;
            z++;
        }
        for (int i = start; i < end; i++) {
            arr[i] = tmp[i];
        }
        return;
    }
};
```