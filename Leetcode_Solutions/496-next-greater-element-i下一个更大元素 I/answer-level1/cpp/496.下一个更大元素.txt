### 解题思路
基本思路与739.每日温度一致，正向入栈，若是大的，小的pop，否则一起入栈。
在对nums2进行所有解答后，用map进行配对，再将nums1一个个检索，以下是cpp版。

### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        stack<int> data;
        vector<int> result (nums1.size() ) ;
        map<int,int> pairs ;
        
        for ( int i = 0 ; i < nums2.size() ; ++i )
        {
            while ( !data.empty() && nums2[data.top()] < nums2[i] )
            {
                pairs.insert(make_pair(nums2[data.top()], nums2[i]));
                data.pop() ; 
            }
            data.push(i);
        }
        
        for ( int i = 0 ; i < nums1.size() ; ++i )
        {
            if (pairs[nums1[i]] )
                result[i] = pairs[nums1[i]] ;
            else
                result[i] = -1 ;
        }

        return result ;
    }
};

```