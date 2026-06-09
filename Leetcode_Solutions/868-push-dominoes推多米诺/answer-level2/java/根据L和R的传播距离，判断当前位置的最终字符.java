#### [838. 推多米诺](https://leetcode-cn.com/problems/push-dominoes/)

一行中有 N 张多米诺骨牌，我们将每张多米诺骨牌垂直竖立。

在开始时，我们同时把一些多米诺骨牌向左或向右推。

每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。

同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。

如果同时有多米诺骨牌落在一张垂直竖立的多米诺骨牌的两边，由于受力平衡， 该骨牌仍然保持不变。

就这个问题而言，我们会认为正在下降的多米诺骨牌不会对其它正在下降或已经下降的多米诺骨牌施加额外的力。

给定表示初始状态的字符串 "S" 。如果第 i 张多米诺骨牌被推向左边，则 S[i] = 'L'；如果第 i 张多米诺骨牌被推向右边，则 S[i] = 'R'；如果第 i 张多米诺骨牌没有被推动，则 S[i] = '.'。

返回表示最终状态的字符串。

```java
示例 1：

输入：".L.R...LR..L.."
输出："LL.RR.LLRRLL.."

示例 2：

输入："RR.L"
输出："RR.L"
说明：第一张多米诺骨牌没有给第二张施加额外的力。

提示：0 <= N <= 10^5
表示多米诺骨牌状态的字符串只含有 'L'，'R'; 以及 '.';
```

### 思路

题目理解：一个多米诺骨牌，使用一个字符串表示，同时推到一些牌（向左或者向右），求最终的多米诺骨牌所表示的字符串。注意一点：如果某张牌左右同时受到异向的推力，那么传播在此处停止。

这道题需要考虑多米诺骨牌的传播。

```java
public String methodOne(String s){
    //分别计算向左和向右多米诺骨牌的传播距离
    int n = s.length();
    int[] left = new int[s.length()];
    int[] right = new int[s.length()];
    //计算向右的距离
    for(int i=0; i<n; i++){
        if(s.charAt(i)=='R'){
            int count = 0;
            while((++i)<n && s.charAt(i)=='.'){
                right[i] = ++count;
            }
            i--;
        }
    }

    for(int i=n-1; i>=0; i--){
        if(s.charAt(i)=='L'){
            int count = 0;
            while((--i)>=0 && s.charAt(i)=='.'){
                left[i] = ++count;
            }
            i++;
        }
    }
    StringBuilder result = new StringBuilder();
    for(int i=0; i<n; i++){
        char cur = s.charAt(i);
        if(left[i]==0 && right[i]==0) result.append(cur);
        else if(left[i]==0 && right[i] !=0) result.append('R');
        else if(left[i]!=0 && right[i] == 0) result.append('L');
        else{
            if(left[i]<right[i]) result.append('L');
            else if(left[i]==right[i]) result.append('.');
            else result.append('R');
        }
    }
    return result.toString();
}
```



