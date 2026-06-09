/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/4
 * 
 * 解题思路: 有坑 二分法 (start + end)/2 可能会出现整数溢出 改进为 start + (end - start)/2
 * 
 */
```
public int guessNumber(int n) {
    int mid = 0;
    int start = 0;
    int end = n;
    int res = -1;

    while(res != 0){
        // (start + end) 会出现溢出
        mid = start + (end - start)/2;
        res = guess(mid);
        if(res == -1){
            end = mid - 1;
        }else if(res == 1){
            start = mid + 1;
        }
    }
    return mid;
}
```