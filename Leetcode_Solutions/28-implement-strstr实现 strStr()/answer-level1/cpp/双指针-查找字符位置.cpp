### 解题思路
之前自学数据结构与算法有接触过KMP算法，KMP的查找效率很高，但算法有点复杂；其次还有双指针、暴力蛮解法，其时间复杂度越来越高。
双指针解题的思路大致如下：
一个指针h指向haystack，一个指针n指向needle；仅当指针h指向的值等于指针n指向的值才开始比较后续的值，且当计数器的值等于needle的长度时，才确保查找正确。
**注意：strStr函数返回值是int型，所以一定要有返回值；如果所有的返回函数return均存在条件判断下，会报错，如if(count==n){return i;}，所以一定要有一个return函数是不属于条件判断下的。**

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size(),n=needle.size(),j,count;
        if(n>h)
            return -1;
        for(int i=0;i<h-n+1;i++){
            j=0;
            count=0;
            while(haystack[i+j]==needle[j]&&needle[j]!='\0'){
                j++;
                count++;
            }
            if(count==n)
                return i;
        }
        return -1;
    }
};
```