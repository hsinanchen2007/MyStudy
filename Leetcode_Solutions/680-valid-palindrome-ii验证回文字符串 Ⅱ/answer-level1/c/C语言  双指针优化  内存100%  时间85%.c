### 解题思路
最简单的思路吧
双指针向中间夹逼
如果遇到不相同的情况，就删除一位
这个情况下采用flag的方式保证只修改一次
如果在删除修改的过程中，两个指针相遇，则直接输出ture就好了，
如果左边或者右边删除一位之后，存在相同的情况，则再比较一位确保下一位也相同

主要是为了避免这一个case：
aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga

精简之后就是
lcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucul
左边删除一位和右边删除一位都满足相等的条件，那么再比较一位，就可以确定我们需要删除哪一边的字符了

### 代码

```c
bool validPalindrome(char * s){
    int len = strlen(s);
    int i = 0, j = len - 1;
    int flag = 0; //标志只做一次修改
    while(i <= j){
        if(s[i] == s[j]){ i++;  j--; }
        else if(s[i] != s[j]){
            if(flag){ return false;  break; } //只能做一次修改
            else{ //做一次删除之后，继续对比两个指针
                flag = 1;
                if(i+1 == j)  return true;
                else if(s[i+1] == s[j] && s[i+2] == s[j-1]){ i+=3; j-=2; }
                else if(s[i] == s[j-1] && s[i+1] == s[j-2]){ i+=2; j-=3; }
                else { return false; break; }
            }
        }
    }
    return true;
}
```