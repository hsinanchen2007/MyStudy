### 解题思路
题目的根本目的，还是先求出每个数字分别出现了多少次，然后次数的最大公约数就是分组的大小，
分组大小大于等于2时则为true


### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        // 题目的根本目的，还是先求出每个数字分别出现了多少次，然后次数的最大公约数就是分组的大小，分组大小大于等于2时则为true

        // 找到最大值，用于创建数组时使用
        int max = 0;
         for(int num : deck){
            if(num > max){
                max = num;
            }
        }

        // 先获取每个数字分别出现了多少次
        int[] count = new int[max + 1];
        for(int num : deck){
            count[num] ++;
        }

        int result = -1;
        // 求次数的最大公约数
        for(int i = 0; i < max + 1; i++){
            if(count[i] > 0){
                if(result == -1){
                    result = count[i];
                }else{
                    result = getGYS(result,count[i]);
                }
            }
        }
        return result >= 2 ? true : false;
    }

    //辗转相除法求最大公约数
    private int getGYS(int x, int y){
        return y == 0? x : getGYS(y,x%y);
    }


}
```