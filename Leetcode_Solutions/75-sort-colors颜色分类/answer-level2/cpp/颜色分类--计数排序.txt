### 解题思路
小范围内数字排序，适合计数排序
- 仅需定义一个长度为3的数组；
- 用该数组存储每种颜色出现的数量
- 然后依次按照下标， 给nums数组重新赋值；

### 代码

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> res(3,0);//初始化数组
        for(auto i: nums)
            res[i]++;//颜色叠加

        int k=0;
        for(int i=0;i<3;i++){
            while(res[i]-- != 0){//输出
                nums[k++] = i;
            }     
        }
    }
};
```