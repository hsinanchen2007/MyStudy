### 代码

```cpp
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int W = sqrt(area);
        while (area % W != 0) --W;
        return {area / W, W};
    }
};
```
![image.png](https://pic.leetcode-cn.com/8ab323803579147d4fe0dbd20b5a9e950ee50b74800f8678964c7db5efbc2bb7-image.png)
