```
struct MyStruct
{
  bool operator () (const vector<int>& v1, const vector<int>& v2) {
    return (v1[0] + v1[1]) < (v2[0] + v2[1]);
  }
};

//bool operator < (const vector<int>& v1, const vector<int>& v2) {
//  return (v1[0] + v1[1]) < (v2[0] + v2[1]);
//}

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> res;
    priority_queue<vector<int>, vector<vector<int>>, MyStruct> heap;
    //priority_queue<vector<int>, vector<vector<int>>, less<vector<int>>> heap;
    if (k <= 0 || nums1.empty() || nums2.empty()) {
      return res;
    }
    for (size_t i = 0; i < nums1.size(); i++)
    {
      for (size_t j = 0; j < nums2.size(); j++) {
        if (heap.size() < k) {
          heap.push({ nums1[i],nums2[j] });
        }
        else {
          if (nums1[i] + nums2[j] <= heap.top()[0] + heap.top()[1]) {
            heap.pop();
            heap.push({ nums1[i], nums2[j] });
          }
          }
      }
    }
    while (!heap.empty()) {
      res.push_back(heap.top());
      heap.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
```
