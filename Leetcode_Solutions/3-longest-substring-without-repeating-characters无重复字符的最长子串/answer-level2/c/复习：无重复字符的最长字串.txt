### 解题思路
时隔多日，完全忘记这么经典的题怎么写的了。复习一下：
应该结合大佬的题解中的[利用数组(桶)代替hashmap](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/)进行复习。
end负责进队列，但是**当前**end指向的值是尚未进队列的。*当前的end需要判断的是在对应的hash数组中的值是否大于了start*。
需要注意的是在while循环中真正持续进行的是**入队**操作，即
```
    hash[s[end]]=end;
    end++;
```
这道题之所以那么容易遗忘是因为使用了hash数组使得映射关系非常绕，毕竟智商不够。但这里还是要再次提一下这个hash数组得含义：hash[i]的下标i指的是一个字母（'a','b','c'...）,值对应的是在当前栈中**出现过**的位置。


### 代码

```c
int lengthOfLongestSubstring(char * s){
    if(strlen(s)==0) return 0;
    if(strlen(s)==1) return 1;
    //使用maxLength记录最大长度
    int hash[128],maxLength=0;
    //对其实对数组也可以使用memset的，因为memset的第一个参数其实就是一个地址，准确说要初始化的空间的首地址而已
    //同时因为我这里直接初始化数组hash，使用sizeof的时候就可以稍微简单些
    memset(hash,-1,sizeof(hash));
    //使用数组桶实际上就是栈和hash表的结合
    int start=-1,end=0;
    //当end遍历到s的结尾时结束
    while(s[end]!='\0'){
        //end指向的字符串的位置应该在start之后才能够移动start指针
        if(hash[s[end]]>=start) start=hash[s[end]]+1;
        //这时每一次循环都应该做的，即更新hash数组的值
        hash[s[end]]=end++;
        if(maxLength<end-start) maxLength=end-start;
    }
    return maxLength;
}
```