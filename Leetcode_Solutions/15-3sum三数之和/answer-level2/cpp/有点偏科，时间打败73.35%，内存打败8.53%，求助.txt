### 解题思路
刚开始写了个三次方时间复杂度的，时间超出限制，然后改成平方——i还是从头到尾循环一次，但是每次循环利用双指针的思想进行一遍遍历就行，但是要考虑到（-2，-1，1，2）这种情况，就是即使碰到了等于零的情况也不能冒然跳出循环，还要继续遍历，我采用的是让前面那个指针往后移一位（动后面那个指针也行）。
现在问题来了，求助大佬有什么减少内存的tip么，我有好多次都是偏科——时间还好，内存太大了
（学校的数据结构目前只讲了如何优化时间复杂性，不太了解怎么优化空间复杂度）

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int i,j,k;
        int tmp;
        vector<int>::iterator ita=nums.begin();
        vector<int>::iterator itb=nums.end();
        sort(ita, itb);

        vector<vector<int>>res;
        
        for(i=0;i<n-2;++i)
        {
            while((i>0)&&(i<n-2)&&(nums[i-1]==nums[i]))i++;
            j=i+1;
            k=n-1;
            while(j!=k)
            {
                if((nums[i]+nums[j]+nums[k])>0)
                {
                    tmp=k;
                    while((nums[k]==nums[tmp])&&(k>j))k--;
                    if(k==j) continue;
                }
                else if((nums[i]+nums[j]+nums[k])<0)
                {
                    tmp=j;
                    while((nums[j]==nums[tmp])&&(j<k))j++;
                    if(k==j)continue;
                }
                
                else
                {
                    vector<int>tp;
                    tp.push_back(nums[i]);
                    tp.push_back(nums[j]);
                    tp.push_back(nums[k]);
                    res.push_back(tp);
                    
                    tmp=j;
                    while((nums[j]==nums[tmp])&&(j<k))j++;
                    if(k==j)continue;
                }
            }
        }
        return res;
    }
};
```