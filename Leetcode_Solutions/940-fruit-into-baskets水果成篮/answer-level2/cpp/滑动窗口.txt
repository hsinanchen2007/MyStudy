### 解题思路
与第三题Longest Substring with K Distinct Characters (medium)类似
但不同之处在于 3题为unordered_set容器（hash）
此题为unordered_map（hasmap）
与map、set不同之处在于他们是无序元素，查找插入时间消耗更低
**1.i-left+1为滑动窗口**
**2.滑动条件为当水果种类大于2，把第一种的水果全部移除**
while(m.size()>2){
  if(--m[tree[left]]==0){
        m.erase(tree[left]);
  }
  left++;
}
**3.存放结果**
res=max(res,i-left+1);

### 代码

```cpp
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> m;
        int left=0,res=0;
        for(int i=0;i<tree.size();i++){
            m[tree[i]]++;
            //滑动条件
            while(m.size()>2){
                if(--m[tree[left]]==0){
                    m.erase(tree[left]);
                }
                left++;
            }
            //i-left+1为滑动窗口
            res=max(res,i-left+1);
        }
        return res;
    }
};
```