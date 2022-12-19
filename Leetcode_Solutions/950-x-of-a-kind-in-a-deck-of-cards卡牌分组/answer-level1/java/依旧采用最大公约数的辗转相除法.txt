### 解题思路
还是最大公约数的问题。
本来第一反应是统计各个数字出现个数，直接比较所有个数是否相等就ok了，然后直接开始写，写完发现还有示例5，血亏。用最大公约数微调了一下，结束战斗。
注意，运行过程中出现的一个小错误是找到第一个不为0的数字之后，忘记break了，在eclipse里调试了一下才发现错误，真的是淡黄的长裙蓬松的头发。。。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        if(deck.length<2){
            return false;
        }
        if(deck.length==2&deck[0]==deck[1]){
            return true;
        }
        int max = 0;
        for(int i = 0;i<deck.length;i++){//获取这个数组中最大值，为建立数组长度，省空间但是消耗时间
            max = deck[i]>max?deck[i]:max;
        }
        int []arr = new int[max+1];//建立了数组
        for(int i = 0;i<deck.length;i++){//遍历数组并统计各个数字出现频率
            arr[deck[i]]++;
        }
        int pre1 = 0;
        int index = 0;
        boolean res = true;
        for(int j = 0;j<arr.length;j++){//遍历数组找到第一个不为0的数字
            if(arr[j]!=0){
                pre1 = arr[j];
                index = j;
                break;
            }
        }//现在pre1存储的就是这个第一个多个数字的个数，从这个数的下一位开始遍历比较
        //这个pre1之后存储最大公约数中的最小值
        for(int j = index+1;j<arr.length;j++){
            if(arr[j]!=0){
                pre1 = gcd(pre1,arr[j]);
                if(pre1==1){//说明不存在最大公约数
                    return false;
                }else{
                    res = true;
                }
            }
        }
        return res;
    }
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
}
```