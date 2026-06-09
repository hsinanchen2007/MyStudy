### 解题思路
本题用到的是朴素的数学模拟，本质上是将所有元素出现的个数进行求最大公约数，最大公约数不为1即可恰好分成几个组。解题过程分为3个部分。
（1）统计所有出现的数的个数。整体遍历一遍，统计个数，存到普通数组`hash`中，但是此时的`hash`表是浪费空间的，很多位置是没有元素，表现出来`value=0`
（2）移动数组。为了方便后面的前后相邻位置一一比较，此处先将所有元素都移动到前面来，使之没有空位置。
（3）求最大公约数。整体便利一遍，求前后两个元素的最大公约数。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        
        int len = deck.length;
        if(len <= 1){
            return false;
        }

        //1.统计个数
        int[] hash = new int[len];
        for(int i = 0; i < len; i++){
            hash[deck[i]]++;
        }
        
        // 2.移动数组
        int j = 0;
        for(int i = 0; i < len; i++){
            if(hash[i] != 0){
                if(i != j){
                    hash[j] = hash[i];
                }
                j++;
            }
        }
        
        //3.求最大公约数
        for(int i = 0; i<j; i++){
            hash[i+1] = getCom(hash[i],hash[i+1]);
            if(hash[i+1] == 1){
                return false;
            }
        }
        
        return true;
    }
    
    private int getCom(int a, int b){
        int big = a > b ? a : b;
        int small = a > b ? b : a;
        
        if(small==0 || big % small == 0){
            return small;
        }
        return getCom(big % small, small);
    }
}
```