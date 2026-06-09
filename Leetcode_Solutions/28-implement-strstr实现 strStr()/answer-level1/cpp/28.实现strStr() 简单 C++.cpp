### 解题思路
采用了KMP算法！！
#### 需要注意：
1. 预设的next数组分配空间，以及在求next数组时访问到的空间，是否越界！
2. 还有就是size()和length()返回的时unsigned类型，当j==-1时，与其比较将会化为unsigned类型，那么-1将大于数组长度，循环结束，所以先将其转化为int类型在进行比较。
#### 提示：
1. KMP算法关键在于模式串指针的回溯和求next数组，而求next数组实际上是求每个元素的最大公共前后缀，并将整个数组右移~~~（目标元素的next值由该元素前的子串的最大公共前后缀）且有next[0]=-1
2. 而求解next数组只需要模式串；next数组的值的含义：    
    1. 为对应元素失配时，指针应该回退到的下标
    2. 该失配元素前的子串的最大公共前后缀
    3. 指针应该回退到的下标，则是最大公共前后缀中的前缀的下一个元素~~

#### 代码如下👇，代码的推导根据画图逐步得出
### 代码

```cpp
class Solution {
public:
    void next(int *&next, string str) {
        int j = 0;
        int k = -1;
        while(j < str.size()) {
            if(k == -1 || str[j] == str[k]) {
                j++;
                k++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }

    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(haystack == "")
            return -1;
        int *next = new int[needle.size()+1];
        next[0] = -1;
        this->next(next, needle);
        int i = 0, j = 0;
        while(i < (int)haystack.size() && j < (int)needle.size()) {
            if(j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if(j == needle.size())
            return i - j;
        return -1;
    }
};
```