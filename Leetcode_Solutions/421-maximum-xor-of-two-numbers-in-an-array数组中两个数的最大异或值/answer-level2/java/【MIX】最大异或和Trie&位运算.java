### 解题思路
1. 建立Trie, 使用贪心策略求解
2. 建立哈希集合, 正向求解

### 代码

```c++ []
/*
贪心策略
Trie树 & 位运算
*/
class Solution {
public:
    struct Node{
        int son[2];
    };

    vector<Node> nodes; // 记录所有节点

    int findMaximumXOR(vector<int>& nums) {
        nodes.push_back(Node({0, 0}));

        for(auto &x: nums){
            int p =0;
            for(int i=30; i>=0; --i){
                int t = x>>i&0x01;
                if(!nodes[p].son[t]){
                    nodes.push_back(Node({0, 0}));
                    nodes[p].son[t] = nodes.size()-1;
                }
                p = nodes[p].son[t];
            }
        }
        int res = 0;
        for(auto &x: nums){
            int p = 0, xxor=0;
            for(int i=30; i>=0; --i){
                int t = x>>i&0x01;
                if(nodes[p].son[!t]){
                    p = nodes[p].son[!t];
                    xxor += 1<<i;
                }
                else{
                    p = nodes[p].son[t];
                }
            }
            res = max(res, xxor);
        }
        return res;
    }
};
```
```java []
class Solution {
    public int findMaximumXOR(int[] nums) {
        // 根据官方题解整理
        // 定位数组中的最大元素, 并计算其二进制表示的长度
        int maxE = nums[0];
        for(int i=1; i<nums.length; ++i) maxE = Math.max(maxE, nums[i]);
        int L = Integer.toBinaryString(maxE).length();

        // 从高位向低位检测
        int mXOR=0; // 记录最大异或值
        int cXOR;   // 记录当前异或值
        Set<Integer> PRE = new HashSet<>();
        for(int i=L-1; i>=0; --i){
            mXOR <<=1;
            cXOR = mXOR | 0x01; // 将当前异或值的低位设置为1(构造出尽可能大的异或值)) 
            PRE.clear(); // 每次循环清空前缀集合
            for(int n: nums) PRE.add(n>>i); // 前缀加入哈希集合
            for(int p: PRE){
                /*
                对前缀进行遍历
                如果对于当前cXOR, 集合中存在q, 使得cXOR^p=q, 那么有cXOR^p^p = q^p=cXOR
                即当前最大异或可以组成
                */
                if(PRE.contains(cXOR^p)){mXOR=cXOR; break;}
            }
        }
        return mXOR;
    }
}
```
```python []
class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        L = len(bin(max(nums)))-2
        mXOR, cXOR = 0, 0
        for i in range(L)[::-1]:
            mXOR <<= 1
            cXOR = mXOR | 0x01
            PRE = {n>>i for n in nums}
            for P in PRE:
                if cXOR ^ P in PRE:
                    mXOR = cXOR
                    break

        return mXOR
```