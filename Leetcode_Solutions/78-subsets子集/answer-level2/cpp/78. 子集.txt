### 掩码法
全排列/组合/子集的解法类似，都可以使用回溯法进行解决，一般解的空间为
（1）全排列：n!
 (2) 组合：n！
（3）子集：2的n次方，因为每一位可能为0，也可能为一。
掩码法就是找出长度为n的所有掩码，例如：[1，2，3]
这时n为3，解空间为8种，0~7的二进制数依次为：000，001，010，011，100，101，110，111
也就是说我们只要从0到n循环，并对应将1的位加入结果就可以了。具体代码如下。
### 时间/空间复杂度
时间：O（n2）
空间：O（n2）
### 代码

```cpp
//执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :6.8 MB, 在所有 C++ 提交中击败了100.00%的用户
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long n=1<<nums.size();              //这里是1右移num.size()位，结果为2的num.size()次方
        vector<int> tmp;
        vector<vector<int>> res;
        for(long i=0;i<n;++i){              //子集的解一共有2的n次方种
            tmp.clear();
            long mask=1;
            for(int j=0;j<nums.size();++j){ //每一次循环走nums.size（）个位置，看哪一位上为1
                if(i&mask){                 //如果i的mask那一位为0，i&mask就为0
                    tmp.push_back(nums[j]);
                }
                mask=mask<<1;               //注意位移的写法
            }
            res.push_back(tmp);
        }
        return res;
    }
};
```