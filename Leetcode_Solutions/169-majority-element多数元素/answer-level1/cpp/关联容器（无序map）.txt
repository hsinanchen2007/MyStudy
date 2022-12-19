### 解题思路
此处撰写解题思路
使用关联容器unordered_map来实现（相当于python中的字典）
由于我是第一次使用这个关联容器，所以在代码中都注释了。。。
有什么好方法或者发现了什么错误欢迎讨论交流!
### 代码

```cpp
class Solution {
    /***
    用到了关联容器：关联容器中的元素是按照关键字来保存和访问的。主要的两个：map和set
    map中的元素是一些 关键字-值（key-value）对，类似与python中的字典
    set中只包含一个关键字（关键字的集合）即可以存储字符的“数组”
    **/

    /***
    map与unordered_map的区别：
    （1）map是有序的，结果按照关键字有顺序的排列；unordered_map是无序的；
    （2）map是通过红黑树实现的，而unordered_map是通过一个哈希函数实现的；
    ***/
public:
    int majorityElement(vector<int>& nums) 
    {
        //int size = nums.size();
        //int times = size/2; 因为题目中明确表明给定的数组总是存在多数元素，所以不用考虑

        unordered_map<int, int> map1; //定义一个无序的关联容器map
        int key = 0, value = 0; //关键字和值
        
        for(int num : nums) //范围for循环给map赋值
        {
            ++map1[num];
        }

        for(auto map_it = map1.begin(); map_it != map1.end(); map_it++) //遍历map(使用迭代器)
        {
            if(map_it->second > value) //更新value的值，并保存关键字key,因为最后需要输出key
                {
                    key = map_it->first;
                    value = map_it->second;
                }

        }
        return key;
    }
};
```