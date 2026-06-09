这个题目除了边界外，他不可能找不到一个与它1数目相等的值。
我们直接从num开始，往上遍历，找到有一个1的个数相同的值
然后往下遍历找到有一个1的个数相同的值
```
class Solution {
    public int oneFigure(int num){
        int fi = 0;
        while(num != 0){
            if((num & 1) == 1){
                fi++;
            }
            num >>= 1;
        }
        return fi;
    }
    public int[] findClosedNumbers(int num) {
        int fi, i;
        int[] arr = new int[2];
        arr[0] = arr[1] = -1;
        fi = oneFigure(num);
        for(i = num + 1; i <= 2147483647; i++){
            int f = oneFigure(i);
            if(fi == f){
                arr[0] = i;
                break;
            }
        }
        for(i = num - 1; i >= 1; i--){
            int f = oneFigure(i);
            if(fi == f){
                arr[1] = i;
                break;
            }
        }
        return arr;
    }
}
```
