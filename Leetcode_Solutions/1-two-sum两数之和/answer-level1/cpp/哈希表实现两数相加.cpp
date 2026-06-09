### 解题思路
![屏幕快照 2020-04-07 下午8.23.29.png](https://pic.leetcode-cn.com/8ca2a0c2cc8ceaad994f08a5b1cb65bb2941396af59e657b7793f3b8cec15a86-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-07%20%E4%B8%8B%E5%8D%888.23.29.png)
创建大小为2n的哈希表，key由原始序列的value根据哈希函数确定。
第一遍循环是建立表。
第二次循环得到第一个数a,再在哈希表中查询target-a所在位置下表，找到就返回。没找到循环继续。
时间复杂度为2n,即O(n)。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int N=nums.size();
    int M=2*N;
    int i;
    int *Hash_Table=(int *)malloc(sizeof(int)*M);
    //初始化
    for(i=0;i<M;i++){
        Hash_Table[i]=-1;
    }
    int a,b,a_index,b_index;
    int key;
    //根据哈希函数生成哈希表
    for(i=0;i<N;i++){
        key=((10*nums[i])%M+M)%M;
        //已有记录
        while(Hash_Table[key]!=-1){
            key=(key+1)%M;
        }
        Hash_Table[key]=i;
    }
    vector<int>ret;
    for(i=0;i<N;i++){
        a=nums[i];
        b=target-a;
        key=((10*b)%M+M)%M;
        while(Hash_Table[key]!=-1&&nums[Hash_Table[key]]!=b)key=(key+1)%M;
        if(Hash_Table[key]==-1)continue;
        else{
            if(i==Hash_Table[key])continue;
            ret.push_back(i);
            ret.push_back(Hash_Table[key]);
            break;
        }
    }
    return ret;
}
};
```