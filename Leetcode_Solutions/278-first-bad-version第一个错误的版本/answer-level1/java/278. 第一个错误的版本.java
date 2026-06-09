/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/2
 *
 * 解题思路: 经典的二分查找 但是注意，在(start + end)/2 的过程中可能会出现溢出 可以使用long来解决，也可以使用 (start + (end - start)/2)
 */
```
int start = 0;
int end = n;
int mid = 0;
while(start <= end){
    mid = (start + (end - start)/2);
    if(isBadVersion(mid) == true){
        if(mid != 0 && isBadVersion(mid - 1) == false){
            return  mid;
        }else if(mid == 0){
            return  mid;
        }else{
            end = mid;
        }

    }else{
        start = mid + 1;
    }
}
return mid;
```