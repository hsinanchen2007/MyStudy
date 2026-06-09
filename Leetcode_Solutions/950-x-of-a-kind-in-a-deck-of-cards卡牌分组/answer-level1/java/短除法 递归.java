### 解题思路
此处撰写解题思路
首先这个题的问题是求所有数字出现次数的最大公约数，因此我们要先统计每个数字出现的次数，
随后设置好短除法求最大公约数，求最大公约数有几种方法，这里选用的是短除法，随后遍历出现次数的数组，
使用编辑好的短除法。最后设定好弹出条件。
### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int x = 0;
        int[] num = new int[10000];//创建新数组，用于存放数字出现次数
        for(int a : deck){
            num[a]++;
        }
        for(int i : num){//遍历新的数组，求所有数的最大公约数,如果某个数出现次数为0则直接跳过
            if(i>0){
                x = gcd(x,i);
                if(x==1){//如果其中有两个数的最大公约数是1，则可直接输出false
                    return false;
                }
            }
        }
        return x >= 2;
    }
    private int gcd(int a,int b){//定义求两个数最大公约数的方式，如果是三个数的最大公约数，可用前两个数的最大公约数与第三个数求最大公约数
            return b==0 ? a : gcd(b,a%b);
    }
}
```