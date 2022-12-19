先贴图
![微信图片_20200319094847.png](https://pic.leetcode-cn.com/49ab88af1b9f3e38e0e9e7d2d585136970f3b14d3d886102aac5ac18ce85c8bb-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200319094847.png)


### 解题思路
思路与官方题解差不多，只不过是C实现。

首先回文字符串必定是s对称的，但长度有两种，一是奇数长度，偶数长度。
奇数长度：以中间一个字母对称。
偶数长度：两两对称

要最长长度。就要尽可能利用所有的字符串。

由于大小写字母数量是固定的，我们可以用两个大小为26的数组来统计各个字母的数量。

假设为字符串偶数长度：
则，一个字母必定是两两出现。则遍历所有两个数组，取每个字母（>0)最大的偶数整数。就是字串的最大长度。

假设为字串为奇数长度。
奇数长度以一个字母对称分布。
利用这个特点，我们可以先不管是什么字母，只求对称分布的字母长度。因此，问题转换为求偶数长度问题了，最后长度+1，就是最长长度。

前面我们是假设已经知道长度是奇数还是偶数，现在应该怎样判断是偶数还是奇数呢？

上述奇数长度可以转换为求偶数长度，即可以先求偶数长度，再判断是否能构成奇数长度。

求偶数长度上述已经说过了，现在问题又转换为是否能构成奇数长度。

能否构成，其实就是问是否有奇数个字母数量，即有没有不是对称分布的字母（偶数数量的字母）。利用这个特点，遍历数组时设置个flag即可知道了。

conclusion：
利用两个数组统计各个字母数量，然后先求最长偶数长度的字符串长度，最后判断是否能构成奇数长度，若能，+1，否则，+0；

第一次写题解，大家多多见谅。

### 代码

```c
int longestPalindrome(char * s){
    if((*s)=='\0')
        return 0;
    int alphabet_lower[26];
    int alphabet_upper[26];
    for(int i=0;i<26;i++)
    {
        alphabet_lower[i]=0;
        alphabet_upper[i]=0;
    }
    while((*s)!='\0')
    {
        if((*s)>='a'&&(*s)<='z')
        {
            alphabet_lower[((*s)-'a')]++;

        }
        else
        {
            alphabet_upper[(*s)-'A']++;

        }
        s++;
    }
    int cnt=0;
    bool flag=false;
    for(int i=0;i<26;i++)
    {
        if(alphabet_upper[i]>=2)
        {
            cnt+=alphabet_upper[i]/2;

        }
        if(alphabet_lower[i]>=2)
        {
            cnt+=alphabet_lower[i]/2;

        }
        if(!flag&&(alphabet_lower[i]%2||alphabet_upper[i]%2))
            flag=true;
    }
    if(!flag)
    {
        
        return cnt*2;
    }
    else
        return cnt*2+1;

}
```