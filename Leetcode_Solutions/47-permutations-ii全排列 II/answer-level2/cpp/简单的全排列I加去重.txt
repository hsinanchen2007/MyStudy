很惭愧，击败了7%，方法很好理解，在全排列的基础上去重就OK了，关于vector去重，使用erase函数和unique函数。

```C++ []
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        DFS(nums,0);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        
        return res;
    }
    
    void DFS(vector<int>& nums, int pos)
    {
        
        if(pos == nums.size()-1)
        {
        
            res.push_back(nums);
            return;
                
        }
        for(int i = pos; i < nums.size(); i++)
        {
            swap(nums[pos],nums[i]);
            DFS(nums,pos+1);
            swap(nums[pos],nums[i]);
        }
        
    }
private:
    vector<vector<int>> res;
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```