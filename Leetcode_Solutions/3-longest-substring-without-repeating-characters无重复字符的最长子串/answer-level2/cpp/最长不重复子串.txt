### 解题思路
1.设置两个指针，i 和 j ,i 表示每次判断的起始位置，j跟在i的后面
2.max 是当前最长长度， len是每次判断子序列的长度 ， flag 标记是否有相同元素，tem 记录需要比较的元素
3.解题思路：
   以pwwkew为例：
       初始条件是，i指向p，j指向i后面的第一个元素w；
       第一层的循环条件是i和j都在长度范围，
       j指向的元素（tem）与 i 和 j 之间的元素进行比较，如果没有相同元素，则j指针向后移动，len++, 继续向后比较;如果有相同元素，将当前的已经记录的长         度len和max相比较，将最大值赋给max,并且重新开始一个子序列，重新开始的子序列的开始元素i向后移动一位，将j定位在i的后面，
4.循环演示：
        1. **p w w k e w**
             i j   (j指向的元素与 i 和 j 之间的元素进行比较，没有相同元素，j继续向后移动，len++)
        2. **p w w k e w**
             i   j (j指向的元素（tem）与 i 和 j 之间的元素进行比较，有相同元素，重新开始一个子序列判断，i向后移动一位,将j定位在i的后面)
        3. **p w w k e w**
               i j (j指向的元素（tem）与 i 和 j 之间的元素进行比较, 有相同元素，同上)
        4. **p w w k e w**
                 i j (j指向的元素（tem）与 i 和 j 之间的元素进行比较,没有相同元素，j继续向后移动，len++)
        5. **p w w k e w**
                 i   j (j指向的元素（tem）与 i 和 j 之间的元素进行比较,没有相同元素，j继续向后移动，len++)
        6. **p w w k e w**
                 i     j (j指向的元素（tem）与 i 和 j 之间的元素进行比较，有相同元素,同第二步)
        7. **p w w k e w**
                   i j
            ......以此类推  

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        else if(s.length()==1) return 1;
        int i,j,k;
        int max = 0;
        int len = 1;
        i = 0;
        j = 1;
        char tem;
        int flag;
        while(i<s.length() && j<s.length())
        {
            tem = s[j];
            flag = 1;
            for(k=i; k<j; k++)
            {
                if(tem==s[k])
                {
                    //cout<<"the same "<<tem<<" "<<s[k]<<" "<<k<<endl;
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
            {
                if(len>max) max = len;
                len = 1;
                i = i +1;
                j = i + 1;
            }
            else if(flag == 1)
            {
               // cout<<"no same "<<j<<" "<<s[j]<<endl;
                j++; 
                len++;
                if(len>max) max = len;
            }
            //cout<<"max len "<<max<<endl;
        }
        return max;
    }
};
```