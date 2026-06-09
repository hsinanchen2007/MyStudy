### 解题思路
1、标记()的深度，(加1，)减1,同时统计最大深度。
2、将深度大于最大深度一半的()，标记为1，其它的标记为0;
### 代码

```cpp
class Solution {
public:
vector<int> maxDepthAfterSplit(string seq) {
    int cnt = 0;
    int depth = 0;
    vector<int> vec(seq.size(), 0);

    for(int i = 0; i < seq.size(); i++){
        if(seq[i] == '('){
            cnt++;
            depth = max(depth, cnt);
            vec[i] = cnt;
        } else {
            vec[i] = cnt;
            cnt--;
        }
    }
    
    depth /= 2;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] <= depth)
            vec[i] = 0;
        else
            vec[i] = 1;
    }

    return vec;
}
};
```