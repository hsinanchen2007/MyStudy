### 解题思路
只有两种状态一种是单数，一种是偶数，统计两种的个数，谁小答案就是谁

### 代码

```java
//java
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int count = (int)Arrays.stream(chips).filter(o->o%2==0).count();
        return 2*count>chips.length?chips.length-count:count;
    }
}
```


``` C++
//C++
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int count = count_if(chips.begin(),chips.end(),[](auto i ){return i&1;});
        return 2*count>chips.size()?chips.size()-count:count;
    }
};
```

