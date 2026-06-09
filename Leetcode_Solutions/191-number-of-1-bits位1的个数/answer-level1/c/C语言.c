### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f23113e9c70bf64fe3ddf7f19a7a0c664b96364d733c48d0a7bda792cee3dcee-image.png)

### 代码

```c
int hammingWeight(uint32_t n) {
    int ret = 0;
    while(n > 0) {
        if(n % 2) {
            ret++;
        }
        n /= 2;
    }
    return ret;    
}
```