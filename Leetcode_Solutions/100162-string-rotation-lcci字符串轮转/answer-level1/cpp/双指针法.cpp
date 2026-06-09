
### 代码

```cpp
class Solution {
public:
    bool isFlipedString(string s1, string s2)
    {
        int i = 0;
        int j = 0;
        int len = 0;
        int m = s2.size();
        int n = s1.size();
        if(s1.size() != s2.size()) return false;
        if(s2.empty())
        {
            return 1;
        }
        //方法一 find函数
        //s1 = s1 + s1;//若s2是s1翻转得到 则对于s1拼接之后的string中 必然含有s2
        //if(s1.find(s2) != -1) return true;
        //return false;
        //方法二 双指针
        //对s1 wat[erbottle] 旋转 s2：[erbottle]wat s2保持头不动，s1向后排查，直到底，若中间有不匹配的元素 则向下排查 len重置（旋转项必然连续）
        while(i < n)//找到s1的旋转体
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
                len++;
            }
            else
            {
                i++;
                j = 0;
                len = 0;
            }
        }
        //此时s2已经走到了w处 len为旋转体1的长度
        i = 0;
        while(j < m)//记录旋转体2的长度 若能走完 则返回true
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
                len++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};



```