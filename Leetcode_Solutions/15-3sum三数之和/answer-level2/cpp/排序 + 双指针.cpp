## 两数之和的拓展（超时）
两重循环找出两个数的所有组合情况，再利用map查找第三个数；
最后利用vector的unique对返回结果去重；
```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, len = nums.size();
        map<int,int> pp;
        vector<vector<int>> vv;
        for( i=0; i<len; i++ )
            pp[nums[i]] = i;
        
        int tmp;
        for( i=0; i<len-1; i++ )
            for( j=i+1; j<len; j++)
            {
                tmp = 0 - ( nums[i] + nums[j] );
                if( pp.find(tmp) != pp.end() && pp[tmp] != i && pp[tmp] != j )
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(tmp);
                    sort(v.begin(),v.end());
                    vv.push_back(v);
                }
            }
        sort(vv.begin(),vv.end());
        vv.erase(unique(vv.begin(),vv.end()), vv.end());
        return vv;
    }
};
```
## 排序 + 双指针
1、对vector升序排序。

2、遍历排序后的nums：
nums[k]作为第一个数，
指针 i = k+1，用于找第二个数；
指针 j = len-1，用于找第三个数；
sum3 = nums[k] + num[i] + num[j]，若存在 sum3 = 0，则找到一组解。

3、避免重复值：因为是已经升序的数组，所以当 k、i、j 遇到跟上一次相同的值时，都应该跳过。

4、双指针的移动规则：
sum3 > 0，正太多，需要用更小的正数（j--），或更小的负数（不存在）；
sum3 < 0，负太多，需要用更大的负数（i++），或更大的正数（不存在）；

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vv;
        int len = nums.size();
        if( len < 3 ) return vv; //长度不够，直接返回

        sort(nums.begin(), nums.end()); //升序排序

        if( nums[0] > 0 || nums[len-1] < 0 ) return vv; //全正全负，直接返回

        int i, j, k;
        for( k=0; k<len; k++ )
        {
            i = k + 1, j = len -1;
            while( i < j )
            {
                int sum3 = nums[i] + nums[j] + nums[k];
                if( sum3 == 0 )
                {
                    vector<int> v;
                    v.push_back(nums[k]);
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    vv.push_back(v);
                    //排除重复值
                    while( i < j && nums[i] == nums[i+1] )
                        i++;
                    while( i < j && nums[j] == nums[j-1] )
                        j--;
                    i++, j--;
                }
                else if( sum3 > 0 ) //正得太多
                    j--;
                else
                    i++;
            }
            //排除重复值
            while( k+1<len && nums[k] == nums[k+1] )
                k++;
        }
        return vv;
    }
};
```