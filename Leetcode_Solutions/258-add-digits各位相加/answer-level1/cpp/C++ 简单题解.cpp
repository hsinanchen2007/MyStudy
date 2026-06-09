![image.png](https://pic.leetcode-cn.com/20bc27971f01d80e663ce76c12fcc6b5b698857d289441df6600070cfdd53e97-image.png)
解题思路：递归大法好
```
    int addDigits(int num) {
        if(num == 0) return 0;
           int sum = 0;
        while(num != 0){
              sum += num%10;
              num /= 10;
        }
        if(sum < 10) return sum;
           else      return(addDigits(sum));
    }
```

