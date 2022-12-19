### 解题思路
这里说一下我的思考过程

基本思路就是我们从头往后遍历，每次接收一个新的元素，就从当前元素开始，往前遍历，记录它能够不出现元素一样的个数，然后保存最大的长度即可，可结合下面的演示理解
```
a  b  c  a  b  c  b  b                  a  b  c  a  b  c  b  b 
                            ------>                             ------>
1  1  1  1  1  1  1  1                  1  2  1  1  1  1  1  1

a  b  c  a  b  c  b  b                  a  b  c  a  b  c  b  b
                            .......                            
1  2  3  1  1  1  1  1                  1  2  3  3  3  3  2  1 
```

### 代码

```c
//暴力解决
int lengthOfLongestSubstring(char * s){
    int length=strlen(s);
    if(length==0)
    return 0;
    int dp[length];//dp[i]表示下标以i为结束的最长无重复字符子串
    int i,j;

    int max=1;
    for(i=0;i<length;i++)
    {
        if(i==0)
        dp[i]=1;
        else
        {
            dp[i]=1;
            for(j=i-1;j>=0&&j>=i-dp[i-1];j--)
            if(s[j]!=s[i])//更新
            dp[i]++;
            else
            break;
            if(max<dp[i])
            max=dp[i];
        }
    }
    return max;
}
```
时间:O（N*N）
仔细分析，这里可以发现两个特点
```
1.最长子串要求的是不重复
2.我们确定长度的时候是从后往前是确认是否存在相同元素
```

根据这个特点，我想到了hash表可以做到这一点，hash的查找是O(1)的，那么我们就可以用简单的数组来模拟hash（反正是不重复的）,hash窗口的长度就是不出现重复元素的长度

这里需要精细的考虑一下窗口的定义，有下面几个问题：
```
1.如何设置窗口的头尾

2.hash记录的是什么，如何记录

3.如何更新hash的记录
```
解决方案：
```
1.利用双指针，i指向头部，j指向尾部，逐个逐个的往后扩张

2.hash记录的是元素的下标，只保存在窗口范围内的下标

3.这里需要判断每次加入的元素是否能够在窗口内找到，如果发生了碰撞，那么i就会找到出现碰撞的位置的后一个作为新的头部，这样子就能够保证当前的窗口元素都是不重复的，因为我们把重复的元素舍弃到窗口之外了
```
接下来的就仔细看看代码，我都有详细的注解


```c
//hash滑动窗口
int lengthOfLongestSubstring(char * s){
    int hash[128];//hash滑动窗口
    memset(hash,-1,sizeof(int)*128);//初始化
    int max=0;

    int length=strlen(s);
    
    int i,j;

    for(i=0,j=0;i<length-max&&j<length;j++)
    {
        if(hash[s[j]]<i)//存下标
        hash[s[j]]=j;
        else
        {//发生碰撞
            if(j-i>max)
            max=j-i;
            int mark=s[hash[s[j]]+1];
            i=hash[s[j]]+1;//在出现重复元素的后一个位置
            hash[s[j]]=j;//记录新的下标
        }
    }
    if(j-i>max)
    max=j-i;
    return max;
}


```
时间:O（N）