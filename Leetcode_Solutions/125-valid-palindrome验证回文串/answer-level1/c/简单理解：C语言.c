### 解题思路
参考zrita老哥的简化代码，让C代码简化

这里需要额外注意就是函数调用必须先于左右指针大小判断！非常重要，是处理奇偶回文串的重点！同时还是处理"空串"的巧合？

### 1.外层循环条件：left<right
既然知道是首尾对比，自然双指针少不了，因为回文关于中心对称(本题有点特殊除外)，但依旧有个规则就是left<right，因为回文，两侧相等了，自然没有必要再比两端了。因此总的大条件，也就是双指针循环条件就是left<right

### 2.内层循环条件：convert(s[left])&&left<right
convert函数是判别是否是有效数字或字母函数。这两个顺序一定不能颠倒，否则出错。

1.left<right?怎么又来一个同样条件？
由于题目给出"只考虑字母和数字字符，可以忽略字母的大小写。"，那么出现一堆非字母与数字，都需要跳过。
而且"本题我们将空字符串定义为有效的回文串。"，那么出现跳完了，就是"空字符串"情况。
怎么跳跃？筛选符合条件的字符，我想不可能一个个if,if语句判断吧。自然而然就是使用while循环。
鉴于外层大循环终止条件是left<right,那么筛选有效字符的while循环也没必要超过这个界限，因此内层循环加上也没错。
其实最主要的是担心，跳跃越界问题，并不是通过外层left<right来约束，只不过是left<right约束条件更具体。
',.':left不停右移，一定出现问题就是超界！那么限定条件就是left<len,right>=0，有必要吗？
刚好外层left<right帮我们完美解决问题，即使从这个例子中,right=len-1根本没有机会-1，left不停右移，直到将其变成”空串“。

2.express1 && express2 顺序重要性
A man, a plan, a canal: Panama
当还剩a ca这个时候，left=a,right=a，此时left<right：
因此left可以右移1次，但是发现是空格，还需要右移。这里就出现问题，如果left<right&&convert(s[left])那么函数将直接被短路,s[left]=' ',s[right]='a'，此时不相等会造成假结果。
因此其是奇数回文串，对称中心在字母c上，那么convert(s[left])&&left<right，就先得到left值，然后left++后正好等于right，但是convert函数在&&前，将得到lc=c;同样对于之后对rc也会优先得到rc=c，正好相等，循环结束返回true

### 代码

```c
char convert(char c){
    if(c>=65&&c<=90||c>=48&&c<=57) return c;
    else if(c>=97&&c<=122) return c - 32;
    else return '\0';  // 其他东西
}

bool isPalindrome(char * s){
    char lc,rc;
    for(short right=strlen(s)-1,left=0;left<right;left++,right--){
        while((lc=convert(s[left]))=='\0'&&left<right) left++;
        while((rc=convert(s[right]))=='\0'&&left<right) right--;
        if(lc!=rc) return false;
    }
    return true;
}
```

