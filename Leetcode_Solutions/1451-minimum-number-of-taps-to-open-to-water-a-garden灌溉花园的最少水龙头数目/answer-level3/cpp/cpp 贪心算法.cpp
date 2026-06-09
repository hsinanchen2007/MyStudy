### 解题思路
begin记录上次灌溉结束位置，farthest记录本次可灌溉最远位置

### 代码

```cpp
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int begin=0;int farthest=0;int count=0;
        while (farthest<(ranges.size()-1)){
            if (begin>=farthest and count!=0) return -1;//说明上次遍历搜索并没有发现可灌溉的更远位置，无法全部灌溉
            begin=farthest;//begin赋为上次灌溉结束的地方 #这里吐槽下这题两片灌溉区域的始末得重叠，我之前写得begin=farthest+1结果有一题出错
            for (int i=begin;i<ranges.size();i++){
                if (i-ranges[i]<=begin){
                    if (i+ranges[i]>farthest) farthest=i+ranges[i];
                }
            }
            count++;
        }
        return count;
    }
};
```