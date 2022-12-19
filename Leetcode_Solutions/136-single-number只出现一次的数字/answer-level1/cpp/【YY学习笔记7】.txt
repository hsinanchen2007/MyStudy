### 解题思路
异或、哈希、双重循环。最让我感到意外的是异或，因为自己之前在思考这道题的时候完全没有往数学方面去考虑，太强了。
### 知识点
**1**   容器（排序类）和迭代器：（类比为数组和指针）两者往往配套使用。
**2**   list（列表）、vector（向量）、array（数组）都是排序类容器。
········list：由双向链表构成，其内存空间不连续，内存大小可变。
········vector:内存空间连续，内存大小可变。
········array：内存空间连续，内存大小不可变。
**3**   如何定义vector容器。
**4**   如何访问vecotr容器中元素：方法一：像数组那样访问；方法二：借助迭代器访问。
**5**   map的定义和用法。
### 感悟
最近在码代码的时候发现自己的知识储备实在太匮乏了：往往一道题就能深挖出很多知识点，花上很长的时间才能做完一题。不过收获也是真的大。冲冲冲！！！

### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //采用官方的异或操作
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
    int singleNumber2(vector<int>& nums) {
        //类似官方哈希表方法，使用map键值对的方法来操作。
        //时间复杂度O(n),空间复杂度O(n)
        map<int,int>a;
        map<int,int>::iterator it;
        for(int i=0;i<nums.size();++i){
            if(a[nums[i]]==1){
                a.erase(nums[i]);
            }
            else
                a[nums[i]]++;
        }
        it=a.begin();
        return it->first;
    }
    int singleNumber3(vector<int>& nums) {
        //类似于官方解法1，具体思想看官方解法更易懂。本人解法目的在于熟悉容器、迭代器。
        //时间复杂度O(n²)，空间复杂度O(n)。
        bool same=false;
        vector<int> tmp;
        vector<int>::iterator it;
        //外层循环，采用数组的方法来进行循环。
        for(int i=0;i<nums.size();++i){
            same=false;
            //内层循环，采用迭代器的方法来进行循环：迭代器可看成指向数组的指针，而vector容器可看成数组（不严谨，但好理解）。
            //begin()函数为“数组”tmp首元素的地址.
            //end()函数为“数组”末尾元素地址+1。
            //erase(iterator it)函数为删除"指针"it指向的元素
            for(it=tmp.begin();it!=tmp.end();++it){
                if(*it==nums[i]){
                    tmp.erase(it);
                    same=true;
                    break;  
                }
            }
            if(!same)
                tmp.push_back(nums[i]);
        }
        return *tmp.begin();
    }
};
```