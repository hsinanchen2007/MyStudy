直接考虑一个sideLength * sideLength的正方形 我们需要在正方形里面取maxOnes个点

当i,j处的点被选取后 所有坐标为i±k1\*sideLength,j±k2\*sideLength的点都可以写1

这样一来就可以遍历一个正方形 算出每一个点最后能写上多少1

最后排序取前maxOnes个即可

```cpp
class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> data;
        for (int i = 0; i < sideLength; ++i)
            for (int j = 0; j < sideLength; ++j)
                data.push_back(ceil((double)(width - i) / sideLength) * ceil((double)(height - j) / sideLength));
        sort(data.begin(), data.end(), greater<int>());
        int result = 0;
        for (int i = 0; i < maxOnes; ++i)
            result += data[i];
        return result;
    }
};
```
