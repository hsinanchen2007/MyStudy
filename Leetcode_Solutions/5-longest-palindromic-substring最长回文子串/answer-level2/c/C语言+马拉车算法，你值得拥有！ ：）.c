### 解题思路
![截屏2020-02-03下午10.33.09.png](https://pic.leetcode-cn.com/4352d5160751868959908c726ed4d5478e3d530bce5f6eb517d5d58340dad046-%E6%88%AA%E5%B1%8F2020-02-03%E4%B8%8B%E5%8D%8810.33.09.png)

   马拉车用于解决最长回文子串问题，重点是子串，而不是子序列.
   算法的思路就是用一个radius[i]数组去存第i个位置到mx位置的长度，然后用id记录上一次操作的位置，mx标记上一次的最长子串的最右端，然后依次去递推。
       先定义一个字符串s = "ababc"，因为对于回文字符串来说有对称轴，比如说aba就是以b作为对称轴，那么当字符串长度为偶数的时候，对称轴就不是唯一的整数位了。所以我们要对原字符串做一个预处理，在每个字符左右都加上一个特殊字符，这里我用'#'，那么处理后的字符串mana就是#a#b#a#b#c#了，不管原字符串长度是奇数还是偶数，处理后的长度都变成奇数了。然后还需要在这个mana的最前面加一个不同于之前的特殊字符的特殊字符，这里我用了'$'，不要忘记最后一个字符'\0'(因为在后面的while循环中在匹配字符的时候可能会越界),。这样预处理操作就完了，最后的字符串mana就是$#a#b#a#b#c#了。
    首先需要明白的是，我定义的mx是上一次操作的最长回文子串的最右端，我解释一下，比如说ababa，第一次对i=2操作的时候，会计算出他的最回文子串为aba(长度为3)，则在这次操作结束后mx的位置就是4，也就是aba的下一位。而我定义的id是上一次操作的位置，也就是i的位置，还以刚才的例子为例，在对i=2操作结束后，id的位置就是2。
    radius数组里存的是第i个位置到mx位置的长度，比如说还是ababa，当i=2的时候，可以计算出aba是它此时的最长回文子串，那么mx的位置就是aba的下一位，那radius[2]存的就是mx - i了。最重要的就是radius数组，所以这点一定要弄明白，radius数组存的是，当前这个位置到它的最长回文子串的最右端的距离(也就是mx的位置)。在mana字符串中，radius[i] = 2*Len[i] - 1(因为有特殊字符)，在s字符串中Len[i] = mx - id + 1。

   首先把mx初始化0，然后开始从i=1开始遍历mana，当i>=mx的时候，也就是i在mx前面的时候，就让radius[i] = 1，表示在i之前没有回文串出现，所以让radius从1开始，然后先不说i<mx的情况，然后往下走到while循环，这个循环就是用来判断这个位置的最长回文子串的，就是以这个点为中心，然后依次比较左边一个和右边一个、左边第二个和右边第二个...是否相等，相等的话就让radius[i]++，就相当于这个位置到这个位置的子串的最右端的长度++。然后再比较这个点+这个点的回文长度是否超过了mx的位置，超过的话就更新一下mx的值，因为mx是此次操作的最长回文子串的最右端。
![截屏2020-02-03下午10.44.52.png](https://pic.leetcode-cn.com/ef52eb0dd433e90bd4a6142ca2747d6c5b8e504c724f7153d9996cf414e6be8f-%E6%88%AA%E5%B1%8F2020-02-03%E4%B8%8B%E5%8D%8810.44.52.png)

   然后对于i<mx的情况就稍微有点不太好理解了，参考着上图我讲一下这种情况。这是一个以id(上一次操作的位置)为中点长度为mx-my的回文串，j是以id为中点的i的对称点，因为j在之前遍历的时候就已经操作过了，所以radius[j]是已知的又因为回文串的性质可以知道radius[j]<=radius[i]的，my是mx的对称点。对于i<mx的情况还要再分情况，就是radius[j]和mx-i比较了，上图的情况是radius[j]是小于mx-i的，表示j位置的最长回文子串的长度是在id位置的最长回文子串的范围内的，还有一种情况就是radius[j]>mx-i，如下图所示，radius[j]的长度的范围超出了my。
![截屏2020-02-03下午10.55.39.png](https://pic.leetcode-cn.com/2ccf2adbbb188f3c1ee4ede49498f8c02904f5b7b4c307057c6b761bc5cb63f1-%E6%88%AA%E5%B1%8F2020-02-03%E4%B8%8B%E5%8D%8810.55.39.png)

所以我们需要对这两种情况再讨论一下，当radius[j] < mx-i的时候，表示radius[j]的长度可能不会超过mx-i，所以我们就从i的radius[2*id - i]也就是radius[mx-i]的地方开始匹配。当radius[j] > mx - i的时候，说明i位置的子串长度超过了mx，但mx以外的地方还没有遍历到，所以我们就从mx-i也就是mx的位置开始对i匹配。

### 代码

```c
char * longestPalindrome(char * s){
    if(s == NULL)
    {
        return NULL;
    }

    if(strlen(s) == 1)
    {
        return s;
    }

    int len = strlen(s);
    int str_len = 2*len + 3;
    char mana[str_len];
    /*注意此处radius是int类型*/
    int radius[str_len];//表示以 i 为中心的最长回文的半径

    memset(mana,0,sizeof(mana));
    memset(radius,0,sizeof(radius));

    mana[0] = '$';
    mana[1] = '#';
    int j = 2;

    for(int i = 0;i < len;i++)
    {
        mana[j++] = s[i];
        mana[j++] = '#';
    }
    mana[j] = '\0';

    int manaSize = j;
    //printf("manaSize = %d\n",manaSize);
    int id = 0;//centej
    int mx = 0;//以i为中心的回文子串的最右端
    int maxLen = 0;
    int start = 0;
    int i;
    for(i = 1;i < manaSize;i++)
    {
        if(i < mx)//i center does not exceed the right end boundary of MX
        {
            radius[i] = (mx-i)<radius[2*id-i]?(mx-i):radius[2*id-i];
        }
        else
        {
            radius[i] = 1;//once the boundary is exceeded, start counting again
        }

        /*expand from the center to the outside, and 
          gradually expand the range of palindrome 
          substring*/
        while(mana[i-radius[i]] == mana[i+radius[i]])
        {

            radius[i]++;
        }

        /*if the rightmost endpoint of the new calculation 
          is greater than mx,update id and mx */
        //printf("before i = %d id = %d mx = %d maxLen = %d radius[%d]= %d\n",i,id,mx,maxLen,i,radius[i]);
        if(radius[i] + i > mx)
        {
            id = i;
            mx = radius[i] + i;
            //printf("id = %d mx = %d\n",id,mx);
        }

        /*calculate the index value that meets the condition*/
        if(radius[i] - 1 > maxLen)
        {
            start = (i - radius[i])/2;
            maxLen = radius[i] - 1;
        }
    }


    char *res = (char*)malloc(sizeof(char)*(maxLen+1));
    for(int i = start,k = 0;i <start+maxLen;i++,k++)
    {
        res[k] = s[i];
    }
    res[maxLen] = '\0';

    return res;

}
```