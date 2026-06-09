C++使用while循环+if判断
```
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int i = 0, len = flowerbed.size();
        while (i <= len - 1 && n != 0) //测试用例给了n=0的情况，这种情况百分百是true
        {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i + 1 == len || flowerbed[i + 1] == 0)) 
            {
                //就是需要判断边界问题，i=0的时候和i=len-1的时候，放在或的符号前面
                //因为c++对或的处理方式是不满足前一个才运行下一个，所以保证不会越界报错
                i += 2; // i可以种，那么下一个可能可以种的地方必然是i+2
                --n; //需要种的花-1
            }
            else
                ++i; // i不能种，判断下一个位置
        }
        return n == 0; // 因为前面while循环加了条件限制n必须不为0，所以结束后n必然>=0
    }
};
```