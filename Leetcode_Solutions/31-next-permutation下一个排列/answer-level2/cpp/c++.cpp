题解：首先解释一下字典。根据wiki的蜜汁分析(设想一本英语字典里的单词，哪个在前哪个在后？)，字典序可以认为是是这样一种表述：首先定义元素的大小关系，如1<2,2<3,字典序的比较方式为：假设比较大小的是A,B,从第一位顺序进行比较，相同则比较下一位，如果在某一位上A>B,则字典序上A>B（如12354>12345),因此每一位都比后一位小的顺序是最小的字典序（12345），每一位都比后一位大的顺序是最大的字典序（54321）。
找到下个字典序我的思路是
1. 从后向前找到第一个后>前的位置，定义此时前的位置为front，串的结尾为end
2. 找到[front,end]中比front处值大的最小值，其位置为target
3. 交换target和front处的值
4. 对[front+1,end]的进行排序。


```cpp
bool cmp(int a, int b) {
    if (a > b)return true;
    return false;
}
void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1)
        return;
    auto endIter = nums.end() - 1;
    while (*endIter <= *(endIter - 1)) { 
        endIter--;
        if (endIter == nums.begin()) {
            //逆序
            sort(nums.begin(), nums.end());
            return;
        }
    }
    endIter = endIter - 1;
    auto minIter = endIter + 1,targetIter= minIter;
    int iMin = *minIter-*endIter;
    while (minIter!=nums.end()){
        if (*minIter - *endIter > 0 && (*minIter - *endIter) < iMin) {
            iMin = *minIter - *endIter;
            targetIter = minIter;
        }
        minIter++;
    }
    int temp = 0;
    temp = *endIter;
    *endIter = *targetIter;
    *targetIter = temp;

    sort(endIter + 1, nums.end());
    return;
}
```