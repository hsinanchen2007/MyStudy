### 解题思路
大概就是遍历一遍，装入map，当值为3时移出map。最后map中只剩值为1的。

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>m;
        for(int i=0 ;i<nums.size();i++){
            if(m.count(nums[i])){
                if(m[nums[i]]==2){
                    m.erase(nums[i]);
                }else m[nums[i]]++;
            }else{
                m[nums[i]]=1;
            }
        }
        int key=0;
        for(auto x:m){
            key=x.first;
    }
        return key;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4492a8263a9b1ebc4b7b64c8072482613fc93243991f09f5e7c3f06154042c6e-image.png)


别人的暴力map的解法：
比我自己写得好一些
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();++i)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(mp[nums[i]]==1) return nums[i];
        }
        return -1;


    }
};

作者：fu-jian-xiao-ya-xuan-fen-xuan
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/c-mapfa-by-fu-jian-xiao-ya-xuan-fen-xuan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


```
![image.png](https://pic.leetcode-cn.com/0812064ccb2761497af100580ce3d42980f6c177d7ca54883013fff373c6d156-image.png)



※数字电路法
没想到数字电路中的知识能用到这里，长见识了，可惜当时我没有好好学，下来复习一下。

```c++
public int singleNumber(int[] nums) {
        int a=0,b=0;
        for (int c : nums) {
            b = b ^ c & ~ a;
            a = a ^ c & ~ b;
        }
        return b;
    }

作者：sheng-tian-ban-zi-4
链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof/solution/zhuang-tai-ji-jie-jue-ci-wen-ti-xiang-jie-shu-zi-d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```