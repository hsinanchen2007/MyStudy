### 1双指针简洁版本
用i记录上一个非0元素的后一个位置，j记录当前遍历的位置，
循环每次寻找非0元素，找到之后就与i当前位置的元素进行交换，即上一个非0元素的后一个位置，(第一次除外，交换的是初始位置0的元素),
这样就将非0元素全部移动到数组前面，0全部移动到后面
因为是顺次进行的交换，所以非0元素相对顺序不变

总结：遍历找非0元素，与最前面的元素依次交换(如果最前面的元素非0，则元素与自己交换值),只有最前面元素值为0，才可能发生元素值的变化

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
    int i=0;        //记录非0元素的后一个位置，初始为0
    for(int j=0;j<nums.size();j++)
        if(nums[j]!=0)          //遍历数组找到非0元素的索引为j
        {
         swap(nums[i],nums[j]);
         i++;       //让i指向非0元素的下一个元素
        }
    
    }
};

```

### 2双指针易于理解版本   非0前移，后补0


### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
    int i=0;    //慢指针
    for( int j=0;j<nums.size();j++)//1.非0元素前移
        if(nums[j]!=0)      //遍历数组找到非0元素的索引为j
        {
         nums[i]=nums[j];
         i++;
        }

    for(;i<nums.size();i++)    //2.末尾补0，此时i为非0元素的后一个位置，
        nums[i]=0;
    }
};
```

### 3直接删除0，再补0
这个一开始自己实现出了点问题，看了评论区的一位朋友答案后才完善的

### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
    int count=0;
    for(auto it=nums.begin();it!=nums.end();)
    {
        if(*it==0)
        {
        nums.erase(it);
        count++;
        }
        else
         ++it;
    }
    nums.insert(nums.end(), count, 0);
    }
};
```