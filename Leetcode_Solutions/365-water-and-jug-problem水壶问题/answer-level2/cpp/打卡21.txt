### 解题思路
  这题一开始是按照数学的方式去解决的，但是没找出来规律。就直接一个一个试过去。
  因为只有把x的倒满、倒空以及y的倒满、倒空这么四种方式，去凑出能不能刚好为z。所以，我就使用一个sum变量代表当前符合操作规范搜集到的水。而且x+y一定是要比z大的，因此，也就不需要明确到sum这个水当前是在哪个容器之中。因为无论是在哪个容器中，sum都不可能会超过x或者y。
  所以，不需要直到sum具体在哪个水桶里，只需要去进行倒满、倒空的的动作就好了，因为如果是在当前容器了，肯定是会使sum小于等于0的。
  最后，因为对于出现过的sum情况，就不需要去查找了。不然就会进入死循环了。

### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)return false;
        if(x + y == z || x == z || y == z)return true;
        //防止为0的情况
        if(x == 0 || y == 0)return x == z || y == z;
        vector<int> v(1000001, 0);
        return dfs(x,y,z,0,v);
    }

    bool dfs(int x , int y , int z , int sum , vector<int>& v){
        //当前水的体积小于0是不可能的
        if(sum < 0)return false;
        //只需要去看当前的水容量是否等于z或者加上空的x或y能够使得sum等于z（这里就是之前说的不用考虑水在哪个容器中盛放）
        if(z == sum || x + sum == z || y + sum == z)return true;
        if(v[sum])return false;
        //标记状况已经发生过了
        v[sum] = 1; 
        //这里执行倒满或倒空
        return dfs(x,y,z,x - sum,v) || dfs(x,y,z,y - sum,v) || dfs(x,y,z,sum - x,v) || dfs(x,y,z,sum - y,v);
    }
};
```