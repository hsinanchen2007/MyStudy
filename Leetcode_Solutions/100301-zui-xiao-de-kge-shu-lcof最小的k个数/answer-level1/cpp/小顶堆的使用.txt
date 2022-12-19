### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int,vector<int>, greater<int> > book;
        // sort(arr.begin(),arr.end());
        for(int x:arr){
            book.push(x);
        }
        vector<int> res;
        int index=0;
        while(k--){
            res.push_back(book.top());
            book.pop();
        }
        return res;
        //尝试采用小顶堆
    }
};
```