执行用时 :4 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了100.00%的用户

### 解题思路
逐次对容器内的每个数字分析
循环向左移位直到当前数字小于0(int)，记录移位的次数从而得出当前数字的位数
如果当前数字的位数为偶数则返回值+1
最后返回返回值

### 代码

```cpp
class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int size = nums.size();
        int COUNT = 0;

        for(int i=0; i<size; i++){
            
            int temp = nums[i];
            int count = 0;

            while(temp>0){

                count++;
                temp = temp/10;

            }

            if(count%2==0)
            COUNT++;



        }


        return COUNT;
    }
};


```

### 简单方法
讲数字转为string字符串，字符串的长度即为数字的位数
```
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int count = 0;
        for(int num:nums){

            if(to_string(num).size()%2==0)
            count++;
        }

        return count;
    }
};
```
