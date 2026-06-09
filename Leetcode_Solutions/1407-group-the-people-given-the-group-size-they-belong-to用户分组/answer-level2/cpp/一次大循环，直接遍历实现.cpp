
思路：
  如果当前分组的元素个数为n，那么该分组内所有元素所在分组的的元素个数都是n。
  代码实现：遍历到一个元素的所在分组元素数为n时，遍历后续n个分组元素数为n的元素，作为一组返回值。
  
减少空间复杂度的一个方法：直接修改输入数据 -- 当某个元素被选出来后，分组元素数改为0

```
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        
        for (int i = 0; i < groupSizes.size(); i++) {
            vector<int>cur;
            int dstSize = groupSizes[i];            
            int j = i;
            if (dstSize > 0) {
                while (cur.size() < dstSize) {
                    if (dstSize == groupSizes[j]) {
                        groupSizes[j] = 0;
                        cur.push_back(j);
                    }
                    j++;
                }
                res.push_back(cur);
            }
        }
        
        return res;
    }
}; 

```
