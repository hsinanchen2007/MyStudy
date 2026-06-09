### 解题思想
暴力方法：从1开始依次判断以每该数开头连续正数能否组成目标数组，直到判断到target/2

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target < 3)
            return res;
        for(int i = 1; i <= target/2; ++i){
            vector<int> temp;
            int t = i;
            int sum = 0;
            while(sum < target){
                sum += t;
                temp.push_back(t++);                
            }
            if(sum == target)
                res.push_back(temp);
        }
        return res;
    }
};
```


### 解题思路
动态规划：以当前数字结尾的连续正数数组的和能否等于target
- 每一次执行循环时，加上当前的数字，
- 如果结果大于目标值，则将数组中前面的元素依次弹出，直到数组中的和不大于目标值
- 如果结果等于目标值，则保存到结果中

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target < 3)
            return res;
        vector<int> temp;
        int sum = 0;
        for(int i = 1; i <= target/2 + 1; ++i){  
            sum += i;
            temp.push_back(i);            
            if(sum > target){
                while(sum > target){                    
                    sum -= *temp.begin();
                    temp.erase(temp.begin());  
                }              
            }
            
            if(sum == target)
                res.push_back(temp);
        }
        return res;
    }
};
```
### 解题思想
滑动窗口也叫双指针
- 定义两个指针，左指针l，右指针r
- 当[l,r)范围内的连续正数的和小于目标值时，当前的求和变量加上==右指针==的值，右指针右移；
- 当[l,r)范围内的连续正数的和大于目标值时，当前的求和变量减去==左指针==的值，左指针右移；
- 等于目标值时，将连续整数存放到结果中

**特别注意**：
循环条件：右指针的范围小于等于中间值的下一个，确保右指针为中间值时的结果也能保存到结果中，
例如：目标值为9，结果数组中应包括【4，5】

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if(target < 3)
            return res;
        int l = 1, r = 1;
        int sum = 0;
        while(r <= target/2 + 2){
            if(sum < target){
                sum += r;
                ++r;
            }
            else if(sum > target){
                sum -= l;
                ++l;
            }
            else{
                vector<int> temp;
                for(int k = l; k < r; ++k)
                    temp.push_back(k);
                res.push_back(temp);
                sum -= l;
                ++l;                
            }
            //cout << sum << endl;
        }
        return res;
    }
};
```