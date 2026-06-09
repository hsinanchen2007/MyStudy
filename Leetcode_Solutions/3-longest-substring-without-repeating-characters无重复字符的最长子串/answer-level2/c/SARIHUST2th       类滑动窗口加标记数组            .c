### 解题思路
本题让我回忆起当年学习C语言的时候（听上去好久远，其实就几个月前吧）一道程序设计实验例题。要求是将字符数组中的重复字符跳过。例题的解法是每遍历到一个字符，就再开一个循环将它后面所有与它一样的字符跳过。简而言之这是一个时间复杂度为O(n^2)的方法。当时要求以空间换时间将程序设计为O(n)，只遍历一遍数组完成。于是引入了一个以字符ASCII码值做下标的h标记数组以标明字符是否出现过再据此判断是否要跳过。
本题也是要判断元素是否出现过，所以我就选择采用了开辟标记数组tag的方法。

同时，又联想到最近学习的数据结构中的最大子列和问题的O(n)算法，其核心是要直接跳过序列元素和为负数的这一段序列，因为0加上任何数都大于负数加上这个数。这里序列和为负，与本题的重复元素在我的脑回路中有很大的相似之处。我们在发现了相同元素x之后，可直接舍弃掉之前出现的x以及它之前的子串因为最长的子串中不可能同时含有两个x而新的x出现之前的子串中的最长子串已经被记录下来了。具体可见分析。
- 分析：
开始时两个指针front，rear均指向数组起始元素，将tag数组元素全部置0。
1. 让rear向后遍历，并同时使当前子串长sizej自增。若rear遇到之前未出现的元素x，就将tag[x]置为1，表示元素x出现了。
2. 继续遍历若重新遇到了元素x（可通过tag[x]是否非0判断），就将当前子串长size与最长子串长maxsize进行比较然后更新maxsize。接下来需要跳过不可能在后续子串中出现的部分。
3. 做一个一重循环找到之前出现的x再使front指向其后继元素。循环过程中每使front自增一次就使size自减一次。
4. 执行1，2，3直至数组末尾
5. 最后一次的maxsize可能并未更新，再做一次比较。

![3.png](https://pic.leetcode-cn.com/10d25f77ec823850d20539ae1ef187b48b53ccf5ffb80e975bec136c20af1d10-3.png)

测试时使用的代码稍有不同，开辟的是int型数组，占用的字节数更多。




### 代码

```c

int lengthOfLongestSubstring(char * s){
    int a = strlen(s);
    if(a == 1)
        return a;
    int maxsize, size;
    char tag[128] = {0};
    char *front, *rear;
    front = rear = s;
    maxsize = size = 0;
    while(rear < s + a)
    {
        if(!tag[*rear])         //说明*rear未曾在之前的子串序列中出现
        {
            tag[*rear] = 1;
            size++;
            rear++;
        }
        else
        {
            if(maxsize < size)
                maxsize = size;         //每需要抛弃前面子串时就要更新maxsize
            while(*front != *rear)
            {
                tag[*front] = 0;
                front++;
                size--;
            }                   //通过循环找到之前已经出现过的元素x
            front++;
            rear++;
        }
    }
    if(maxsize < size)
    	maxsize = size;         //未出现重复元素就到达字符数组尾部时，需要额外更新一次maxsize
    return maxsize;    
}    
```