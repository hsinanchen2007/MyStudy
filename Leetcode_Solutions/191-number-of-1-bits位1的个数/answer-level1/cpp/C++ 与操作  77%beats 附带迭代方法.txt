## 解题思路
#### 与操作法
最值得注意的地方是进行按位与的mask也要是uint32_t类型的，否则编译报错
```
int hammingWeight(uint32_t n)
    { //传进来的是32位的2进制数
        //存在比递归更好的方法
        int ret = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i)
        {
            if ((n & mask) != 0)
            {
                ++ret;
            }
            mask = mask << 1;
        }
        return ret;

    }
```

#### 迭代法
```
int hammingWeight(uint32_t n){
         int count=0;
         while(n>0)
         {
             if(n%2==1) ++count;
             n=n/2;
         }
         return count;
}
```

