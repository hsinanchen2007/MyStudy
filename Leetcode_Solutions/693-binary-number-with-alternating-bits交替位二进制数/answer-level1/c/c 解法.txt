![image.png](https://pic.leetcode-cn.com/4a136be7c5370bf508c194be16b80ccfba8caf7e8137b982c6fca6417d691763-image.png)

# 代码：
```
bool hasAlternatingBits(int n){
    
    if(n == 0 || n == 1 || n == 2){return 1;}
    
    int binarynum = 1,numberofdigits = 1, copyn = n;
    
    while((copyn/=2) > 0){numberofdigits++;}
   
    for(int i = 1;i < numberofdigits;i++){
        binarynum<<=1;
        binarynum += (i%2 == 0);
    }
    return (binarynum == n);
}
```

