### 解题思路
1、暴力解法
2、单调栈

### 代码

```cpp
class Solution {
public:
    //时间复杂度O(M * N)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        //对nums2建立 (值，索引)映射关系 方便nums1快速查找
        unordered_map<int, int> map;
        map.reserve(nums2.size() * 2);

        for (int i = 0; i < nums2.size(); ++i)
        {
            map.insert(make_pair(nums2.at(i), i));
        }

        //找下一个更大元素
        vector<int> res(nums1.size(), -1); //用-1初始化，只需要存在时填

        for (int i = 0; i < nums1.size(); ++i)
        {
            //找到nums1.at(i)在nums2中的位置，从这个位置的下一个开始找
            int j = map.find(nums1.at(i))->second + 1;
            for (; j < nums2.size(); ++j)
            {
                if (nums2.at(j) > nums1.at(i))
                {
                    res.at(i) = nums2.at(j);
                    break;
                }
            }
        }

        return res;
    }


    //方法2：单调栈
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> v(nums2.size(), -1); //记录nums2中每个元素的下一个比其更大的值

        //构建nums2的值与索引的映射关系，方便nums1快速查找
        unordered_map<int, int> map;
        map.reserve(nums2.size() * 2);

        stack<int> stack; //单调递增栈
        for (int i = 0; i < nums2.size(); ++i)
        {
            while (!stack.empty() && nums2.at(i) > nums2.at(stack.top()))
            {
                int index = stack.top();
                stack.pop();

                v.at(index) = nums2.at(i);
            }
            stack.push(i);
            map.insert(make_pair(nums2.at(i), i));
        }

        //v初始化全为-1，找不到下一个更大元素的无需再设值
        //while (!stack.empty())
        //{
        //    int index = stack.top();
        //    v.at(index) = -1;
        //    stack.pop();
        //}

        //遍历nums1，去v中查找下一个更大元素，放入res
        vector<int> res(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); ++i)
        {
            res.at(i) = v.at(map[nums1.at(i)]);
        }

        return res;
    }
};
```