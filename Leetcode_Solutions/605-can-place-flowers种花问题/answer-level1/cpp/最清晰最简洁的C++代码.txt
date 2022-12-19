首先为了避免首位和尾位的特殊情况，可在首位和尾位都填上一个0，这样就可以一视同仁了，只需寻找到有多少个 0 的左右两边都是0即可，该个数即为可插花朵的最大值

```
class Solution 
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count =  0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.insert(flowerbed.end(),0);
        for(int i = 1; i < flowerbed.size()-1; i++)
        {
            if(flowerbed[i] == 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0)
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return n <= count;
    }
};
```

若不想两边添加0的话，也有方法
修改一下for语句和if语句的内容，首尾特例包含在内即可
for(int i = 0; i < flowerbed.size(); i++)

if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0))
一定注意：i == 0 || flowerbed[i-1] == 0
和 i == flowerbed.size() - 1 || flowerbed[i+1] == 0
中的||两边的位置，如果颠倒的话，就会发生数组越界，无法通过