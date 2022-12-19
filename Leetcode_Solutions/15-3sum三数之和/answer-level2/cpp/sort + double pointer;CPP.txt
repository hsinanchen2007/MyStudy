```

class Solution
{
public:
    {
        if (nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0)
            return vector<vector<int>>();
        vector<vector<int>> ret;
        int L, R, res;
        for (auto i = 0; nums[i] <= 0 && i<nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            L = i + 1, R = nums.size() - 1;
            while (L < R)
            {
                res = nums[i] + nums[L] + nums[R];
                if (res == 0)
                {
                    ret.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    do
                    {
                        R--;
                    } while (L < R && nums[R] == nums[R + 1]); 

                    do
                    {
                        L++;
                    } while (L < R && nums[L] == nums[L - 1]);
                }
                else // move pointer
                {
                    res > 0 ? R-- : L++;
                }
            }
        }
        return ret;
    }
};
``````javascript []
console.log('Hello world!')
```
```javascript []
console.log('Hello world!')
```javascript []
console.log('Hello world!')
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
