### 解题思路
跟双指针类似 增加统计长度的len

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator writer,reader;//reader读取 writer写入
        int counter = 1;//统计数字

        //判断大小
        if(nums.empty())
            return 0;
        if(nums.size()<=2)
            return nums.size();

        //reader为最后一个才能停止
        writer = nums.begin()+1;
        reader = writer;
        int len = 1;
        while(reader != nums.end())
        {
            //判断是否相等
            if(*reader == *(reader-1))
                counter++;
            else
                counter =1;

            //counter统计<2 时候才能进行写时候复制
            if(counter <=2)
            {
                *writer = *reader;
                writer++;
                len++;
            }
            reader++;
        }

        nums.resize(len);

        return len;
    }
};
```