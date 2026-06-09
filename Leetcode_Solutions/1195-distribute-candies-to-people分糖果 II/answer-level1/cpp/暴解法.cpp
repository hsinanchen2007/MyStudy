### 解题思路
一直分，直到没有糖果为止。

### 代码

```cpp
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> arr(num_people, 0);
        int n = num_people;
        int i = 0;
        while(candies != 0){
            arr[i % num_people] += min(candies,i + 1);
            candies -= min(candies, i + 1);
            i++;
        }
     ///   cout<<arr[1];
    return arr;
    }
};
```